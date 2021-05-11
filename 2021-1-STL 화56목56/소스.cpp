//-------------------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 5�� 11�� ȭ����            (11�� 1��)
//
// Sequence ~
// Associative Container - set(281��) / map	key/value
// Unordered Associative ~
//
// map - pair<key, value>
//		�����迭�� ����Ѵ�. (���ó���� ����)
//-------------------------------------------------------------------------
#include <iostream>
#include <map>		// key/value pair�̰� key�� const
#include <string>
#include <vector>
#include "save.h"
#include "String.h"
using namespace std;

// �׷��̸��� �Է��ϸ� ����� �˷��ִ� ���� �����.

int main()
{
	map<string, vector<string>> group;
	group.insert(pair<string, vector<string>>{"Itzy", { "����","����" }});
	group["�޽ý�����"] = { "���μ�", "���μ�" };
	group["�̴��Ǽҳ�"] = { "��", "�ø���� ��" };
	group["����"] = { "��Ű��", "ö��7" };
	group["�ڿ���"] = { "������", "����", "����" };

	// �׷��̸��� �Է��ϸ� ����� ����ϴ� ���α׷�
	// (�׷��̸��� ������ ����� �Է¹޾� ����� ���� �ִ�.)
	
	while (true) {
		cout << "ã�� �׷� �̸��� �Է��ϼ���: ";
		string groupName;
		cin >> groupName;

		auto p = group.find(groupName);
		if (p == group.end()) {
			cout << groupName << "�� ��ϵ� �׷��� �ƴմϴ�." << endl;
			continue;
		}
		cout << "�׷� " << p->first << "�� ���: ";
		for (const string& name : (p->second))
			cout << name << " ";
		cout << endl;
	}
	//save("�ҽ�.cpp");
}