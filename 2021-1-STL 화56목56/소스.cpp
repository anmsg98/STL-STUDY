//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 4�� 8�� �����            (6�� 2��)
//
// deque
//
// �߰����� - 4�� 22�� (�����)
//-----------------------------------------------------------------
#include <iostream>
#include <deque>
#include "save.h"
#include "String.h"
using namespace std;

int main()
{	
	deque<String> d;

	d.emplace(d.end(), "1");
	d.emplace(d.end(), "2");
	d.emplace(d.end(), "3");
	for (const String& s : d)
		cout << s << endl;
	
	//save("�ҽ�.cpp");
}