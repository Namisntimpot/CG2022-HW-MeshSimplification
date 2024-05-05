/*尝试写一个模板*/
/*能够随机访问队列中元素的优先队列。用简单的二叉堆实现*/
/*和stl相似，如果给进来一个<(less)，会是个大顶堆*/
/*小心是从0开始！*/
/*x儿子是2x+1,2x+2,父亲是(x+1)/2-1*/
#ifndef MUTABLE_PRIORITY_QUEUE_H
#define MUTABLE_PRIORITY_QUEUE_H
#include<vector>
#include<iostream>

template <typename T>
class MutablePriorityQueue
{
public:
	std::vector<T> data;
	bool(*comp)(T&, T&);    //用原始的函数指针，因为没搞懂C++函数那堆东西.

	MutablePriorityQueue(bool(*)(T&, T&));
	MutablePriorityQueue(std::vector<T>, bool(*)(T&, T&));

	~MutablePriorityQueue();

	void push_back(T);
	void rebuild();  //重新建立堆序！
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
	/*下滤*/
	int j = index * 2 + 1, i = index;
	int size = data.size();
	while (j < size) {
		/*当comp为1的时候表示要交换.*/
		if (j < size - 1 && comp(data[j], data[j + 1]))
			j++;  //选择两个儿子中更优先的那个
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
	data.pop_back();  //丢掉最后一个
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