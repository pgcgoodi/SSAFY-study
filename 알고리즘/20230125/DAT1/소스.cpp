// 문자열 중 각 알파벳이 몇 개 인가?
// DAT: Direct Access Table -> 배열의 index에 의미를 부여
// int DAT[]; // index : 문자, value : 해당 문제가 몇 개?

#include <iostream>

using namespace std;

int main()
{
	char temp[100];
	cin >> temp;

	int DAT[256] = { 0, }; // 기본적인 문자(Ascii code) : 128가지, char라는 data가 표현 가능한 종류 = 256가지
	// index : 문자
	// value : 해당 문자가 몇 개?
	for (int i = 0; i < temp[i]; i++)
	{
		char now = temp[i]	;
		DAT[now]++; // now라는 문자가 1개 추가
	}

	return 0;
}