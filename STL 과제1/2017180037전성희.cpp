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
	string name; // 이름
	int id; // 아이디
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
	os << "이름: " << player.name << ", 아이디: " << player.id;
	return os;
}
istream& operator>>(istream& is, Player& player) {
	is >> player;
	return is;
}

int main()
{
	Player player;
	vector<Player> v;
	int i = 0;
	
	ifstream in{ "중간시험.dat"s};
	
	while (in >> player) {
		v.push_back(player);
	}
	
}