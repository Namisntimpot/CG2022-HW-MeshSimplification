/*����дһ��ģ��*/
/*�ܹ�������ʶ�����Ԫ�ص����ȶ��С��ü򵥵Ķ����ʵ��*/
/*��stl���ƣ����������һ��<(less)�����Ǹ��󶥶�*/
/*С���Ǵ�0��ʼ��*/
/*x������2x+1,2x+2,������(x+1)/2-1*/
#ifndef MUTABLE_PRIORITY_QUEUE_H
#define MUTABLE_PRIORITY_QUEUE_H
#include<vector>
#include<iostream>

template <typename T>
class MutablePriorityQueue
{
public:
	std::vector<T> data;
	bool(*comp)(T&, T&);    //��ԭʼ�ĺ���ָ�룬��Ϊû�㶮C++�����ǶѶ���.

	MutablePriorityQueue(bool(*)(T&, T&));
	MutablePriorityQueue(std::vector<T>, bool(*)(T&, T&));

	~MutablePriorityQueue();

	void push_back(T);
	void rebuild();  //���½�������
	void modifyKey(int, const T&);
	T pop();
	T top();
	T& operator[](int);
	size_t size();
	bool empty();

private:
	void backward_filter(int);
	void forward_filter(int);
	void swap(int, int);
};

template<typename T>
MutablePriorityQueue<T>::MutablePriorityQueue(bool(*comp)(T&, T&)) :comp(comp)
{

}

template<typename T>
MutablePriorityQueue<T>::MutablePriorityQueue(std::vector<T> data, bool(*comp)(T&, T&)) :
	data(data), comp(comp)
{
	rebuild();
}

template<typename T>
MutablePriorityQueue<T>::~MutablePriorityQueue()
{
	return;
}

template<typename T>
void MutablePriorityQueue<T>::swap(int i, int j)
{
	T tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

template<typename T>
void MutablePriorityQueue<T>::backward_filter(int index)
{
	/*����*/
	int j = index * 2 + 1, i = index;
	int size = data.size();
	while (j < size) {
		/*��compΪ1��ʱ���ʾҪ����.*/
		if (j < size - 1 && comp(data[j], data[j + 1]))
			j++;  //ѡ�����������и����ȵ��Ǹ�
		if (comp(data[i], data[j])) {
			swap(i, j);
			i = j;
			j = j * 2 + 1;
		}
		else
			break;
	}
}

template<typename T>
void MutablePriorityQueue<T>::forward_filter(int index)
{
	int i = (index + 1) / 2 - 1, j = index;
	while (i >= 0) {
		if (comp(data[i], data[j])) {
			swap(i, j);
			j = i;
			i = (i + 1) / 2 - 1;
		}
		else
			break;
	}
}

template<typename T>
void MutablePriorityQueue<T>::rebuild()
{
	int size = data.size();
	for (int i = (size + 1) / 2 - 1; i >= 0; i--) {
		backward_filter(i);
	}
}

template<typename T>
void MutablePriorityQueue<T>::modifyKey(int i, const T& val)
{
	bool greater = comp(data[i], val);
	data[i] = val;
	if (greater)
		forward_filter(i);
	else
		backward_filter(i);
}

template<typename T>
void MutablePriorityQueue<T>::push_back(T val)
{
	data.push_back(val);
	forward_filter(data.size() - 1);
}

template<typename T>
T MutablePriorityQueue<T>::top()
{
	if (data.empty()) {
		std::cout << "the priority queue is empty when using top()!";
		exit(1);
	}
	return data[0];
}

template<typename T>
T MutablePriorityQueue<T>::pop()
{
	if (data.empty()) {
		std::cout << "the priority queue is empty when using pop()!";
		exit(1);
	}
	T top = data[0];
	int size = data.size();
	data[0] = data[size - 1];
	data.pop_back();  //�������һ��
	backward_filter(0);
	return top;
}

template<typename T>
size_t MutablePriorityQueue<T>::size()
{
	return data.size();
}

template<typename T>
bool MutablePriorityQueue<T>::empty()
{
	return data.empty();
}

template<typename T>
T& MutablePriorityQueue<T>::operator[](int i)
{
	return data[i];
}

#endif