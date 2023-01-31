#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;


int main()
{
	/* 문자열 길이
	int len = 0;
	char str[100] = "string";
	cout << strlen(str);

	string s = "string";
	cout << s.length();*/

	/* 문자열 비교
	char a[100] = "abc";
	char b[100] = "bcd";
	// strcmp(a, b) : 같으면 0, 다르면 -1(a가 b보다 사전 순으로 앞) 또는 1(a가 b보다 사전순으로 뒤)
	if (strcmp(a, b) == 0)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}

	string c = "abc";
	string d = "bcd";
	if (c == d)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}*/

	/* 문자열 붙이기
	char a[100] = "str";
	char b[100] = "ing";

	for (int i = 0; i < strlen(b); i++)
	{
		a[i + strlen(a)] = b[i];
	}
	// 문자열로 만들어주기 위해 마지막에 NULL 추가
	a[strlen(a) + strlen(b)] = '\0';
	cout << a;

	// strcat(a, b) : b가 a에 결합됨
	strcat(a, b);
	cout << a; */

	// string class
	// 연산자 사용가능(+ : 결합)

	/* 문자열 전체 복사
	char a[100] = "string";
	char b[100];
	// strcpy(a, b) : b를 a에 복사
	strcpy(b, a);
	cout << b;

	string c = "string";
	string d;
	d = c;
	cout << d;*/

	/* 문자열 부분 복사
	char a[100] = "string";
	char b[100];
	int st, en;
	cin >> st >> en;
	// strncpy(복사 저장 배열, 복사 시작 위치, 복사 구간 크기)
	// 배열의 이름은 해당 배열의 주소를 나타냄
	strncpy(b, a + st, en - st);
	b[en - st] = '\0';
	cout << b;

	string c = "string";
	string d;
	// substr(시작 위치, 구간 크기)
	int st, en;
	cin >> st >> en;
	d = c.substr(st, en - st);
	cout << d;*/

	/* 부분 문자열 위치 찾기
	char a[100] = "string";
	char b[100];
	cin >> b;
	int index = 0;
	int cnt = 0;
	for (int i = 0; i < strlen(a); i++)
	{
		for (int j = 0; j < strlen(b); j++)
		{
			if (a[i + j] == b[j])
			{
				cnt++;
			}
		}
		if (cnt = strlen(b))
		{
			cout << i;
			return 0;
		}
	}

	// strstr(A, B) : pointer를 return
	// -> 찾으려고 하는 문자열이 A에 존재한다면, 처음 찾은 위치를 기준으로 남은 문자열 전체를 반환
	cout << strstr(a, b);

	// a.find(b) : a에서 b 문자열이 있는 index를 반환
	// 찾을 수 없다면 string::npos 또는 -1 return
	string c = "string";
	string d = "ring";
	cout << c.find(d); */

	return 0;
}