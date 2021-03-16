//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 3�� 16�� ȭ����            (3�� 1��)
//
// ȣ�� ������ Ÿ�� - callable type
//
// ������ ����� ������ class(�ڿ��� Ȯ���ϴ�) ����� �α�
//-----------------------------------------------------------------

#include <iostream>
#include <thread>
#include "save.h"
using namespace std;

// ��Ű��
// ���ʹ�ư - ����, �����ʹ�ư - �����̵�
//
// ������ ���� ��ư�� �ٲ��.
// ���α׷� ������ ��� ������?

void jump() {
	cout << "����" << endl;
}
void slide() {
	cout << "�����̵�" << endl;
}
void (*left_function)() = jump;

void left()
{
	left_function();
}

int main()
{
	// 10���� �ѹ��� ����� �ٲ۴�.

	int cnt{};
	while (true) {
		left();
		this_thread::sleep_for(500ms);
		++cnt;
		if (cnt == 10) {
			left_function = slide;
		}
	}
	
	//save("�ҽ�.cpp");
}



