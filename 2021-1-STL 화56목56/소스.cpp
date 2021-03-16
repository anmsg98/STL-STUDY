//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 3�� 16�� ȭ����            (3�� 1��)
//
// Dog ����� �����ϰ� �о� �����ϱ� ������ ��
// callable type
//
// ������ ����� ������ class ����� �α�
//-----------------------------------------------------------------

#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include "save.h"
using namespace std;

// [����] Dog ��ü�� ����� ���Ͽ� �����ϰ� �ٽ� �о� ������ ����.
// ���� "Dog ����ü"�� ���̳ʸ� ���� ����Ǿ� �ִ� Dog 10000 ��ü�� �о�� 
// id ������������ ����

default_random_engine dre;
uniform_int_distribution<> uid;

class Dog {
public:
	Dog() : id{ uid(dre) } {
		name = "Dog"s;
		name += to_string(cnt);
		
		++cnt;
	}

private:
	int id;			// 4
	string name;	// 24 (28 - debug) -x64

	static int cnt; // 4 - Ŭ���� ����

	friend ostream& operator<<(ostream& os, const Dog& dog);
};

int Dog::cnt = { 1 };

ostream& operator<<(ostream& os, const Dog& dog)
{
	os << "�̸�: " << dog.name << ", ���̵�: " << dog.id;
	return os;
}

Dog dogs[10000];

int main()
{

	ifstream in{ "Dog ����ü.txt",ios::binary };
	
	Dog* dogs = new Dog[10000]; // ���� Ÿ���� �����ͷ� �޾ƾߵ�

	in.read((char*)dogs, sizeof(Dog) * 10000);

	for (int i = 0; i < 10000; i++)
		cout << dogs[i] << endl;
	//save("�ҽ�.cpp");
}



