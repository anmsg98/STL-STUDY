//-----------------------------------------------------------------------------
// String.h - STL 내부 동작을 관찰하기 위해 만든 자원을 확보하는 클래스
//
// 2021. 3. 30									Programmed by wulong
// 2021  4.			iterator 추가
//-----------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <random>
#include <unordered_set>
#include <string>

using std::cout;
using std::endl;

//#define 관찰			// 이 주석을 풀면 special member의 동작을 알 수 있다.

std::default_random_engine dre;
std::uniform_int_distribution<> uidAlpha{ 'a', 'z' };
// 2021. 04. 20.
// String이 외부에 제공하는 반복자
class String_iterator // : public std::iterator<std::random_access_iterator_tag, char>
{
public:
	String_iterator() = default;
	String_iterator(char* p) : p{ p } {}
	~String_iterator() {}

private:
	char* p;

public:
	// [algorithm] _ULast - _UFirst
	int operator-(const String_iterator& rhs) const
	{
		return p - rhs.p;
	}

	String_iterator operator-(int n) const
	{
		return String_iterator{ p - n };
	}

	String_iterator operator+(int n) const
	{
		return String_iterator{ p + n };
	}

	bool operator==(const String_iterator& rhs) const
	{
		return p == rhs.p;
	}

	bool operator!=(const String_iterator& rhs) const
	{
		return p != rhs.p;
	}

	bool operator<(const String_iterator& rhs) const
	{
		return p < rhs.p;
	}

	bool operator>(const String_iterator& rhs) const
	{
		return p > rhs.p;
	}

	String_iterator& operator--()
	{
		--p;

		return *this;
	}

	String_iterator& operator++()
	{
		++p;

		return *this;
	}

	char& operator* ()
	{
		return *p;
	}

	char& operator*() const
	{
		return *p;
	}
};

template<>
struct std::iterator_traits<String_iterator>
{
	using iterator_concept = std::contiguous_iterator_tag;
	using iterator_category = std::random_access_iterator_tag;
	using ptrdiff_t = std::ptrdiff_t;
	using pointer = char*;
	using reference = char&;
	using value_type = char;
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

	// 2021. 5. 11 set의 원소로 사용할 수 있도록 기본 정렬연산자인 < 를 정의
	// 2021. 5. 18 기본 정렬을 길이 오름차순으로 
	bool operator<(const String& rhs)const {
		return num < rhs.num;
	}
	void setCnt(int n) {
		xcnt = n;
	}
	int getCnt() const {
		return xcnt;
	}
private:
	size_t num;							// 확보한 자원의 수
	char* p;							// 확보한 자원의 위치
	static int xcnt;

private:
	friend std::ostream& operator<<(std::ostream&, const String&);

	// 2021. 05. 04.
	friend std::istream& operator>>(std::istream&, String&);

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

	// 2021. 05. 04.
	void set(const std::string& s)
	{
		num = s.size();
		p = new char[num];

		for (int i = 0; i < num; ++i)
		{
			p[i] = s[i];
		}
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

	bool operator==(const String& rhs) const {
		xcnt++;
		if (num != rhs.num)
		{
			return false;
		}

		for (int i = 0; i < num; ++i)
		{
			if (p[i] != rhs.p[i])
			{
				return false;
			}
		}

		return true;
	}
};
int String::xcnt;

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (int i = 0; i < s.num; ++i)
	{
		os << s.p[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, String& s)
{
	std::string str;

	is >> str;
	s.set(str);

	return is;
}

