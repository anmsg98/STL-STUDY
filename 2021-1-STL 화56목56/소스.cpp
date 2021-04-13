//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 4월 13일 화요일            (7주 1일)
//
// 1. sequence 컨테이너
//	원소를 삭제/추가 하는 동작이 0(1)
//	- list
//	- forward_list
//-----------------------------------------------------------------

#include <iostream>
#include <list>
#include "save.h"
#include "String.h"
using namespace std;


int main()
{	
	list<String> c{ 1,3,5,7,9,2,4,6,8,10 };
	c.sort([](const String& a, const String& b) {
		return a.size() < b.size();
		});
	//c.reverse();	// 리스트의 순서를 반대로 바꿔줌
	// 전체를 순회하며 출력하자
	for (const String& s : c)
		cout << s << endl;

	//save("소스.cpp");
}