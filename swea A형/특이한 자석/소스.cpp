#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int k;
int magnet[4][8];

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

void left(int a) {
	rotate(magnet[a], magnet[a] + 1, magnet[a] + 8);
}

void right(int a) {
	rotate(magnet[a], magnet[a] + 7, magnet[a] + 8);
}

void turn(int num, int dir) {
	int check[3] = { 0, };
	for (int i = 0; i < 3; i++)
	{
		if (magnet[i][2] != magnet[i + 1][6])
		{
			check[i] = 1;
		}
	}
	if (dir == 1)
	{
		right(num);
	}
	else
	{
		left(num);
	}
	if (num == 0)
	{
		if (check[0] == 1)
		{
			if (dir == 1)
			{
				left(1);
			}
			else
			{
				right(1);
			}
			if (check[1] == 1)
			{
				if (dir == 1)
				{
					right(2);
				}
				else
				{
					left(2);
				}
				if (check[2] == 1)
				{
					if (dir == 1)
					{
						left(3);
					}
					else
					{
						right(3);
					}
				}
			}
		}
	}
	else if (num == 1)
	{
		if (check[0] == 1)
		{
			if (dir == 1)
			{
				left(0);
			}
			else
			{
				right(0);
			}
		}
		if (check[1] == 1)
		{
			if (dir == 1)
			{
				left(2);
			}
			else
			{
				right(2);
			}
			if (check[2] == 1)
			{
				if (dir == 1)
				{
					right(3);
				}
				else
				{
					left(3);
				}
			}
		}
	}
	else if (num == 2)
	{
		if (check[2] == 1)
		{
			if (dir == 1)
			{
				left(3);
			}
			else
			{
				right(3);
			}
		}
		if (check[1] == 1)
		{
			if (dir == 1)
			{
				left(1);
			}
			else
			{
				right(1);
			}
			if (check[0] == 1)
			{
				if (dir == 1)
				{
					right(0);
				}
				else
				{
					left(0);
				}
			}
		}
	}
	else
	{
		if (check[2] == 1)
		{
			if (dir == 1)
			{
				left(2);
			}
			else
			{
				right(2);
			}
			if (check[1] == 1)
			{
				if (dir == 1)
				{
					right(1);
				}
				else
				{
					left(1);
				}
				if (check[0] == 1)
				{
					if (dir == 1)
					{
						left(0);
					}
					else
					{
						right(0);
					}
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> k;
		memset(magnet, 0, sizeof(magnet));
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> magnet[i][j];
			}
		}
		for (int i = 0; i < k; i++)
		{
			int num, dir;
			cin >> num >> dir;
			num--;
			turn(num, dir);
		}
		int sum = 0;
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				if (magnet[i][0] == 1)
				{
					sum += 1;
				}
			}
			else if (i == 1)
			{
				if (magnet[i][0] == 1)
				{
					sum += 2;
				}
			}
			else if (i == 2)
			{
				if (magnet[i][0] == 1)
				{
					sum += 4;
				}
			}
			else
			{
				if (magnet[i][0] == 1)
				{
					sum += 8;
				}
			}
		}
		cout << '#' << tc << ' ' << sum << '\n';
	}
	return 0;
}