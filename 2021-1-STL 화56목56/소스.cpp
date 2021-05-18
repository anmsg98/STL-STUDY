//-------------------------------------------------------------------------
// 2021. 1�б� STL ȭ56 ��56  - 5�� 18�� ȭ����            (12�� 1��)
//
// ��ǥ �����̳��� ã�� �Ƿ��� �����Ѵ�.
// 1. vector			- 0( n )	
// 2. set				- 0( log n )
// 3. unordered_set		- 0( 1 )
// �⸻���� - 6�� 10�� (�����) (15�� 2��)
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
// ã�� ��� ��ü�� �����̳ʿ� �����Ѵ�.
// �� �߿��� Ư�� ���Ҹ� ã�ƺ���. (�����ϴ� ��ü�� ���� ��ü�� �غ��ؾ� �Ѵ�)
// �� �����̳� ���� �ɸ��� �ð��� �����Ѵ�.
// ����� ���캻��.

const int NUM{ 1'0000 };		// ������ ����
const int FNUM{ 1'0000 };			// ã�� ����

int main()
{
	//// ���Ϳ� String�� �����Ѵ�.
	//// ���� 1���� NUM���� ���̸� ���� String�� ����
	//vector<String> v;
	//v.reserve(NUM); // �޸𸮸� Ȯ���� ����

	//cout << "������ ���� ��..." << endl;
	//for (int i = 0; i < NUM; ++i)
	//	v.emplace_back(i + 1);
	//cout << "������ ���� �Ϸ�" << endl;

	//// ã�� ��ü�� array�� �����Ѵ�.
	//array<String, FNUM> arr;

	//for (int i = 0; i < FNUM; ++i)
	//	arr[i] = v[sel(dre)];

	//// 10%�� �������� �ʴ� ������
	//for (int i = 0; i < FNUM * 0.1; ++i)
	//	arr[i] = move(String(sel(dre)));
	//cout << endl;
	//{	// ������ �Ƿ��� �˾ƺ���
	//	int cnt{};

	//	using namespace std::chrono;
	//	// �ð� ����
	//	auto b = steady_clock::now();
	//	for (int j = 0; j < 10; ++j) {
	//		for (int i = 0; i < FNUM; ++i)
	//			if (find(v.begin(), v.end(), arr[i]) != v.end())
	//				++cnt;
	//	}
	//	// �ð� ��
	//	cout << "���Ϳ��� ã��(�и���) - "
	//		<< duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;
	//	cout << "ã�� ���� - " << cnt << endl;
	//}

	//cout << endl;
	//{	// ���� �Ƿ��� �˾ƺ���
	//	set<String> s{ v.begin(), v.end() };

	//	int cnt{};

	//	using namespace std::chrono;
	//	// �ð� ����
	//	auto b = steady_clock::now();
	//	for (int j = 0; j < 10; ++j) {
	//		for (int i = 0; i < FNUM; ++i)
	//			if (s.find(arr[i]) != s.end())
	//				++cnt;
	//	}
	//	// �ð� ��
	//	cout << "�¿��� ã��(�и���) - "
	//		<< duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;
	//	cout << "ã�� ���� - " << cnt << endl;
	//}
	
	// [����] set���� ���� ���Ҷ� �����ΰ�?
	cout << "�¿��� ���ٴ� ���� �ǹ�?" << endl;
	cout << "����(equivalence)�ϴٴ� �ǹ̸� ����ϱ� �����̴�" << endl;
	cout << "���(equality)�� ==�� ���� ���� �Ǵ��� ���� �ǹ��Ѵ�" << endl;
	set<String> s{ 5,1,3 };
	for (const String& s : s)
		cout << s << endl;
	String x{ 3 };
	cout << "3���������� ������ �ٸ��� - " << x << endl;
	if (s.find(x) == s.end())
		cout << "����" << endl;
	else
		cout << "�־�" << endl;
	//save("�ҽ�.cpp");
}