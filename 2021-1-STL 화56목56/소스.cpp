//-------------------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 5월 25일 화요일            (13주 1일)
//
// 알고리즘 함수 살펴보기
// 알고리즘 사용예제(anagram)
// range, view
//
// 기말시험 - 6월 10일 (목요일) (15주 2일)
//-------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include "save.h"
#include "String.h"
using namespace std;

// partition

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	// 홀짝으로 분리하라.
	stable_partition(v.begin(), v.end(), [](int n) {
		return n % 2 == 1;
		});

	for (int n : v)
		cout << n << " ";
	cout << endl;
	//save("소스.cpp");
}