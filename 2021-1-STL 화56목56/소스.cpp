//-------------------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 5월 18일 화요일            (12주 1일)
//
// 대표 컨테이너의 찾기 실력을 검증한다.
// 1. vector			- 0( n )	
// 2. set				- 0( log n )
// 3. unordered_set		- 0( 1 )
// 기말시험 - 6월 10일 (목요일) (15주 2일)
//-------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <array>
#include <algorithm>
#include <chrono>
#include "save.h"
#include "String.h"
using namespace std;

uniform_int_distribution<> sel{ 1,10000 };
// 찾을 대상 전체를 컨테이너에 저장한다.
// 그 중에서 특정 원소를 찾아본다. (존재하는 객체와 같은 객체를 준비해야 한다)
// 각 컨테이너 별로 걸리는 시간을 측정한다.
// 결과를 살펴본다.

const int NUM{ 1'0000 };		// 저장한 개수
const int FNUM{ 1'0000 };			// 찾을 개수

int main()
{
	//// 벡터에 String을 저장한다.
	//// 길이 1부터 NUM까지 길이를 갖는 String을 저장
	//vector<String> v;
	//v.reserve(NUM); // 메모리를 확보해 놓음

	//cout << "데이터 생성 중..." << endl;
	//for (int i = 0; i < NUM; ++i)
	//	v.emplace_back(i + 1);
	//cout << "데이터 생성 완료" << endl;

	//// 찾을 객체를 array에 저장한다.
	//array<String, FNUM> arr;

	//for (int i = 0; i < FNUM; ++i)
	//	arr[i] = v[sel(dre)];

	//// 10%는 존재하지 않는 데이터
	//for (int i = 0; i < FNUM * 0.1; ++i)
	//	arr[i] = move(String(sel(dre)));
	//cout << endl;
	//{	// 벡터의 실력을 알아본다
	//	int cnt{};

	//	using namespace std::chrono;
	//	// 시간 시작
	//	auto b = steady_clock::now();
	//	for (int j = 0; j < 10; ++j) {
	//		for (int i = 0; i < FNUM; ++i)
	//			if (find(v.begin(), v.end(), arr[i]) != v.end())
	//				++cnt;
	//	}
	//	// 시간 끝
	//	cout << "벡터에서 찾기(밀리초) - "
	//		<< duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;
	//	cout << "찾은 개수 - " << cnt << endl;
	//}

	//cout << endl;
	//{	// 셋의 실력을 알아본다
	//	set<String> s{ v.begin(), v.end() };

	//	int cnt{};

	//	using namespace std::chrono;
	//	// 시간 시작
	//	auto b = steady_clock::now();
	//	for (int j = 0; j < 10; ++j) {
	//		for (int i = 0; i < FNUM; ++i)
	//			if (s.find(arr[i]) != s.end())
	//				++cnt;
	//	}
	//	// 시간 끝
	//	cout << "셋에서 찾기(밀리초) - "
	//		<< duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;
	//	cout << "찾은 개수 - " << cnt << endl;
	//}
	
	// [문제] set에서 같은 원소란 무엇인가?
	cout << "셋에서 같다는 것의 의미?" << endl;
	cout << "동등(equivalence)하다는 의미를 사용하기 때문이다" << endl;
	cout << "상등(equality)은 ==로 같은 것을 판단할 때를 의미한다" << endl;
	set<String> s{ 5,1,3 };
	for (const String& s : s)
		cout << s << endl;
	String x{ 3 };
	cout << "3글자이지만 내용은 다르다 - " << x << endl;
	if (s.find(x) == s.end())
		cout << "없어" << endl;
	else
		cout << "있어" << endl;
	//save("소스.cpp");
}