//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 3월 25일 목요일            (4주 2일)
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
// 관찰 class에 이동기능 코딩 - sort 함수로 확인
//-----------------------------------------------------------------
#include <iostream>
#include "save.h"
#include "String.h"
using namespace std;

// [실습] main이 실행될 수 있게 Array을 프로그램 하라.
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

	cout << "======반복자로 출력======" << endl;
	for (auto i = a.begin(); i != a.end(); ++i)
		cout << *i << endl;
	
	save("소스.cpp");
}