//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 3�� 30�� ȭ����            (5�� 1��)
//
// String.h�� �ٿ�޾� ����� ������ �� ����.
//-----------------------------------------------------------------
#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"
#include "String.h"
using namespace std;

// [����] STL ǥ�� �����̳ʿ� String�� ����(element)�� �־��.
// ���� ����(lexicographical) �� ������������ �����غ���
int main()
{	
	array<String, 3> words{ "������", "������", "�غ��ϰھ��" };
	
	sort(words.begin(), words.end(), [](const String& a, const String& b) {
		return a.getData() < b.getData(); });

	//save("�ҽ�.cpp");
}