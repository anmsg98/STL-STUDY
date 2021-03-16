//-----------------------------------------------------------------
// 2021. 1학기 STL 화56 목56  - 3월 16일 화요일            (3주 1일)
//
// 호출 가능한 타입 - callable type
//
// 앞으로 사용할 관찰용 class(자원을 확보하는) 만들어 두기
//-----------------------------------------------------------------

#include <iostream>
#include <thread>
#include "save.h"
using namespace std;

// 쿠키런
// 왼쪽버튼 - 점프, 오른쪽버튼 - 슬라이드
//
// 설정에 가서 버튼을 바꿨다.
// 프로그램 구현은 어떻게 했을까?

void jump() {
	cout << "점프" << endl;
}
void slide() {
	cout << "슬라이드" << endl;
}
void (*left_function)() = jump;

void left()
{
	left_function();
}

int main()
{
	// 10번에 한번은 기능을 바꾼다.

	int cnt{};
	while (true) {
		left();
		this_thread::sleep_for(500ms);
		++cnt;
		if (cnt == 10) {
			left_function = slide;
		}
	}
	
	//save("소스.cpp");
}



