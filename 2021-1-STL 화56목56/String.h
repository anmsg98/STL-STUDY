#include <iostream>
#include <random>
#include <algorithm>

std::mt19937 dre;
std::uniform_int_distribution<> uid{ 'a','z' };
std::uniform_int_distribution<> uidLen{ 1,200 };

// 밑에 줄에 주석을 제거하면 출력메시지 안나옴
// #define 관찰

class String {
public:
	String() :num{ uidLen(dre) }, p{ new char[num] }{

#ifdef 관찰
		std::cout << "String() - ctor" << std::endl;
#endif
		for (int i = 0; i < num; ++i)
			p[i] = uid(dre);
	}

	String(int num) : num{ num }, p{ new char[num] }{
#ifdef 관찰
		std::cout << "String(int)" << std::endl;
#endif
		for (int i = 0; i < num; ++i)
			p[i] = uid(dre);
	}

	~String() {
#ifdef 관찰
		std::cout << "~String() -p: " << (void*)p << std::endl;
#endif
		delete[] p;
	}

	String(const String& other) :num{ other.num }, p{ new char[num] } {
		//cout << "복사";		// switch로 출력 조절
		memcpy(p, other.p, num);
	}

	String& operator=(const String& other) {
		//cout << "할당" << endl;
		if (this != &other) {
			delete[] p;
			num = other.num;
			p = new char[num];
			memcpy(p, other.p, num);
		}

		return *this;
	}

	size_t size() const {
		return num;
	}

	void sortAscending() {
		std::sort(p, p + num);
	};

private:
	int num{};
	char* p{ nullptr };

	friend std::ostream& operator<<(std::ostream&, const String&);
};

std::ostream& operator << (std::ostream& os, const String& s) {
	for (int i = 0; i < s.num; ++i) {
		os << s.p[i];
	}
	return os;
}