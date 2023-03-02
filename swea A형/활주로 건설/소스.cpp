#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, x;
int map[20][20];
struct node
{
	int h;
	int used;
};
vector<node> v[40];

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

bool check(int idx, int lev) {
	if (lev == n - 1)
	{
		return true;
	}
	if (v[idx][lev + 1].h == v[idx][lev].h)
	{
		check(idx, lev + 1);
	}
	else if (v[idx][lev + 1].h - v[idx][lev].h > 2 or v[idx][lev + 1].h - v[idx][lev].h < -2)
	{
		return false;
	}
	else if (v[idx][lev + 1].h - v[idx][lev].h == 1)
	{
		if (lev - x + 1 < 0)
		{
			return false;
		}
		for (int i = lev - 1; i >= lev - x + 1; i--)
		{
			if (v[idx][i].h != v[idx][lev].h)
			{
				return false;
			}
			if (v[idx][i].used != 0)
			{
				return false;
			}
		}
		check(idx, lev + 1);
	}
	else if (v[idx][lev + 1].h - v[idx][lev].h == -1)
	{
		if (lev + x >= n)
		{
			return false;
		}
		for (int i = lev + 2; i <= lev + x; i++)
		{
			if (v[idx][i].h != v[idx][lev + 1].h)
			{
				return false;
			}
		}
		for (int i = lev + 1; i <= lev + x; i++)
		{
			v[idx][i].used = 1;
		}
		check(idx, lev + x);
	}
}

int main()
{
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> x;
		for (int i = 0; i < 40; i++)
		{
			v[i].clear();
		}
		memset(map, 0, sizeof(int) * 20 * 20);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				v[i].push_back({ map[i][j], 0 });
				v[j + n].push_back({ map[i][j], 0 });
			}
		}
		int cnt = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			bool temp = false;
			temp = check(i, 0);
			if (temp == true)
			{
				cnt++;
			}
		}
		cout << '#' << tc << ' ' << cnt << '\n';
	}
	return 0;
}