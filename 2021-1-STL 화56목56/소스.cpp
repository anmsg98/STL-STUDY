//-------------------------------------------------------------
// X86 mode & Release mode 에서 프로그램
//
// 2021. 1학기 STL 화56 목56  - 3월 4일 목요일		(1주 2차시)
//
// 1주 1일 강의 소스는 e-class에 수록
//
// 이번 시간 내용 - C++ 언어 복습
// 많은 수의 데이터 다루기 - int 에서 시작
//-------------------------------------------------------------

#include <iostream>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;
 
// [문제] int 20개를 저장할 공간을 마련한다
// int를 임의의 값(랜덤엔진과 분포)으로 만든다.
// 값을 오름 or 내림차순으로 정렬 해보자.
// 화면에 int 값을 출력하자.

default_random_engine dre; // 랜덤 엔진

int main()
{
	uniform_int_distribution uid{ 1,1000 }; // 범위 지정 가능

	int arr[20];
	for (int& n : arr)
		n = uid(dre);

	for (int n : arr)
		cout << n << " ";
	cout << endl << "정렬" << endl;
	// 정렬한다
	sort(begin(arr), end(arr), [](int a, int b) {return a < b; }); // 3번째 인자로 정렬방법을 결정할 수 있음.
	for (int n : arr)
		cout << n << " ";
	cout << endl;
	//save("소스.cpp");
	return 0;
}
