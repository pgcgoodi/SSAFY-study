#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;


int main()
{
	/* ���ڿ� ����
	int len = 0;
	char str[100] = "string";
	cout << strlen(str);

	string s = "string";
	cout << s.length();*/

	/* ���ڿ� ��
	char a[100] = "abc";
	char b[100] = "bcd";
	// strcmp(a, b) : ������ 0, �ٸ��� -1(a�� b���� ���� ������ ��) �Ǵ� 1(a�� b���� ���������� ��)
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

	/* ���ڿ� ���̱�
	char a[100] = "str";
	char b[100] = "ing";

	for (int i = 0; i < strlen(b); i++)
	{
		a[i + strlen(a)] = b[i];
	}
	// ���ڿ��� ������ֱ� ���� �������� NULL �߰�
	a[strlen(a) + strlen(b)] = '\0';
	cout << a;

	// strcat(a, b) : b�� a�� ���յ�
	strcat(a, b);
	cout << a; */

	// string class
	// ������ ��밡��(+ : ����)

	/* ���ڿ� ��ü ����
	char a[100] = "string";
	char b[100];
	// strcpy(a, b) : b�� a�� ����
	strcpy(b, a);
	cout << b;

	string c = "string";
	string d;
	d = c;
	cout << d;*/

	/* ���ڿ� �κ� ����
	char a[100] = "string";
	char b[100];
	int st, en;
	cin >> st >> en;
	// strncpy(���� ���� �迭, ���� ���� ��ġ, ���� ���� ũ��)
	// �迭�� �̸��� �ش� �迭�� �ּҸ� ��Ÿ��
	strncpy(b, a + st, en - st);
	b[en - st] = '\0';
	cout << b;

	string c = "string";
	string d;
	// substr(���� ��ġ, ���� ũ��)
	int st, en;
	cin >> st >> en;
	d = c.substr(st, en - st);
	cout << d;*/

	/* �κ� ���ڿ� ��ġ ã��
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

	// strstr(A, B) : pointer�� return
	// -> ã������ �ϴ� ���ڿ��� A�� �����Ѵٸ�, ó�� ã�� ��ġ�� �������� ���� ���ڿ� ��ü�� ��ȯ
	cout << strstr(a, b);

	// a.find(b) : a���� b ���ڿ��� �ִ� index�� ��ȯ
	// ã�� �� ���ٸ� string::npos �Ǵ� -1 return
	string c = "string";
	string d = "ring";
	cout << c.find(d); */

	return 0;
}