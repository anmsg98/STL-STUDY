//-----------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 3�� 23�� ȭ����            (4�� 1��)
//
// ������ ����� ������ class(�ڿ��� Ȯ���ϴ�) ����� �α�
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

// [����] "�ҽ�.cpp"�� �ִ� �ܾ ������ ��
// ������������ �����Ͽ� ����϶�.

int main()

{
	ifstream in{ "�ҽ�.cpp" };
	vector<string> v{ istream_iterator<string>{in},{} };
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\t"));

	//save("�ҽ�.cpp");
}