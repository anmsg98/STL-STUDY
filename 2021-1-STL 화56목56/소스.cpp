//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 3월 23일 화요일            (4주 1일)
//
// 앞으로 사용할 관찰용 class(자원을 확보하는) 만들어 두기
//-----------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>
#include "save.h"
#include "String.h"
using namespace std;

// [문제] "소스.cpp"에 있는 단어를 저장한 후
// 오름차순으로 정렬하여 출력하라.

int main()

{
	ifstream in{ "소스.cpp" };
	vector<string> v{ istream_iterator<string>{in},{} };
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\t"));

	//save("소스.cpp");
}