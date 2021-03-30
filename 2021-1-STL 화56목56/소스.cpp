//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 3월 30일 화요일            (5주 1일)
//
// String.h를 다운받아 공통된 관찰을 해 본다.
//-----------------------------------------------------------------
#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"
#include "String.h"
using namespace std;

// [문제] STL 표준 컨테이너에 String을 원소(element)로 넣어본다.
// 사전 순서(lexicographical) 상 오름차순으로 정렬해보자
int main()
{	
	array<String, 3> words{ "다음주", "과제를", "준비하겠어요" };
	
	sort(words.begin(), words.end(), [](const String& a, const String& b) {
		return a.getData() < b.getData(); });

	//save("소스.cpp");
}