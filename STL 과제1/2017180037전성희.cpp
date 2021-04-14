#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <algorithm>
#include "Player.h"
using namespace std;

class Player {
public:
	string name; // �̸�
	int score; // ����
	int id; // ���̵�
	size_t num; // Ȯ���� �޸� ����Ʈ ��
	char* p; // Ȯ���� �޸��� ���۹���
	friend ostream& operator<<(ostream& os, const Player& player);

	Player(istream& in) {
		in.read((char*)this, sizeof(Player));
		p = new char[num] {};
		in.read((char*)p, num);
	}
};

ostream& operator<<(ostream& os, const Player& player)
{
	os << "�̸�: " << player.name << ", ���̵�: " << player.id << ", ����: " << player.score << ", �ڿ���: " << player.num;
	return os;
}

int main()
{
	int aver=0;
	int cnt = 0;
	ifstream in{ "Player 100����",ios::binary };
	vector<Player> v;
	for (int i = 0; i < 1000000; i++) {
		v.push_back(Player(in));
	}

	auto i = v.cend()-1;
		cout << *i << endl;

	for (auto i : v)
		aver += i.score;
	cout << "������ ��հ�: " << aver / 1000000 << endl;
	for (auto i : v) {
		cnt++;
		if (i.num == 500)
			cout << cnt << "/ " << i << endl;
	}
}