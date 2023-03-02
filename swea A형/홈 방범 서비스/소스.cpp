#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m;
int map[20][20];

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

int count(int y, int x, int k) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int dy = abs(y - i);
			int dx = abs(x - j);
			if (dy + dx < k)
			{
				if (map[i][j] == 1)
				{
					cnt++;
				}
			}
			else
			{
				continue;
			}
		}
	}
	return cnt;
}

int main()
{
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> m;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}
		int ans = 0;
		int k = 1;
		while (k <= n + n - 1)
		{
			int cost = k * k + (k - 1) * (k - 1);
			int cntmax = -1;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					int home = count(i, j, k);
					if (home > cntmax)
					{
						cntmax = home;
					}
				}
			}
			if (cntmax * m - cost >= 0)
			{
				ans = cntmax;
			}
			k++;
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}