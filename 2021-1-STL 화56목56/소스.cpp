//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 4�� 1�� �����            (5�� 2��)
//
// - vector
//-----------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include "save.h"
#include "String.h"
using namespace std;

// [����] "�ҽ�.cpp"�� �о� vector�� ������ �� 
// �Ųٷ� ȭ�鿡 ����϶�.
int main()
{	
	ifstream in{ "�ҽ�.cpp" };
	
	vector<char> v;

	char c;
	while (in >> c) {
		v.push_back(c);
	}
	for (auto i = v.rbegin(); i != v.rend(); ++i) {
		cout << *i;
	}

	cout << endl << endl;
	//save("�ҽ�.cpp");
}