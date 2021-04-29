//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 4�� 29�� �����            (9�� 2��)
//
// Container - ���׸� Ŭ����, String( [c][c][c]...), begin(), end()
// Iterator - String_iterator, String_reverse_iterator
// Algorithm - ���׸� �Լ�
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
	
	// [����] �� main()�� �������� ����ǰ� �Ͻÿ�.
	auto p = find(v.begin(), v.end(), String{ "abc" });
	cout << *p << endl;
	//save("�ҽ�.cpp");
}