#include <iostream>
#include <filesystem>
#include <fstream>
#include <ctime>
#include "save.h"

// google coding convention
void save(std::string_view fileName)
{
	// ��� ������ �����ϴ��� ȭ�鿡 �����. - ����name & size
	std::cout << "����: " << fileName << ", ũ��: " << std::filesystem::file_size(fileName) << std::endl;

	std:: ofstream out("2021 1�б� STL ȭ56 ��56 ��������.txt", std::ios::app);

	std::ifstream in(fileName);

	using namespace std;
	// ������ ����� �ð��� ���
	time_t t = time(nullptr);

	out.imbue(std::locale("korean"));

	out << "===============================================" << endl;
	out << "����ð� : " << put_time(localtime(&t), "%c %A") << endl;
	out << "===============================================" << endl;

	int c; // EOF �˻��(������ ����)
	while ((c = in.get()) != EOF)
		out.put(c);
	// RAII
}

/*using namespace std::chrono;

	auto b = steady_clock::now();

	this_thread::sleep_for(333ms);

	cout << "����ð�(�и���) - "
		<< duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;*/