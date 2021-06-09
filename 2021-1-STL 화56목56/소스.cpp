// ================================================================
// 2021. 1�б� STL ȭ56��56 - 05��13�� ����� (11�� 2��)
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

// e-class���� "�ܾ��.txt"�� �ٿ�޾� vector�� �����϶�.

// [����] ��� �� �ܾ����� ����϶�.

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


	ifstream in{ "����1.dat"s, ios::binary };
	vector<string> v{ istream_iterator<string>{in}, {} };
	for (auto c : v)
		cout << c << " ";

	
}
