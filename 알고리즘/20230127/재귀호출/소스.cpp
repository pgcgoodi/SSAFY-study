/* ǥ���� ���� �� �ִ� �� �� �ּҿ� �ִ�
#include <iostream>

using namespace std;
int arr[4][4] = { 3, 1, 4, -2, 1, 1, -1, 1, 2, 3, 1, 4, 5, 1, 0, -3 };
int maxi = -21e8;
int mini = 21e8;

void func(int lev, int gop) {
	if (lev == 4)
	{
		if (maxi < gop)
		{
			maxi = gop;
		}
		if (mini > gop)
		{
			mini = gop;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		func(lev + 1, gop * arr[lev][i]);
	}
}

int main()
{
	func(0, 1);
	cout << maxi << '\n' << mini;
	return 0;
}*/

/* �̸� �� 3���� ��� ������ ����� ��
#include <iostream>

using namespace std;
char name[10];
char path[3];
int len;

void func(int lev) {
	if (lev == 3)
	{
		cout << path << '\n';
		return;
	}

	for (int i = 0; i < len; i++)
	{
		path[lev] = name[i];
		func(lev + 1);
		path[lev] = 0;
	}
}

int main()
{
	cin >> name;
	for (int i = 0; i < 10; i++)
	{
		if (name[i] == NULL)
		{
			len = i;
			break;
		}
	}
	func(0);
	return 0;
}*/

/* �ֻ��� 3���� ������ �ߺ����� ������ ����� ��
#include <iostream>

using namespace std;
char path[7];
int dat[7];

void func(int lev) {
	if (lev == 3)
	{
		cout << path << '\n';
		return;
	}

	for (int i = 1; i < 6; i++)
	{
		if (dat[i] == 1)
		{
			continue;
		}
		dat[i] = 1;
		path[lev] = '0' + i;
		func(lev + 1);
		path[lev] = 0;
		dat[i] = 0;
	}
}

int main()
{
	func(0);
	return 0;
}*/

/* ī�� �� 4���� �ߺ����� �̱�
#include <iostream>

using namespace std;
char card[10];
int len;
char path[10];
int dat[100];

void func(int lev) {
	if (lev == 4)
	{
		cout << path << '\n';
		return;
	}

	for (int i = 0; i < len; i++)
	{
		if (dat[card[i]] == 1)
		{
			continue;
		}
		path[lev] = card[i];
		dat[card[i]] = 1;
		func(lev + 1);
		dat[card[i]] = 0;
	}
}

int main()
{
	cin >> card;
	for (int i = 0; i < 10; i++)
	{
		if (card[i] == NULL)
		{
			len = i;
			break;
		}
	}

	func(0);
	return 0;
}*/

/* ����
#include <iostream>

using namespace std;
char path[10];


void func(int lev, int start) {
	if (lev == 2)
	{
		cout << path << '\n';
		return;
	}

	for (int i = start; i <= 6; i++)
	{
		path[lev] = '0' + i;
		func(lev + 1, i);
		path[lev] = 0;
	}
}

int main()
{
	func(0, 1);
	return 0;
}*/

/* �ߺ� ����
#include <iostream>

using namespace std;
char path[10];

void func(int lev) {
	if (lev == 3)
	{
		cout << path << '\n';
		return;
	}

	for (int i = 1; i <= 6; i++)
	{
		path[lev] = '0' + i;
		func(lev + 1);
	}
}

int main()
{
	func(0);
	return 0;
}*/