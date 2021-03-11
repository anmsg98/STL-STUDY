//--------------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 3월 11일 목요일	(2주 2차시)
//
// 알고리즘 시간재기
// 스마트 포인터
//
// 앞으로 사용할 관찰용 class 만들어 두기
//--------------------------------------------------------------------

#include <iostream>
#include <thread>
#include <chrono>
#include "save.h"
using namespace std;

int main()
{
	using namespace std::chrono;
	//(수까락의 프로그래밍 참고)
	auto b = chrono::steady_clock::now();	//스톱워치 시작
	this_thread::sleep_for(333ms);
	
	cout << "경과시간(밀리초) - " << duration_cast<chrono::milliseconds>steady_clock::now() - b).count(); << endl;
	//save("소스.cpp");
}