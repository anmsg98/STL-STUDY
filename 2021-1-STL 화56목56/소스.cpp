//-------------------------------------------------------------
// X86 mode & Release mode ���� ���α׷�
//
// 2021. 1�б� STL ȭ56 ��56  - 3�� 4�� �����		(1�� 2����)
//
// 1�� 1�� ���� �ҽ��� e-class�� ����
//
// �̹� �ð� ���� - C++ ��� ����
// ���� ���� ������ �ٷ�� - int ���� ����
//-------------------------------------------------------------

#include <iostream>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;
 
// [����] int 20���� ������ ������ �����Ѵ�
// int�� ������ ��(���������� ����)���� �����.
// ���� ���� or ������������ ���� �غ���.
// ȭ�鿡 int ���� �������.

default_random_engine dre; // ���� ����

int main()
{
	uniform_int_distribution uid{ 1,1000 }; // ���� ���� ����

	int arr[20];
	for (int& n : arr)
		n = uid(dre);

	for (int n : arr)
		cout << n << " ";
	cout << endl << "����" << endl;
	// �����Ѵ�
	sort(begin(arr), end(arr), [](int a, int b) {return a < b; }); // 3��° ���ڷ� ���Ĺ���� ������ �� ����.
	for (int n : arr)
		cout << n << " ";
	cout << endl;
	//save("�ҽ�.cpp");
	return 0;
}
