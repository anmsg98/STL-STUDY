// ----------------------------------------------------------------------------
// String.h - STL ���� ������ �����ϱ� ���� ���� �ڿ��� Ȯ���ϴ� Ŭ����
//
// 2021. 3. 30									Programmed by wulong
//-----------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <random>
#include <string>

using std::cout;
using std::endl;

//#define ����			// �� �ּ��� Ǯ�� special member�� ������ �� �� �ִ�.

std::default_random_engine dre;
std::uniform_int_distribution<> uidAlpha{ 'a', 'z' };

// 2021. 4. 20
// String�� �ܺο� �����ϴ� �ݺ���
class String_iterator 
{
	char* p{ nullptr };
public:
	String_iterator(char* p) : p{ p } {}
	
	int operator-(const String_iterator& rhs)const {
		return p - rhs.p;
	}
	bool operator!=(const String_iterator& rhs)const {
		return p != rhs.p;
	}
	bool operator==(const String_iterator& rhs)const {
		return p == rhs.p;
	}
	bool operator<(const String_iterator& rhs)const {
		return p < rhs.p;
	}
	String_iterator& operator++() {
		++p;
		return *this;
	}
	String_iterator& operator--() {
		--p;
		return *this;
	}
};

class String
{
	using iterator = String_iterator;
	using value_type = char;

public:
	String() : num{}, p{}
	{
#ifdef ����
		cout << "������() (this:" << this << ") - ����: " << num << ", ��ġ:" << (void*)p << endl;
#endif
	}

	String(size_t n) : num{ n }, p{ new char[num] }
	{
		for (int i = 0; i < num; ++i)
			p[i] = uidAlpha(dre);

#ifdef ����
		cout << "������(int) (this:" << this << ") - ����: " << num << ", ��ġ:" << (void*)p << endl;
#endif
	}

	String(const char* str) : num{ strlen(str) }, p{ new char[num] }
	{
		memcpy(p, str, num);

#ifdef ����
		cout << "������(const char*) (this:" << this << ") - ����: " << num << ", ��ġ:" << (void*)p << endl;
#endif
	}

	~String()
	{
		delete[] p;

#ifdef ����
		cout << "�Ҹ��� (this:" << this << ") - ����: " << num << ", ��ġ:" << (void*)p << endl;
#endif
	}

	// ���������
	String(const String& other) : num{ other.num }, p{ new char[num] }
	{
		memcpy(p, other.p, num);

#ifdef ����
		cout << "��������� (this:" << this << ") - ����: " << num << ", ��ġ:" << (void*)p << endl;
#endif
	}

	// �����Ҵ翬����
	String& operator=(const String& other)
	{
		if (this != &other)
		{
			// this->~String(); ��¸޽����� �� �� �ǹǷ� �ּ�ó��
			delete[] p;
			num = other.num;
			p = new char[num];
			memcpy(p, other.p, num);
		}

#ifdef ����
		cout << "�����Ҵ翬���� (this:" << this << ") - ����: " << num << ", ��ġ:" << (void*)p << endl;
#endif
		return *this;
	}

	// �̵�������
	// noexcept : �̵� ������ ������ ���� ���� ���̴�.(������ ����)
	String(String&& other) noexcept : num{ other.num }
	{
		p = other.p;
		other.p = nullptr;
		other.num = 0;

#ifdef ����
		cout << "�̵������� (this:" << this << ") - ����: " << num << ", ��ġ:" << (void*)p << endl;
#endif
	}

	// �̵��Ҵ翬����
	String& operator=(String&& other)
	{
		if (this != &other)
		{
			// this->~String(); ��¸޽����� �� �� �ǹǷ� �ּ�ó��
			delete[] p;
			num = other.num;
			p = other.p;

			other.num = 0;
			other.p = nullptr;
		}

#ifdef ����
		cout << "�̵��Ҵ翬���� (this:" << this << ") - ����: " << num << ", ��ġ:" << (void*)p << endl;
#endif
		return *this;
	}

	size_t size() const
	{
		return num;
	}

	// Ȯ���� �ڿ��� std::stringó�� �̿��� �� �ְ� ����.
	std::string getString() const
	{
		return std::string(p, p + num);
	}
	// 2021. 4. 20
	iterator begin() {
		return iterator{ p };
	}
	// 2021. 4. 20
	iterator end() {
		return iterator{ p + num };
	}
	
private:
	size_t num;							// Ȯ���� �ڿ��� ��
	char* p;							// Ȯ���� �ڿ��� ��ġ
	friend std::ostream& operator<<(std::ostream&, const String&);
	
};

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (int i = 0; i < s.num; ++i)
		os << s.p[i];

	return os;
}