//--------------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 3�� 11�� �����	(2�� 2����)
//
// �˰��� �ð����
// ����Ʈ ������
//
// ������ ����� ������ class ����� �α�
//--------------------------------------------------------------------

#include <iostream>
#include <thread>
#include <chrono>
#include "save.h"
using namespace std;

int main()
{
	using namespace std::chrono;
	//(������� ���α׷��� ����)
	auto b = chrono::steady_clock::now();	//�����ġ ����
	this_thread::sleep_for(333ms);
	
	cout << "����ð�(�и���) - " << duration_cast<chrono::milliseconds>steady_clock::now() - b).count(); << endl;
	//save("�ҽ�.cpp");
}