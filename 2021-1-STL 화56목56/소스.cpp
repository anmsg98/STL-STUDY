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
#include <iterator>
#include <forward_list>
#include <list>
#include <string>
#include "save.h"
#include "String.h"
using namespace std;

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