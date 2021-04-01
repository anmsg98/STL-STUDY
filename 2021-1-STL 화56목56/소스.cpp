//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 4월 1일 목요일            (5주 2일)
//
// - vector
//-----------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include "save.h"
#include "String.h"
using namespace std;

// [문제] "소스.cpp"를 읽어 vector에 저장한 후 
// 거꾸로 화면에 출력하라.
int main()
{	
	ifstream in{ "소스.cpp" };
	
	vector<char> v;

	char c;
	while (in >> c) {
		v.push_back(c);
	}
	for (auto i = v.rbegin(); i != v.rend(); ++i) {
		cout << *i;
	}

	cout << endl << endl;
	//save("소스.cpp");
}