#ifndef VPAIR_H
#define VPAIR_H
#include<Eigen/Dense>

class Vpair : public std::pair<int, int>
{
public:
	Eigen::Matrix4f Q;      //�����Ե�����Q.�γ����µĵ������µ������������.
	Eigen::Vector3f v;      //ֻ�����µĵ��ʵ��λ��
	float _cost;
	Vpair(int num_v1, Eigen::Vector3f& v1, int num_v2, Eigen::Vector3f& v2, Eigen::Matrix4f& Q1, Eigen::Matrix4f& Q2);
	~Vpair() { return; }
	void update(Eigen::Vector3f& v1, Eigen::Vector3f& v2, Eigen::Matrix4f& Q1, Eigen::Matrix4f& Q2);
	Eigen::Matrix4f getQ() {
		return Q;
	}
	float cost() {
		return _cost;
	}
	Eigen::Vector3f newV() {
		return v;
	}
	void setfirst(int num_v1) {
		first = num_v1;
	}
	void setsecond(int num_v2) {
		second = num_v2;
	}
};

bool VpairGreater(Vpair& a, Vpair& b)
{
	return a.cost() > b.cost();
}

Vpair::Vpair(int num_v1, Eigen::Vector3f& v1, int num_v2, Eigen::Vector3f& v2, Eigen::Matrix4f& Q1, Eigen::Matrix4f& Q2) :
	pair(num_v1, num_v2) {
	update(v1, v2, Q1, Q2);
}

void Vpair::update(Eigen::Vector3f& v1, Eigen::Vector3f& v2, Eigen::Matrix4f& Q1, Eigen::Matrix4f& Q2)
{
	/*���¶�����������¼������ŵ����ʧ����*/
	Q = Q1 + Q2;
	bool invetible = false;
	Eigen::Matrix4f Qi(Q), Qi_inv;
	Qi.row(3) << 0., 0., 0., 1.;
	Qi.computeInverseWithCheck(Qi_inv, invetible);
	Eigen::Vector4f tmp;
	if (invetible) {
		tmp = Qi_inv * Eigen::Vector4f(0., 0., 0., 1.);
		v << tmp[0], tmp[1], tmp[2];
	}
	else {
		v = (v1 + v2) / 2;
		tmp << v, 1.;
	}
	_cost = tmp.transpose() * (Q * tmp);
}

#endif