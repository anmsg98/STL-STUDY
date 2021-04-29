//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 4월 29일 목요일            (9주 2일)
//
// Container - 제네릭 클래스, String( [c][c][c]...), begin(), end()
// Iterator - String_iterator, String_reverse_iterator
// Algorithm - 제네릭 함수
//-----------------------------------------------------------------
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "save.h"
#include "String.h"
using namespace std;

template<typename Iter, typename Value>
Iter my_find(Iter begin, Iter end, Value c) {
	for (; begin != end; ++begin)
		if (*begin == c)
			return begin;

	return end;
}

int main()
{
	vector<String> v{ "123", "4567", "abc" };
	
	// [문제] 이 main()이 문제없이 실행되게 하시오.
	auto p = find(v.begin(), v.end(), String{ "abc" });
	cout << *p << endl;
	//save("소스.cpp");
}