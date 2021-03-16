#include <iostream>
#include <filesystem>
#include <fstream>
#include <ctime>
#include "save.h"

// google coding convention
void save(std::string_view fileName)
{
	// 어떠한 파일을 저장하는지 화면에 출력함. - 파일name & size
	std::cout << "저장: " << fileName << ", 크기: " << std::filesystem::file_size(fileName) << std::endl;

	std:: ofstream out("2021 1학기 STL 화56 목56 강의저장.txt", std::ios::app);

	std::ifstream in(fileName);

	using namespace std;
	// 파일을 기록한 시간도 기록
	time_t t = time(nullptr);

	out.imbue(std::locale("korean"));

	out << "===============================================" << endl;
	out << "저장시간 : " << put_time(localtime(&t), "%c %A") << endl;
	out << "===============================================" << endl;

	int c; // EOF 검사용(파일의 종점)
	while ((c = in.get()) != EOF)
		out.put(c);
	// RAII
}

/*using namespace std::chrono;

	auto b = steady_clock::now();

	this_thread::sleep_for(333ms);

	cout << "경과시간(밀리초) - "
		<< duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;*/