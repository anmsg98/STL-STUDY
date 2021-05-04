//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 5�� 4�� ȭ����            (10�� 1��)
//
// Container - ���׸� Ŭ����, String( [c][c][c]...), begin(), end()
// Iterator - String_iterator, String_reverse_iterator
// Algorithm - ���׸� �Լ�
//-----------------------------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "save.h"
#include "String.h"
using namespace std;

// [����] �ݺ��ڰ��� �Ÿ��� ����ϴ� distance�� �ۼ�
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
	
	save("�ҽ�.cpp");
}