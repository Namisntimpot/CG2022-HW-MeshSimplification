#include "MeshSimplification.h"
#include "../tool/MutablePriorityQueue.h"
#include "../tool/DisjointSet.h"
#include "Vpair.h"

#include<iostream>
#include <utility>
#include <queue>
#include <set>


Eigen::Vector4f computePlaneVec(const Eigen::Vector3f& v1, const Eigen::Vector3f& v2, const Eigen::Vector3f& v3)
{
	Eigen::Vector3f norm = ((v2 - v1).cross(v3 - v1));
	//Eigen::Vector3f norm(0., 1., 0.);
	norm.normalize();    //标准化的方向向量.这个normalize没有返回值.
	float d = -norm.dot(v1);
	//float d = 0.;
	return Eigen::Vector4f(norm[0], norm[1], norm[2], d);
	//return Eigen::Vector4f(norm, d);     //这样会报错找不到...<Matrix<float,4,1,0,4,1>>:_init2的重载？
}

namespace meshSimplification
{
	//参数均为复制，因此可以直接在上面处理，返回值就是顶点+面片（面片用三个顶点的序号表示）
	std::pair<std::vector<Eigen::Vector3f>, std::vector<Eigen::Vector3i>> simplifyMesh(
		// 每个元素为一个三维向量，表示每个节点的位置
		std::vector<Eigen::Vector3f> vertices, 
		// 每个元素是三个整型变量(Vector3i)，表示一个三角形
		std::vector<Eigen::Vector3i> faces,
		// 模型简化比例
		float ratio)
	{
		//标记节点是否被删除，实际上是bool，但不推荐std::vector<bool>
		std::vector<char> deleted(vertices.size());;
		
		//每个节点保存它所含的面的编号，方便反向查询
		std::vector<std::vector<int>> faces_of_vertex(vertices.size());  //包含这个顶点的所有面片的序号
		for (int i = 0; i < faces.size(); i++)       //形成每个顶点所属面元的数组
		{
			for (int j = 0; j < 3; j++)
			{
				faces_of_vertex[faces[i][j]].push_back(i);
			}
		}
		for (int i = 0; i < vertices.size(); i++)    //如果这个顶点没有被哪个面包含，它要被删除.应该避免出现这样的情况
		{
			if (faces_of_vertex[i].size() == 0)
				deleted[i] = true;
		}
		//TODO:
		// 完成后续代码，包括：
		// 1. 计算Q矩阵
		// 2. 计算节点间消耗，并储存(std::priority_queue)
		// 3. 收缩节点，直到达到ratio要求
		// 注意收缩节点后更新faces_of_vertex和deleted
		int original_size = vertices.size();      //原本的顶点数量
		int aim_size = static_cast<int>(1.0*original_size*ratio);    //目标顶点数量.(极端值？）
		
		std::cout << "Last time vertices amount is: " << original_size << std::endl;
		/*计算初始Q矩阵*/
		int i, j;
		std::vector<Eigen::Matrix4f> Q_vertices(vertices.size());      //存储每个顶点的损失矩阵
		for (i = 0; i < Q_vertices.size(); i++) {
			Q_vertices[i] = Eigen::Matrix4f::Zero();    //初始化为0.
		}
		for (i = 0; i < faces.size(); i++) {
			/*用三角面元的三个顶点计算平面表达式.*/
			Eigen::Vector4f plane = computePlaneVec(vertices[faces[i][0]], vertices[faces[i][1]], vertices[faces[i][2]]);
			Eigen::Matrix4f Kp = plane * plane.transpose();
			for (j = 0; j < 3; j++) {
				Q_vertices[faces[i][j]] += Kp;
			}
		}
		/*形成点对，计算损失，并加入优先队列*/
		MutablePriorityQueue<Vpair> MPQ(VpairGreater);

		/* 不相交集不能形成所有点对... */
		/* 用C++ set 维护不重复的点对集合.. */
		std::set<std::pair<int, int>> EdgeSet;
		for (i = 0; i < faces.size(); i++) {
			int v1 = faces[i][0], v2 = faces[i][1], v3 = faces[i][2];
			//v1, v2, v3从小到大排序, 冒泡..
			if (v1 > v2) {
				int tmp = v1;
				v1 = v2;
				v2 = tmp;
			}
			if (v2 > v3) {
				int tmp = v2;
				v2 = v3;
				v3 = tmp;
			}
			if (v1 > v2) {
				int tmp = v1;
				v1 = v2;
				v2 = tmp;
			}
			// 边..
			std::pair<int, int> E[] = {std::pair<int,int>(v1,v2),std::pair<int,int>(v1,v3),std::pair<int,int>(v2,v3)};
			for (j = 0; j < 3; j++) {
				if ((EdgeSet.insert(E[j])).second) {  //没有重复. set.insert return pair<iterator, bool>
					Vpair verpair(E[j].first, vertices[E[j].first], E[j].second, vertices[E[j].second], Q_vertices[E[j].first], Q_vertices[E[j].second]);
					MPQ.push_back(std::move(verpair));    //延长verpair寿命.
				}
			}
		}
		//如果用不相交集，形成的边集只有一个“最大连通子图”，不包含所有相邻边。
		//DisjointSet Dset(vertices.size());
		//for (i = 0; i < faces.size(); i++) {
		//	int v1 = faces[i][0], v2 = faces[i][1], v3=faces[i][2];
		//	if (Dset.Union(v1, v2)) {
		//		/*Union返回1表示原本不在同一个集合，成功合并*/
		//		Vpair verpair(v1, vertices[v1], v2, vertices[v2], Q_vertices[v1], Q_vertices[v2]);
		//		MPQ.push_back(std::move(verpair));    //延长verpair寿命.
		//	}
		//	if (Dset.Union(v1, v3)) {
		//		/*Union返回1表示原本不在同一个集合，成功合并*/
		//		Vpair verpair(v1, vertices[v1], v3, vertices[v3], Q_vertices[v1], Q_vertices[v3]);
		//		MPQ.push_back(std::move(verpair));    //延长verpair寿命.
		//	}
		//	if (Dset.Union(v3, v2)) {
		//		/*Union返回1表示原本不在同一个集合，成功合并*/
		//		Vpair verpair(v3, vertices[v3], v2, vertices[v2], Q_vertices[v3], Q_vertices[v2]);
		//		MPQ.push_back(std::move(verpair));    //延长verpair寿命.
		//	}
		//}
		//如果包含所有相邻边,三角形三边都有，考察下面点对：<437,439><437,438>,<438,439>，第三个会变成重复的<437,437>要舍弃
		if (MPQ.size() == 0) {
			std::cout << "Not enough vertices!" << std::endl;
			return { std::move(vertices), std::move(faces) };
		}
		/*循环合并点对*/
		int current_size = original_size;
		while (current_size > aim_size) {
			Vpair top = MPQ.pop();
			int v1 = top.first, v2 = top.second;
			if ((v1 == v2)||deleted[v1]||deleted[v2]) continue;     //舍弃(所有邻边)
			Eigen::Vector3f nv = top.newV();       //这是将两个顶点合并后的新顶点，它将沿用v1的编号防止顶点数组变长.
			Eigen::Matrix4f nQ = top.getQ();
			vertices[v1] = nv;              //更新v1的坐标为新的nv;
			Q_vertices[v1] = nQ;    //把v1的损失矩阵更新为新的损失矩阵.
			//如果包含所有邻边，考察：<437,439>,<437,438>,<438,439>，删去前两个后出现<437,437>有重复的！！这样在遍历faces_of_vertex[v2]时它本身会越来越长！
			//所有邻边的情况下，上述三个点对最后一个可能在过程中形成<439,438>。这时删去第一个后变成<437,438>，删去第二个后，更新点对发现
			//<437,438>中有437，就只把这个437更新（不变编号），最后队列中还有<437,438>，仍有已被删除的点！必须判断，这种要被排除忽略！
			//如果用不相交集取点对，同一个三角形最多只选入两条边，不用考虑这种情况..
			/*合并v1, v2所属平面集合到v1, 即把v2所属平面的v2修改编号放入v1的中*/
			for (i = 0; i < faces_of_vertex[v2].size(); i++) {    //faces_of_vertex[i]是编号i顶点所属面元的编号数组
				for (j = 0; j < 3; j++) {
					if (faces[faces_of_vertex[v2][i]][j] == v2)
						faces[faces_of_vertex[v2][i]][j] = v1;
					else if (faces[faces_of_vertex[v2][i]][j] == v1){  //这个面元同时包含合并的v1v2，舍弃
						faces[faces_of_vertex[v2][i]] = Eigen::Vector3i(-1, -1, -1);
						//这样直接修改了faces，直接丢弃了本体，不用其它操作. 留下来的一定是有v2没v1的，不在faces_of_vertex[v1]出现
						break;
					}
				}
				faces_of_vertex[v1].push_back(faces_of_vertex[v2][i]);
			}
			/*更新优先队列中的点对，把v1,v2更新为nv，并重新计算合并点和损失矩阵*/
			/*如果用了所有邻边(EdgeSet)，队列中可存在v1==v2的，这些点对应该被当成不存在，更不该被更新！*/
			for (i = 0; i < MPQ.size(); i++) {
				if (MPQ[i].first == MPQ[i].second || deleted[MPQ[i].first] || deleted[MPQ[i].second])
					continue;
				if (MPQ[i].first == v1) {         //第一个点是v1，不用改编号
					MPQ[i].update(vertices[v1], vertices[MPQ[i].second], Q_vertices[v1], Q_vertices[MPQ[i].second]);
				}
				else if (MPQ[i].first == v2) {
					MPQ[i].setfirst(v1);         //v2变成了新点，而新点编号v1
					MPQ[i].update(vertices[v1], vertices[MPQ[i].second], Q_vertices[v1], Q_vertices[MPQ[i].second]);
				}
				else if (MPQ[i].second == v1) {
					MPQ[i].update(vertices[MPQ[i].first], vertices[v1], Q_vertices[MPQ[i].first], Q_vertices[v1]);
				}
				else if (MPQ[i].second == v2) {
					MPQ[i].setsecond(v1);
					MPQ[i].update(vertices[MPQ[i].first], vertices[v1], Q_vertices[MPQ[i].first], Q_vertices[v1]);
				}
			}
			MPQ.rebuild();     //重建堆序.
			deleted[v2] = true;//删除v2点.
			current_size--;    //总点数-1
		}
		

		//去除已删除的面和节点：对于faces_of_vertex中删除的面，可以标作-1以防止访问溢出。
		int vertex_count = 0, face_count = 0;
		for (int i = 0; i < vertices.size(); i++)
		{
			/*if (deleted[i])
			{
				for (int face_id : faces_of_vertex[i])   //遍历所有包含这个顶点的面片,并删除面片
					if(face_id != -1)
						faces[face_id] = Eigen::Vector3i{ -1,-1,-1 };
			}*/
			//else
			if(!deleted[i])
			{
				vertices[vertex_count] = vertices[i];    //更新顶点序列，把没有删除的顶点放到前面，并更新所有包含这个顶点的面元中这个顶点的序号
				for (int face_id : faces_of_vertex[i])
					if (face_id != -1)
						for (int j = 0; j < 3; j++)
							if (faces[face_id][j] == i)  //这个顶点的序号已经从i变成vertex_count了，要更新所有面元中这个顶点的序号！
								faces[face_id][j] = vertex_count;
				vertex_count++;
			}
		}
		for (int i = 0; i < faces.size(); i++)  //更新面片的序号
		{
			bool is_face_valid = true;
			for (int j = 0; j < 3; j++)
			{
				if (faces[i][j] == -1)    //有一个顶点被删除了，这个面片就被删除了（实际上删点的时候会把整个面片变(-1,-1,-1)
				{
					is_face_valid = false;
					break;
				}
			}
			if (is_face_valid)
			{
				faces[face_count] = faces[i];
				face_count++;
				for (int j = 0; j < 3; j++)
				{
					if (faces[i][j] >= vertex_count)
					{
						//如果在这里报告错误，说明你之前的数值出现问题，如faces_of_vertex未能正常更新、或faces数组使用了不想要的值等。
						throw "Error! Vertex Index exceeds!";
					}
				}
			}
		}
		vertices.resize(vertex_count);
		faces.resize(face_count);
		//返回新的模型
		return { std::move(vertices), std::move(faces) };
	}
}