//-------------------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 5월 11일 화요일            (11주 1일)
//
// Sequence ~
// Associative Container - set(281쪽) / map	key/value
// Unordered Associative ~
//
// map - pair<key, value>
//		연관배열로 사용한다. (통계처리에 유용)
//-------------------------------------------------------------------------
#include <iostream>
#include <map>		// key/value pair이고 key는 const
#include <string>
#include <vector>
#include "save.h"
#include "String.h"
using namespace std;

// 그룹이름을 입력하면 멤버를 알려주는 맵을 만든다.

int main()
{
	map<string, vector<string>> group;
	group.insert(pair<string, vector<string>>{"Itzy", { "유나","예지" }});
	group["펄시스터즈"] = { "배인순", "배인숙" };
	group["이달의소녀"] = { "츄", "올리비아 혜" };
	group["게임"] = { "쿠키런", "철권7" };
	group["코요태"] = { "김종민", "빽가", "신지" };

	// 그룹이름을 입력하면 멤버를 출력하는 프로그램
	// (그룹이름이 없으면 멤버를 입력받아 등록할 수도 있다.)
	
	while (true) {
		cout << "찾을 그룹 이름을 입력하세요: ";
		string groupName;
		cin >> groupName;

		auto p = group.find(groupName);
		if (p == group.end()) {
			cout << groupName << "은 등록된 그룹이 아닙니다." << endl;
			continue;
		}
		cout << "그룹 " << p->first << "의 멤버: ";
		for (const string& name : (p->second))
			cout << name << " ";
		cout << endl;
	}
	//save("소스.cpp");
}