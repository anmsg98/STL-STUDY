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


	ifstream in{ "�ܾ��.txt" };

	if (!in)
	{
		cout << "������ �� �� �����ϴ�." << endl;
	}

	vector<PS> v{ istream_iterator<string>{in}, {} };

	// PS�� first �������� �����Ѵ�.
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
	});

	for (int i = 0; i < 500; ++i)
	{
		cout << v[i].first << " - " << v[i].second << endl;
	}
	cout << endl;

	// [����] �� ������ ��� anagram ���� ����϶�.
	while (true)
	{
		// ���� ���� ���� ������ ã�´�.
		// if (ã��)
		//	  ã�� �ڸ��� �����ϰ�
		//    ���� ��ġ�� �ٸ� ���� ������ �ڸ��� ã�´�.
		//    if (end())
	}
}
