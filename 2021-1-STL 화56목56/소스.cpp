//-------------------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 5�� 25�� ȭ����            (13�� 1��)
//
// �˰��� �Լ� ���캸��
// �˰��� ��뿹��(anagram)
// range, view
//
// �⸻���� - 6�� 10�� (�����) (15�� 2��)
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

	// Ȧ¦���� �и��϶�.
	stable_partition(v.begin(), v.end(), [](int n) {
		return n % 2 == 1;
		});

	for (int n : v)
		cout << n << " ";
	cout << endl;
	//save("�ҽ�.cpp");
}