//-------------------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 6�� 3�� �����            (14�� 2��)

// �˰��� �Լ� ���캸��
// �˰��� ��뿹��(anagram)
// range, view
//
// �⸻���� - 6�� 10�� (�����) (15�� 2��)
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

	// v���� Ȧ���� ��� ���� 10��� ���� �� ����϶�.

	for (int n : v 
		| views::filter([](int n) {return n & 1;})
		| views::transform([](int n) {return n *= 10; })
		)
		cout << n << " ";
	cout << endl;

	for (int n : v)
		cout << n << " ";
	cout << endl;
	// save("�ҽ�.cpp");
	
}