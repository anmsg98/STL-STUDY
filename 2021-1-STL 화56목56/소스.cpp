//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 4월 20일 화요일            (8주 1일)
//
// 반복자 : 책 31~41, 123~136, Design Pattern 중 iterator pattern
// 반복자는 포인터를 추상화한 것이다.
// 반복자처럼 행동하는 것은 반복자이다.
// 반복자는 컨테이너가 제공하는 인터페이스이다.
//-----------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string_view>
#include <fstream>
#include <random>
#include <algorithm>
#include <iterator>
#include "save.h"
using namespace std;

// [문제] 파일 "int 100개.txt"에 바이너리로 저장되어있는 정수 100개가 있다.
// 읽은 정수 100개를 내림차순으로 정렬한 후 출력.

int main()
{
	int a[100];
	ifstream in{ "int 100개다.txt", ios::binary };
	in.read((char*)&a, 100 * sizeof(int));
	sort(begin(a), end(a), greater<int>());

	for (int n : a)
		cout << n << endl;
}
// [문제] 반복자를 인자로 받은 함수는 그것이 무엇인지를 어떻게 알까?

template <typename Iter>
void showIteratorCategory(const Iter&)
{
	cout << typeid(iterator_traits<Iter>::iterator_category).name() << endl;
}

int main()
{	
	String s{ "1357924680" };
	
	sort(s.begin(), s.end());
		
	//save("소스.cpp");
}