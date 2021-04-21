//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 4�� 20�� ȭ����            (8�� 1��)
//
// �ݺ��� : å 31~41, 123~136, Design Pattern �� iterator pattern
// �ݺ��ڴ� �����͸� �߻�ȭ�� ���̴�.
// �ݺ���ó�� �ൿ�ϴ� ���� �ݺ����̴�.
// �ݺ��ڴ� �����̳ʰ� �����ϴ� �������̽��̴�.
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
// [����] �ݺ��ڸ� ���ڷ� ���� �Լ��� �װ��� ���������� ��� �˱�?

template <typename Iter>
void showIteratorCategory(const Iter&)
{
	cout << typeid(iterator_traits<Iter>::iterator_category).name() << endl;
}

int main()
{	
	String s{ "1357924680" };
	
	sort(s.begin(), s.end());
		
	//save("�ҽ�.cpp");
}