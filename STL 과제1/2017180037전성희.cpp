#include <iostream>
#include <string>
#include <chrono>
#include <array>
#include <fstream>
#include <algorithm>
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
	Player()
	{

	}
	void read(istream& is)
	{
		is.read((char*)this, sizeof(Player));
		p = new char[num] {};
		//cout << name << endl;
		//cout << score << endl;
		//cout << id << endl;
		//cout << num << endl;
		//cout << p << endl;
		is.read((char*)p, num);
		//cout << p << endl;
		//cout << "=======================" << endl;
	}
};


ostream& operator<<(ostream& os, const Player& player)
{
	os << "이름: " << player.name << ", 아이디: " << player.id << ", 점수: " << player.score << ", 자원수: " << player.num /*<< ", 시작번지: " << player.p*/;
	return os;
}

array<Player, 1000000> a;

int main()
{
	/*1번*/
	auto b = chrono::steady_clock::now();	//스톱워치 시작
	ifstream in{ "Player 100만개",ios::binary };
	
	for (int i = 0; i < 1000000; ++i)
		a[i].read(in);

	cout << a[999999] << endl;

	/*2번*/
	int aver = 0;
	for (auto i : a)
		aver += i.score;
	cout << "점수의 평균값: " << aver / 1000000.0 << endl << endl;
	
	/*3번*/
	ofstream out("바이트 수가 500개"s, ios::binary);
	for (auto i : a) {
		if (i.num == 500) {
			out.write((char*)&i, sizeof(Player));
		}
	}
	cout << "바이트 수가 500개.txt 생성완료" << endl << endl;
	
	/*4번*/
	int input_id = 10;
	while (true) {
		cout << "id값 입력 (종료: ctrl+z): ";
		//cin >> input_id;
		if (cin.eof() == true)
			break;
		
		cout << endl << "==========ID 오름차순 정렬==========" << endl;
		sort(a.begin(), a.end(), [](const Player& a, const Player& b) {return a.id < b.id; });
		for (int i = 0; i < 1000000; ++i) {
			if (a[i].id == input_id) {
				cout << a[i - 1] << endl;
				cout << a[i] << endl;
				cout << a[i + 1] << endl;
			}
		}
		cout << endl;
		cout << "==========NAME 오름차순 정렬==========" << endl;
		sort(a.begin(), a.end(), [](const Player& a, const Player& b) {return a.name < b.name; });
		for (int i = 0; i < 1000000; ++i) {
			if (a[i].id == input_id) {
				cout << a[i - 1] << endl;
				cout << a[i] << endl;
				cout << a[i + 1] << endl;
			}
		}
		cout << endl;
		cout << "==========SCORE 오름차순 정렬==========" << endl;
		sort(a.begin(), a.end(), [](const Player& a, const Player& b) {return a.score < b.score; });
		for (int i = 0; i < 1000000; ++i) {
			if (a[i].id == input_id) {
				cout << a[i - 1] << endl;
				cout << a[i] << endl;
				cout << a[i + 1] << endl;
			}
		}
		cout << endl;
		auto e = chrono::steady_clock::now();	// 스톱워치 끝
		auto d = e - b;
		cout << "경과시간(초) - " << chrono::duration<double>(d).count() << endl << endl;
		break;
	}
	
	
	
}