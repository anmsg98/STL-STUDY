//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 3월 30일 화요일            (5주 1일)
//
// - vector
//-----------------------------------------------------------------
#include <iostream>
#include <vector>
#include "save.h"
#include "String.h"
using namespace std;

// [문제] vector란 무엇입니까 - 동적(컴파일시에는 크기를 알 수 없는) 배열입니다.

int main()
{	
	vector<int> v{ 1,2,3 };

	cout << "원소의 개수는 - " << v.size() << endl;
	v.push_back(10);
	cout << "원소의 개수는 - " << v.size() << endl;
	
	//save("소스.cpp");
}