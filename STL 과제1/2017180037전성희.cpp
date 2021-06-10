#include <iostream>
#include <string>
#include <chrono>
#include <array>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Player {
public:
	string name; // �̸�
	int id; // ���̵�
	friend ostream& operator<<(ostream& os, const Player& player);
	friend istream& operator>>(istream& is, Player& player);


	void read(istream& in)
	{
		in >> name;
		in >> id;
	}
};
ostream& operator<<(ostream& os, const Player& player)
{
	os << "�̸�: " << player.name << ", ���̵�: " << player.id;
	return os;
}
istream& operator>>(istream& is, Player& player) {
	is >> player.name >> player.id;
	return is;
}

int main()
{
	Player player;
	vector<Player> v;
	int i = 0;
	
	ifstream in{ "�߰�����.dat"s};
	
	while (in >> player) {
		v.push_back(player);
	}
	for (int i = 0; i < v.size(); ++i)
		cout << "[" << i << "] " << v[i] << endl;
	
}