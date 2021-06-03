//-------------------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 6월 3일 목요일            (14주 2일)

// 알고리즘 함수 살펴보기
// 알고리즘 사용예제(anagram)
// range, view
//
// 기말시험 - 6월 10일 (목요일) (15주 2일)
//-------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include "save.h"
using namespace std;

int main()
{
	vector<int> v{ 1,3,5,7,9,2,4,6,8,10 };

	// v에서 홀수만 골라 값을 10배로 만든 후 출력하라.

	for (int n : v 
		| views::filter([](int n) {return n & 1;})
		| views::transform([](int n) {return n *= 10; })
		)
		cout << n << " ";
	cout << endl;

	for (int n : v)
		cout << n << " ";
	cout << endl;
	// save("소스.cpp");
	
}