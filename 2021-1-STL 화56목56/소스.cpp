//-------------------------------------------------------------------------
<<<<<<< HEAD
// 2021. 1�б� STL ȭ56 ��56  - 6�� 1�� ȭ����            (14�� 1��)
=======
// 2021. 1�б� STL ȭ56 ��56  - 5�� 25�� ȭ����            (13�� 1��)
>>>>>>> 5459dd79ae62a484d6f612060d862f993c0308e8
//
// �˰��� �Լ� ���캸��
// �˰��� ��뿹��(anagram)
// range, view
//
// �⸻���� - 6�� 10�� (�����) (15�� 2��)
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
	ifstream in{ "�ܾ��.txt" };
	vector<PS> v{ istream_iterator<string>{in}, {} };
	// PS first �������� �����Ѵ�.
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});

	for (int i = 210000; i < 210200; ++i)
		cout << v[i].first << " - " << v[i].second << endl;
	
	// [����] �� ������ ��� �ֳʱ׷� ���� ����϶�
	while (true) {
		// ���� ���� ���� ���� �� ã�´�.
		// if ( ã�� )
		//	 ã�� �ڸ��� �����ϰ�
		//	 ���� ��ġ�� �ٸ� ���� ������ �ڸ��� ã�´�.
		//	 if (end())
	}
	
=======
// partition

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	// Ȧ¦���� �и��϶�.
	stable_partition(v.begin(), v.end(), [](int n) {
		return n % 2 == 1;
		});

	for (int n : v)
		cout << n << " ";
	cout << endl;
>>>>>>> 5459dd79ae62a484d6f612060d862f993c0308e8
	//save("�ҽ�.cpp");
}