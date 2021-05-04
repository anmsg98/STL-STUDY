//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 5월 4일 화요일            (10주 1일)
//
// Container - 제네릭 클래스, String( [c][c][c]...), begin(), end()
// Iterator - String_iterator, String_reverse_iterator
// Algorithm - 제네릭 함수
//-----------------------------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "save.h"
#include "String.h"
using namespace std;

// [문제] 반복자간의 거리를 계산하는 distance를 작성
template<typename Iter>
ptrdiff_t my_distance(Iter beg, Iter end)
{
	if (random_access_iterator_tag<Iter>)
		return end - beg;
	
	int cnt{};
	while (beg != end) {
		++cnt;
		++beg;
	}
	return cnt;
}
int main()
{
	vector<int> v{ 1,2,3,4,5 };
	cout << my_distance(v.begin(), v.end()) << endl;
	list<int> cont{ 1,2,3,4,5 };
	cout << my_distance(cont.begin(), cont.end()) << endl;
	
	save("소스.cpp");
}