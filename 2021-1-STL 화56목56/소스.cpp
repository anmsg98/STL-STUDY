// ================================================================
// 2021. 1학기 STL 화56목56 - 05월13일 목요일 (11주 2일)
// 
// Sequence Container
// Associative Container : set(p.281), map - key/value
// Unordered Associative Container
// ================================================================
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "save.h"
#include "String.h"

using namespace std;

// e-class에서 "단어들.txt"를 다운받아 vector에 저장하라.

// [문제] 모두 몇 단어인지 출력하라.

struct PS : public pair<string, string>
{
public:
	PS() = default;

	PS(string s) : pair<string, string>(s, s)
	{
		sort(first.begin(), first.end());
	}
};

int main()
{


	ifstream in{ "시험1.dat"s, ios::binary };
	vector<string> v{ istream_iterator<string>{in}, {} };
	for (auto c : v)
		cout << c << " ";

	
}
