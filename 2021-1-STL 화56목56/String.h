//-----------------------------------------------------------------------------
// String.h - STL 내부 동작을 관찰하기 위해 만든 자원을 확보하는 클래스
//
// 2021. 3. 30									Programmed by wulong
//-----------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <random>
#include <string>

using std::cout;
using std::endl;

//#define 관찰			// 이 주석을 풀면 special member의 동작을 알 수 있다.

std::default_random_engine dre;
std::uniform_int_distribution<> uidAlpha{ 'a', 'z' };

// 2021. 04. 20.
// String이 외부에 제공하는 반복자
class String_iterator : 
	public std::iterator<std :: random_access_iterator_tag, char>
{
	char* p{ nullptr };
public:
	String_iterator() = default;
	String_iterator(char* p) : p{ p } {}
	
	// 2021. 04. 29
	// _ULast - _ULast
	int operator-(const String_iterator& rhs) const {
		return p - rhs.p;
	}

	String_iterator operator+(int n) const {
		return String_iterator{ p + n };
	}

	String_iterator operator-(int n) const {
		return String_iterator{ p - n };
	}

	bool operator!=(const String_iterator& rhs) const {
		return p != rhs.p;
	}

	bool operator==(const String_iterator& rhs) const {
		return p == rhs.p;
	}

	bool operator<(const String_iterator& rhs) const {
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

	char& operator*() {
		return *p;
	}

	char& operator*() const{
		return *p;
	}

};

// 2021. 04. 27.
// String의 역방향 반복자 추가
class String_reverse_iterator
{
public:
	String_reverse_iterator(char* p) : p{ p } {}
	~String_reverse_iterator() {}

public:
	bool operator ==(const String_reverse_iterator& rhs) const
	{
		return p == rhs.p;
	}

	bool operator !=(const String_reverse_iterator& rhs) const
	{
		return p != rhs.p;
	}

	String_reverse_iterator& operator--()
	{
		++p;

		return *this;
	}

	String_reverse_iterator& operator++()
	{
		// 반복자 어댑터 : 겉과 다르게 속에서는 다른 행동을 함.(++인데 내부에서는 --를 하고 있음)
		--p;

		return *this;
	}

	char& operator*()
	{
		return *(p - 1);
	}

private:
	char* p;
};

class String
{
	using iterator = String_iterator;
	using reverse_iterator = String_reverse_iterator;
	using value_type = char;

public:
	String() : num{}, p{}
	{
#ifdef 관찰
		cout << "생성자() (this:" << this << ") - 갯수: " << num << ", 위치:" << (void*)p << endl;
#endif
	}

	String(size_t n) : num{ n }, p{ new char[num] }
	{
		for (int i = 0; i < num; ++i)
			p[i] = uidAlpha(dre);

#ifdef 관찰
		cout << "생성자(int) (this:" << this << ") - 갯수: " << num << ", 위치:" << (void*)p << endl;
#endif
	}

	String(const char* str) : num{ strlen(str) }, p{ new char[num] }
	{
		memcpy(p, str, num);

#ifdef 관찰
		cout << "생성자(const char*) (this:" << this << ") - 갯수: " << num << ", 위치:" << (void*)p << endl;
#endif
	}

	~String()
	{
		delete[] p;

#ifdef 관찰
		cout << "소멸자 (this:" << this << ") - 갯수: " << num << ", 위치:" << (void*)p << endl;
#endif
	}

	// 복사 생성자
	String(const String& other) : num{ other.num }, p{ new char[num] }
	{
		memcpy(p, other.p, num);

#ifdef 관찰
		cout << "복사생성자 (this:" << this << ") - 갯수: " << num << ", 위치:" << (void*)p << endl;
#endif
	}

	// 복사 할당 연산자
	String& operator=(const String& other)
	{
		if (this != &other)
		{
			// this->~String(); 출력메시지가 두 번 되므로 주석처리
			delete[] p;
			num = other.num;
			p = new char[num];
			memcpy(p, other.p, num);
		}

#ifdef 관찰
		cout << "복사할당연산자 (this:" << this << ") - 갯수: " << num << ", 위치:" << (void*)p << endl;
#endif
		return *this;
	}

	// 이동 생성자
	// noexcept : 이동 과정에 문제될 일이 없을 것이다.(보증서 역할)
	String(String&& other) noexcept : num{ other.num }
	{
		p = other.p;
		other.p = nullptr;
		other.num = 0;

#ifdef 관찰
		cout << "이동생성자 (this:" << this << ") - 갯수: " << num << ", 위치:" << (void*)p << endl;
#endif
	}

	// 이동 할당 연산자
	String& operator=(String&& other) noexcept
	{
		if (this != &other)
		{
			// this->~String(); 출력메시지가 두 번 되므로 주석처리
			delete[] p;
			num = other.num;
			p = other.p;

			other.num = 0;
			other.p = nullptr;
		}

#ifdef 관찰
		cout << "이동할당연산자 (this:" << this << ") - 갯수: " << num << ", 위치:" << (void*)p << endl;
#endif
		return *this;
	}
	bool operator==(const String& rhs)const {
		if (num != rhs.num)
			return false;
		for (int i = 0; i < num; ++i)
			if (p[i] != rhs.p[i])
				return false;

		return true;
	}

private:
	size_t num;							// 확보한 자원의 수
	char* p;							// 확보한 자원의 위치

private:
	friend std::ostream& operator<<(std::ostream&, const String&);

public:
	size_t size() const
	{
		return num;
	}

	// 확보한 자원을 std::string처럼 이용할 수 있게 하자.
	std::string getString() const
	{
		return std::string(p, p + num);
	}

	// 2021. 04. 20.
	iterator begin()
	{
		return iterator{ p };
	}

	// 2021. 04. 20.
	iterator end()
	{
		return iterator{ p + num };
	}

	// 2021. 04. 27.
	reverse_iterator rbegin()
	{
		return reverse_iterator{ p + num };
	}

	// 2021. 04. 27.
	reverse_iterator rend()
	{
		return reverse_iterator{ p };
	}
};

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (int i = 0; i < s.num; ++i)
	{
		os << s.p[i];
	}

	return os;
}
