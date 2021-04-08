//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 4월 8일 목요일            (6주 2일)
//
// deque
//
// 중간시험 - 4월 22일 (목요일)
//-----------------------------------------------------------------
#include <iostream>
#include <deque>
#include "save.h"
#include "String.h"
using namespace std;

int main()
{	
	deque<String> d;

	d.emplace(d.end(), "1");
	d.emplace(d.end(), "2");
	d.emplace(d.end(), "3");
	for (const String& s : d)
		cout << s << endl;
	
	//save("소스.cpp");
}