//-------------------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 5월 6일 목요일            (10주 2일)
//
// Sequnce ~
// Associative Container - set / map	key/value
// Unordered Associative ~
//-------------------------------------------------------------------------
#include <iostream>
#include <set>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include "save.h"
#include "String.h"
using namespace std;

// [문제] "소스.cpp"의 단어를 읽어 오름차순으로 정렬한 후 출력
// -set으로 해결해봅시다.
int main()
{
	multiset<char> s; // multi - 중복된 값을 허용	
	ifstream in{ "소스.cpp" };
	copy(istream_iterator<char>{in}, {}, inserter(s, s.begin()));
	for (char s : s)
		cout << s;
	cout << endl;
	//save("소스.cpp");
}