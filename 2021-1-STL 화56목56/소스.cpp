//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 4월 13일 화요일            (7주 1일)
//
// 1. sequence 컨테이너
//	원소를 삭제/추가 하는 동작이 0(1)
//	- list
//	- forward_list
//-----------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string_view>
#include <fstream>
#include <random>
#include <algorithm>
#include "save.h"
using namespace std;

// [문제] 파일 "int 100개.txt"에 바이너리로 저장되어있는 정수 100개가 있다.
// 읽은 정수 100개를 내림차순으로 정렬한 후 출력.

int main()
{
	int a[100];
	ifstream in{ "int 100개다.txt", ios::binary };
	in.read((char*)&a, 100 * sizeof(int));
	sort(begin(a), end(a), greater<int>());

	for (int n : a)
		cout << n << endl;
}
