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
	Player() {

	}
	void read(istream& is)
	{
		is.read((char*)this, sizeof(Player));
		p = new char[num] {};
		is.read((char*)p, num);
	}
	void write(ostream& os) {
		os.write((char*)this, sizeof(Player));
		os.write((char*)p, num);
	}
};


ostream& operator<<(ostream& os, const Player& player)
{
	os << "�̸�: " << player.name << ", ���̵�: " << player.id << ", ����: " << player.score << ", �ڿ���: " << player.num;
	return os;
}

array<Player, 1000000> a;

int main()
{
	/*1��*/
	ifstream in{ "2021 STL ���� ����",ios::binary };
	
	for (int i = 0; i < 1000000; ++i)
		a[i].read(in);
	
	cout << *(a.end()-1) << endl;
	cout << endl;

	/*2��*/
	int aver = 0;
	for (auto i : a)
		aver += i.score;
	cout << "������ ��հ�: " << aver / 1000000.0 << endl << endl;
	
	/*3��*/
	int cnt{ 0 };
	ofstream out("����Ʈ ���� 500��"s, ios::binary);
	for (auto i : a) {
		if (i.num == 500) {
			i.write(out);
			cnt++;
		}
	}
	cout << "�޸� ����Ʈ ���� 500�� " << cnt << "���� ��ü�� ã��" << endl;
	cout << "'����Ʈ ���� 500��' ���� �����Ϸ�" << endl << endl;
	
	/*4��*/
	int input_id{ 0 };
	while (true) {
		cout << "id�� �Է� (����: ctrl+z): ";
		cin >> input_id;
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
	}	
}