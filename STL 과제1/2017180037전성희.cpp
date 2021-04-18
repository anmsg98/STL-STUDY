#include <iostream>
#include <string>
#include <chrono>
#include <array>
#include <fstream>
#include <algorithm>
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
	os << "�̸�: " << player.name << ", ���̵�: " << player.id << ", ����: " << player.score << ", �ڿ���: " << player.num /*<< ", ���۹���: " << player.p*/;
	return os;
}

array<Player, 1000000> a;

int main()
{
	/*1��*/
	auto b = chrono::steady_clock::now();	//�����ġ ����
	ifstream in{ "Player 100����",ios::binary };
	
	for (int i = 0; i < 1000000; ++i)
		a[i].read(in);

	cout << a[999999] << endl;

	/*2��*/
	int aver = 0;
	for (auto i : a)
		aver += i.score;
	cout << "������ ��հ�: " << aver / 1000000.0 << endl << endl;
	
	/*3��*/
	ofstream out("����Ʈ ���� 500��"s, ios::binary);
	for (auto i : a) {
		if (i.num == 500) {
			out.write((char*)&i, sizeof(Player));
		}
	}
	cout << "����Ʈ ���� 500��.txt �����Ϸ�" << endl << endl;
	
	/*4��*/
	int input_id = 10;
	while (true) {
		cout << "id�� �Է� (����: ctrl+z): ";
		//cin >> input_id;
		if (cin.eof() == true)
			break;
		
		cout << endl << "==========ID �������� ����==========" << endl;
		sort(a.begin(), a.end(), [](const Player& a, const Player& b) {return a.id < b.id; });
		for (int i = 0; i < 1000000; ++i) {
			if (a[i].id == input_id) {
				cout << a[i - 1] << endl;
				cout << a[i] << endl;
				cout << a[i + 1] << endl;
			}
		}
		cout << endl;
		cout << "==========NAME �������� ����==========" << endl;
		sort(a.begin(), a.end(), [](const Player& a, const Player& b) {return a.name < b.name; });
		for (int i = 0; i < 1000000; ++i) {
			if (a[i].id == input_id) {
				cout << a[i - 1] << endl;
				cout << a[i] << endl;
				cout << a[i + 1] << endl;
			}
		}
		cout << endl;
		cout << "==========SCORE �������� ����==========" << endl;
		sort(a.begin(), a.end(), [](const Player& a, const Player& b) {return a.score < b.score; });
		for (int i = 0; i < 1000000; ++i) {
			if (a[i].id == input_id) {
				cout << a[i - 1] << endl;
				cout << a[i] << endl;
				cout << a[i + 1] << endl;
			}
		}
		cout << endl;
		auto e = chrono::steady_clock::now();	// �����ġ ��
		auto d = e - b;
		cout << "����ð�(��) - " << chrono::duration<double>(d).count() << endl << endl;
		break;
	}
	
	
	
}