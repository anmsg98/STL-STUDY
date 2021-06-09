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


	ifstream in{ "단어들.txt" };

	if (!in)
	{
		cout << "파일을 열 수 없습니다." << endl;
	}

	vector<PS> v{ istream_iterator<string>{in}, {} };

	// PS의 first 기준으로 정렬한다.
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
	});

	for (int i = 0; i < 500; ++i)
	{
		cout << v[i].first << " - " << v[i].second << endl;
	}
	cout << endl;

	// [문제] 이 사전의 모든 anagram 쌍을 출력하라.
	while (true)
	{
		// 나와 다음 것이 같은지 찾는다.
		// if (찾음)
		//	  찾은 자리를 저장하고
		//    다음 위치와 다른 값이 나오는 자리를 찾는다.
		//    if (end())
	}
}
