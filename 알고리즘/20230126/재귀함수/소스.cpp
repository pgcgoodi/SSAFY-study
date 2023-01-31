#include <iostream>

using namespace std;

/* 재귀 쓰는 이유 : for문으로 구현 할 수 없는 것 구현 가능
ex) 입력한 숫자만큼 for문 반복 시키는 것 */
/* 무한 재귀 호출 막는 법
1. 전역 변수
2. 매개 변수 */


void bbq(int x) {
	if (x == 2)
	{
		return;
	}

	bbq(x+1);

	int d = 1;
}

int main()
{
	bbq(0);
	return 0;
}