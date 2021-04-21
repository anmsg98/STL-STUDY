//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 4�� 13�� ȭ����            (7�� 1��)
//
// 1. sequence �����̳�
//	���Ҹ� ����/�߰� �ϴ� ������ 0(1)
//	- list
//	- forward_list
//-----------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string_view>
#include <fstream>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;

// [����] ���� "int 100��.txt"�� ���̳ʸ��� ����Ǿ��ִ� ���� 100���� �ִ�.
// ���� ���� 100���� ������������ ������ �� ���.

int main()
{
	int a[100];
	ifstream in{ "int 100����.txt", ios::binary };
	in.read((char*)&a, 100 * sizeof(int));
	sort(begin(a), end(a), greater<int>());

	for (int n : a)
		cout << n << endl;
}
