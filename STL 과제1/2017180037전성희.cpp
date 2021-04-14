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
	string name; // 이름
	int score; // 점수
	int id; // 아이디
	size_t num; // 확보한 메모리 바이트 수
	char* p; // 확보한 메모리의 시작번지
	friend ostream& operator<<(ostream& os, const Player& player);

	Player(istream& in) {
		in.read((char*)this, sizeof(Player));
		p = new char[num] {};
		in.read((char*)p, num);
	}
};

ostream& operator<<(ostream& os, const Player& player)
{
	os << "이름: " << player.name << ", 아이디: " << player.id << ", 점수: " << player.score << ", 자원수: " << player.num;
	return os;
}

int main()
{
	int aver=0;
	int cnt = 0;
	ifstream in{ "Player 100만개",ios::binary };
	vector<Player> v;
	for (int i = 0; i < 1000000; i++) {
		v.push_back(Player(in));
	}

	auto i = v.cend()-1;
		cout << *i << endl;

	for (auto i : v)
		aver += i.score;
	cout << "점수의 평균값: " << aver / 1000000 << endl;
	for (auto i : v) {
		cnt++;
		if (i.num == 500)
			cout << cnt << "/ " << i << endl;
	}
}