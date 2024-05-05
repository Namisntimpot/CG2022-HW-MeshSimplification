/*不相交集，即并查集*/
/*集合中的东西一定是“序号”*/
#ifndef DISJOINTSET_H
#define DISJOINTSET_H

class DisjointSet
{
public:
	int size;
	int* sets;
	DisjointSet(int size);
	~DisjointSet();
	int Find(int);                //找到这个元素属于哪个集合（哪个根)
	bool checkSameSet(int, int);
	int Union(int, int);
};

DisjointSet::DisjointSet(int size) :size(size) {
	sets = new int[size];
	for (int i = 0; i < size; i++) {
		sets[i] = -1;        //初始化为-1，为负表示是一个集合的根.
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
	/*检验两个编号是否在同一个集合中*/
	int pa = Find(a), pb = Find(b);
	return pa == pb;
}

int DisjointSet::Union(int a, int b)
{
	/*原本不在同一个集合，合并返回1，原本就在同一个集合返回0*/
	/*用于点对，一个集合也就两个点，随便合并*/
	int pa = Find(a), pb = Find(b);
	if (pa == pb)
		return 0;
	sets[pa] = pb;
	return 1;
}

#endif