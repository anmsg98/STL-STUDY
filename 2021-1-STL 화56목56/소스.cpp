//-------------------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 5�� 6�� �����            (10�� 2��)
//
// Sequnce ~
// Associative Container - set / map	key/value
// Unordered Associative ~
//-------------------------------------------------------------------------
#include <iostream>
#include <set>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include "save.h"
#include "String.h"
using namespace std;

// [����] "�ҽ�.cpp"�� �ܾ �о� ������������ ������ �� ���
// -set���� �ذ��غ��ô�.
int main()
{
	multiset<char> s; // multi - �ߺ��� ���� ���	
	ifstream in{ "�ҽ�.cpp" };
	copy(istream_iterator<char>{in}, {}, inserter(s, s.begin()));
	for (char s : s)
		cout << s;
	cout << endl;
	//save("�ҽ�.cpp");
}