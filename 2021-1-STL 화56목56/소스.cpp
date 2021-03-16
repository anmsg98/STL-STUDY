//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 3월 16일 화요일            (3주 1일)
//
// Dog 만들고 저장하고 읽어 정렬하기 시작할 것
// callable type
//
// 앞으로 사용할 관찰용 class 만들어 두기
//-----------------------------------------------------------------

#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include "save.h"
using namespace std;

// [문제] Dog 객체를 만들어 파일에 저장하고 다시 읽어 정렬해 본다.
// 파일 "Dog 만객체"에 바이너리 모드로 저장되어 있는 Dog 10000 객체를 읽어라 
// id 오름차순으로 정렬

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

	static int cnt; // 4 - 클래스 공통

	friend ostream& operator<<(ostream& os, const Dog& dog);
};

int Dog::cnt = { 1 };

ostream& operator<<(ostream& os, const Dog& dog)
{
	os << "이름: " << dog.name << ", 아이디: " << dog.id;
	return os;
}

Dog dogs[10000];

int main()
{

	ifstream in{ "Dog 만객체.txt",ios::binary };
	
	Dog* dogs = new Dog[10000]; // 같은 타입의 포인터로 받아야됨

	in.read((char*)dogs, sizeof(Dog) * 10000);

	for (int i = 0; i < 10000; i++)
		cout << dogs[i] << endl;
	//save("소스.cpp");
}



