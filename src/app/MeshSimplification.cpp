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
	norm.normalize();    //��׼���ķ�������.���normalizeû�з���ֵ.
	float d = -norm.dot(v1);
	//float d = 0.;
	return Eigen::Vector4f(norm[0], norm[1], norm[2], d);
	//return Eigen::Vector4f(norm, d);     //�����ᱨ���Ҳ���...<Matrix<float,4,1,0,4,1>>:_init2�����أ�
}

namespace meshSimplification
{
	//������Ϊ���ƣ���˿���ֱ�������洦������ֵ���Ƕ���+��Ƭ����Ƭ�������������ű�ʾ��
	std::pair<std::vector<Eigen::Vector3f>, std::vector<Eigen::Vector3i>> simplifyMesh(
		// ÿ��Ԫ��Ϊһ����ά��������ʾÿ���ڵ��λ��
		std::vector<Eigen::Vector3f> vertices, 
		// ÿ��Ԫ�����������ͱ���(Vector3i)����ʾһ��������
		std::vector<Eigen::Vector3i> faces,
		// ģ�ͼ򻯱���
		float ratio)
	{
		//��ǽڵ��Ƿ�ɾ����ʵ������bool�������Ƽ�std::vector<bool>
		std::vector<char> deleted(vertices.size());;
		
		//ÿ���ڵ㱣������������ı�ţ����㷴���ѯ
		std::vector<std::vector<int>> faces_of_vertex(vertices.size());  //������������������Ƭ�����
		for (int i = 0; i < faces.size(); i++)       //�γ�ÿ������������Ԫ������
		{
			for (int j = 0; j < 3; j++)
			{
				faces_of_vertex[faces[i][j]].push_back(i);
			}
		}
		for (int i = 0; i < vertices.size(); i++)    //����������û�б��ĸ����������Ҫ��ɾ��.Ӧ�ñ���������������
		{
			if (faces_of_vertex[i].size() == 0)
				deleted[i] = true;
		}
		//TODO:
		// ��ɺ������룬������
		// 1. ����Q����
		// 2. ����ڵ�����ģ�������(std::priority_queue)
		// 3. �����ڵ㣬ֱ���ﵽratioҪ��
		// ע�������ڵ�����faces_of_vertex��deleted
		int original_size = vertices.size();      //ԭ���Ķ�������
		int aim_size = static_cast<int>(1.0*original_size*ratio);    //Ŀ�궥������.(����ֵ����
		
		std::cout << "Last time vertices amount is: " << original_size << std::endl;
		/*�����ʼQ����*/
		int i, j;
		std::vector<Eigen::Matrix4f> Q_vertices(vertices.size());      //�洢ÿ���������ʧ����
		for (i = 0; i < Q_vertices.size(); i++) {
			Q_vertices[i] = Eigen::Matrix4f::Zero();    //��ʼ��Ϊ0.
		}
		for (i = 0; i < faces.size(); i++) {
			/*��������Ԫ�������������ƽ����ʽ.*/
			Eigen::Vector4f plane = computePlaneVec(vertices[faces[i][0]], vertices[faces[i][1]], vertices[faces[i][2]]);
			Eigen::Matrix4f Kp = plane * plane.transpose();
			for (j = 0; j < 3; j++) {
				Q_vertices[faces[i][j]] += Kp;
			}
		}
		/*�γɵ�ԣ�������ʧ�����������ȶ���*/
		MutablePriorityQueue<Vpair> MPQ(VpairGreater);

		/* ���ཻ�������γ����е��... */
		/* ��C++ set ά�����ظ��ĵ�Լ���.. */
		std::set<std::pair<int, int>> EdgeSet;
		for (i = 0; i < faces.size(); i++) {
			int v1 = faces[i][0], v2 = faces[i][1], v3 = faces[i][2];
			//v1, v2, v3��С��������, ð��..
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
			// ��..
			std::pair<int, int> E[] = {std::pair<int,int>(v1,v2),std::pair<int,int>(v1,v3),std::pair<int,int>(v2,v3)};
			for (j = 0; j < 3; j++) {
				if ((EdgeSet.insert(E[j])).second) {  //û���ظ�. set.insert return pair<iterator, bool>
					Vpair verpair(E[j].first, vertices[E[j].first], E[j].second, vertices[E[j].second], Q_vertices[E[j].first], Q_vertices[E[j].second]);
					MPQ.push_back(std::move(verpair));    //�ӳ�verpair����.
				}
			}
		}
		//����ò��ཻ�����γɵı߼�ֻ��һ���������ͨ��ͼ�����������������ڱߡ�
		//DisjointSet Dset(vertices.size());
		//for (i = 0; i < faces.size(); i++) {
		//	int v1 = faces[i][0], v2 = faces[i][1], v3=faces[i][2];
		//	if (Dset.Union(v1, v2)) {
		//		/*Union����1��ʾԭ������ͬһ�����ϣ��ɹ��ϲ�*/
		//		Vpair verpair(v1, vertices[v1], v2, vertices[v2], Q_vertices[v1], Q_vertices[v2]);
		//		MPQ.push_back(std::move(verpair));    //�ӳ�verpair����.
		//	}
		//	if (Dset.Union(v1, v3)) {
		//		/*Union����1��ʾԭ������ͬһ�����ϣ��ɹ��ϲ�*/
		//		Vpair verpair(v1, vertices[v1], v3, vertices[v3], Q_vertices[v1], Q_vertices[v3]);
		//		MPQ.push_back(std::move(verpair));    //�ӳ�verpair����.
		//	}
		//	if (Dset.Union(v3, v2)) {
		//		/*Union����1��ʾԭ������ͬһ�����ϣ��ɹ��ϲ�*/
		//		Vpair verpair(v3, vertices[v3], v2, vertices[v2], Q_vertices[v3], Q_vertices[v2]);
		//		MPQ.push_back(std::move(verpair));    //�ӳ�verpair����.
		//	}
		//}
		//��������������ڱ�,���������߶��У����������ԣ�<437,439><437,438>,<438,439>�������������ظ���<437,437>Ҫ����
		if (MPQ.size() == 0) {
			std::cout << "Not enough vertices!" << std::endl;
			return { std::move(vertices), std::move(faces) };
		}
		/*ѭ���ϲ����*/
		int current_size = original_size;
		while (current_size > aim_size) {
			Vpair top = MPQ.pop();
			int v1 = top.first, v2 = top.second;
			if ((v1 == v2)||deleted[v1]||deleted[v2]) continue;     //����(�����ڱ�)
			Eigen::Vector3f nv = top.newV();       //���ǽ���������ϲ�����¶��㣬��������v1�ı�ŷ�ֹ��������䳤.
			Eigen::Matrix4f nQ = top.getQ();
			vertices[v1] = nv;              //����v1������Ϊ�µ�nv;
			Q_vertices[v1] = nQ;    //��v1����ʧ�������Ϊ�µ���ʧ����.
			//������������ڱߣ����죺<437,439>,<437,438>,<438,439>��ɾȥǰ���������<437,437>���ظ��ģ��������ڱ���faces_of_vertex[v2]ʱ�������Խ��Խ����
			//�����ڱߵ�����£���������������һ�������ڹ������γ�<439,438>����ʱɾȥ��һ������<437,438>��ɾȥ�ڶ����󣬸��µ�Է���
			//<437,438>����437����ֻ�����437���£������ţ����������л���<437,438>�������ѱ�ɾ���ĵ㣡�����жϣ�����Ҫ���ų����ԣ�
			//����ò��ཻ��ȡ��ԣ�ͬһ�����������ֻѡ�������ߣ����ÿ����������..
			/*�ϲ�v1, v2����ƽ�漯�ϵ�v1, ����v2����ƽ���v2�޸ı�ŷ���v1����*/
			for (i = 0; i < faces_of_vertex[v2].size(); i++) {    //faces_of_vertex[i]�Ǳ��i����������Ԫ�ı������
				for (j = 0; j < 3; j++) {
					if (faces[faces_of_vertex[v2][i]][j] == v2)
						faces[faces_of_vertex[v2][i]][j] = v1;
					else if (faces[faces_of_vertex[v2][i]][j] == v1){  //�����Ԫͬʱ�����ϲ���v1v2������
						faces[faces_of_vertex[v2][i]] = Eigen::Vector3i(-1, -1, -1);
						//����ֱ���޸���faces��ֱ�Ӷ����˱��壬������������. ��������һ������v2ûv1�ģ�����faces_of_vertex[v1]����
						break;
					}
				}
				faces_of_vertex[v1].push_back(faces_of_vertex[v2][i]);
			}
			/*�������ȶ����еĵ�ԣ���v1,v2����Ϊnv�������¼���ϲ������ʧ����*/
			/*������������ڱ�(EdgeSet)�������пɴ���v1==v2�ģ���Щ���Ӧ�ñ����ɲ����ڣ������ñ����£�*/
			for (i = 0; i < MPQ.size(); i++) {
				if (MPQ[i].first == MPQ[i].second || deleted[MPQ[i].first] || deleted[MPQ[i].second])
					continue;
				if (MPQ[i].first == v1) {         //��һ������v1�����øı��
					MPQ[i].update(vertices[v1], vertices[MPQ[i].second], Q_vertices[v1], Q_vertices[MPQ[i].second]);
				}
				else if (MPQ[i].first == v2) {
					MPQ[i].setfirst(v1);         //v2������µ㣬���µ���v1
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
			MPQ.rebuild();     //�ؽ�����.
			deleted[v2] = true;//ɾ��v2��.
			current_size--;    //�ܵ���-1
		}
		

		//ȥ����ɾ������ͽڵ㣺����faces_of_vertex��ɾ�����棬���Ա���-1�Է�ֹ���������
		int vertex_count = 0, face_count = 0;
		for (int i = 0; i < vertices.size(); i++)
		{
			/*if (deleted[i])
			{
				for (int face_id : faces_of_vertex[i])   //�������а�������������Ƭ,��ɾ����Ƭ
					if(face_id != -1)
						faces[face_id] = Eigen::Vector3i{ -1,-1,-1 };
			}*/
			//else
			if(!deleted[i])
			{
				vertices[vertex_count] = vertices[i];    //���¶������У���û��ɾ���Ķ���ŵ�ǰ�棬���������а�������������Ԫ�������������
				for (int face_id : faces_of_vertex[i])
					if (face_id != -1)
						for (int j = 0; j < 3; j++)
							if (faces[face_id][j] == i)  //������������Ѿ���i���vertex_count�ˣ�Ҫ����������Ԫ������������ţ�
								faces[face_id][j] = vertex_count;
				vertex_count++;
			}
		}
		for (int i = 0; i < faces.size(); i++)  //������Ƭ�����
		{
			bool is_face_valid = true;
			for (int j = 0; j < 3; j++)
			{
				if (faces[i][j] == -1)    //��һ�����㱻ɾ���ˣ������Ƭ�ͱ�ɾ���ˣ�ʵ����ɾ���ʱ����������Ƭ��(-1,-1,-1)
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
						//��������ﱨ�����˵����֮ǰ����ֵ�������⣬��faces_of_vertexδ���������¡���faces����ʹ���˲���Ҫ��ֵ�ȡ�
						throw "Error! Vertex Index exceeds!";
					}
				}
			}
		}
		vertices.resize(vertex_count);
		faces.resize(face_count);
		//�����µ�ģ��
		return { std::move(vertices), std::move(faces) };
	}
}