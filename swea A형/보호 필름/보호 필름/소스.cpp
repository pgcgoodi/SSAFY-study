#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
int d, w, k;
int film[13][20];
int mini;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

bool check() {
	for (int i = 0; i < w; i++)
	{
		int cnt = 0;
		int temp = film[0][i];
		for (int j = 0; j < d; j++)
		{
			if (temp == film[j][i])
			{
				cnt++;
			}
			else
			{
				temp = film[j][i];
				cnt = 1;
			}
			if (cnt >= k)
			{
				break;
			}
			if (j == d - 1)
			{
				if (cnt < k)
				{
					return false;
				}
			}
		}
	}
	return true;
}

void dfs(int lev, int cnt) {
	if (lev == d)
	{
		if (check() == true)
		{
			if (cnt < mini)
			{
				mini = cnt;
			}
		}
		return;
	}
	int filmcpy[13][20] = { 0, };
	memcpy(filmcpy, film, sizeof(film));
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			if (cnt > mini)
			{
				continue;
			}
			dfs(lev + 1, cnt);
		}
		else if (i == 1)
		{
			if (cnt + 1 > mini)
			{
				continue;
			}
			for (int j = 0; j < w; j++)
			{
				film[lev][j] = 0;
			}
			dfs(lev + 1, cnt + 1);
		}
		else
		{
			if (cnt + 1 > mini)
			{
				continue;
			}
			for (int j = 0; j < w; j++)
			{
				film[lev][j] = 1;
			}
			dfs(lev + 1, cnt + 1);
		}
		memcpy(film, filmcpy, sizeof(film));
	}
}

int main()
{
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> d >> w >> k;
		memset(film, 0, sizeof(film));
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> film[i][j];
			}
		}
		mini = 21e8;
		dfs(0, 0);
		cout << '#' << tc << ' ' << mini << '\n';
	}
	return 0;
}