//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 3�� 25�� �����            (4�� 2��)
//
// Containers are objects that sotre other objects.
//
// Sequence Containers
//	- array
//	- vector
//	- deque
//	- forward_list
//	- list
//
// ���� class�� �̵���� �ڵ� - sort �Լ��� Ȯ��
//-----------------------------------------------------------------
#include <iostream>
#include "save.h"
#include "String.h"
using namespace std;

// [�ǽ�] main�� ����� �� �ְ� Array�� ���α׷� �϶�.
template <typename T, int N>
class Array {
	T data[N]{ 0 };
public:
	Array() {
	}
	size_t size() const {
		return N;
	}
	T operator[](int idx) const{
		return data[idx];
	}

	T& operator[](int idx) {
		return data[idx];
	}
	
	T* begin() {
		return data;
	}

	T* end() {
		return data + N;
	}
};

int main()
{
	Array<String, 10> a;
	
	for (int i = 0; i < a.size(); ++i)
		a[i] = i;
	
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << endl;

	cout << "======�ݺ��ڷ� ���======" << endl;
	for (auto i = a.begin(); i != a.end(); ++i)
		cout << *i << endl;
	
	save("�ҽ�.cpp");
}