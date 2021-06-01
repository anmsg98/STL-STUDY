//-------------------------------------------------------------------------
<<<<<<< HEAD
// 2021. 1학기 STL 화56 목56  - 6월 1일 화요일            (14주 1일)
=======
// 2021. 1학기 STL 화56 목56  - 5월 25일 화요일            (13주 1일)
>>>>>>> 5459dd79ae62a484d6f612060d862f993c0308e8
//
// 알고리즘 함수 살펴보기
// 알고리즘 사용예제(anagram)
// range, view
//
// 기말시험 - 6월 10일 (목요일) (15주 2일)
//-------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include "save.h"
#include "String.h"
using namespace std;

<<<<<<< HEAD
struct PS : public pair<string, string>
{
	PS() = default;
	PS(string s) : pair<string, string>(s, s) {
		sort(first.begin(), first.end());
	}
};

int main()
{
	ifstream in{ "단어들.txt" };
	vector<PS> v{ istream_iterator<string>{in}, {} };
	// PS first 기준으로 정렬한다.
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});

	for (int i = 210000; i < 210200; ++i)
		cout << v[i].first << " - " << v[i].second << endl;
	
	// [문제] 이 사전의 모든 애너그램 쌍을 출력하라
	while (true) {
		// 나와 다음 것이 같은 지 찾는다.
		// if ( 찾음 )
		//	 찾은 자리를 저장하고
		//	 다음 위치와 다른 값이 나오는 자리를 찾는다.
		//	 if (end())
	}
	
=======
// partition

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	// 홀짝으로 분리하라.
	stable_partition(v.begin(), v.end(), [](int n) {
		return n % 2 == 1;
		});

	for (int n : v)
		cout << n << " ";
	cout << endl;
>>>>>>> 5459dd79ae62a484d6f612060d862f993c0308e8
	//save("소스.cpp");
}