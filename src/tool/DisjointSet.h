/*���ཻ���������鼯*/
/*�����еĶ���һ���ǡ���š�*/
#ifndef DISJOINTSET_H
#define DISJOINTSET_H

class DisjointSet
{
public:
	int size;
	int* sets;
	DisjointSet(int size);
	~DisjointSet();
	int Find(int);                //�ҵ����Ԫ�������ĸ����ϣ��ĸ���)
	bool checkSameSet(int, int);
	int Union(int, int);
};

DisjointSet::DisjointSet(int size) :size(size) {
	sets = new int[size];
	for (int i = 0; i < size; i++) {
		sets[i] = -1;        //��ʼ��Ϊ-1��Ϊ����ʾ��һ�����ϵĸ�.
	}
}

DisjointSet::~DisjointSet()
{
	delete[] sets;
}

int DisjointSet::Find(int a)
{
	int pa;
	for (pa = a; sets[pa] >= 0; pa = sets[pa]);
	return pa;
}

bool DisjointSet::checkSameSet(int a, int b)
{
	/*������������Ƿ���ͬһ��������*/
	int pa = Find(a), pb = Find(b);
	return pa == pb;
}

int DisjointSet::Union(int a, int b)
{
	/*ԭ������ͬһ�����ϣ��ϲ�����1��ԭ������ͬһ�����Ϸ���0*/
	/*���ڵ�ԣ�һ������Ҳ�������㣬���ϲ�*/
	int pa = Find(a), pb = Find(b);
	if (pa == pb)
		return 0;
	sets[pa] = pb;
	return 1;
}

#endif