//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 3�� 30�� ȭ����            (5�� 1��)
//
// - vector
//-----------------------------------------------------------------
#include <iostream>
#include <vector>
#include "save.h"
#include "String.h"
using namespace std;

// [����] vector�� �����Դϱ� - ����(�����Ͻÿ��� ũ�⸦ �� �� ����) �迭�Դϴ�.

int main()
{	
	vector<int> v{ 1,2,3 };

	cout << "������ ������ - " << v.size() << endl;
	v.push_back(10);
	cout << "������ ������ - " << v.size() << endl;
	
	//save("�ҽ�.cpp");
}