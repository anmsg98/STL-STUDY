//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 4�� 13�� ȭ����            (7�� 1��)
//
// 1. sequence �����̳�
//	���Ҹ� ����/�߰� �ϴ� ������ 0(1)
//	- list
//	- forward_list
//-----------------------------------------------------------------

#include <iostream>
#include <list>
#include "save.h"
#include "String.h"
using namespace std;


int main()
{	
	list<String> c{ 1,3,5,7,9,2,4,6,8,10 };
	c.sort([](const String& a, const String& b) {
		return a.size() < b.size();
		});
	//c.reverse();	// ����Ʈ�� ������ �ݴ�� �ٲ���
	// ��ü�� ��ȸ�ϸ� �������
	for (const String& s : c)
		cout << s << endl;

	//save("�ҽ�.cpp");
}