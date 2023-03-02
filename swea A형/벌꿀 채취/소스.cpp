#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m, c;
int map[10][10];
int temp;
int visited[5];

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

void dfs(int y, int x, int cnt, int sum, int price) {
	if (sum > c)
	{
		return;
	}
	if (temp < price)
	{
		temp = price;
	}
	if (cnt == m)
	{
		return;
	}
	for (int i = 0; i < m; i++)
	{
		if (visited[i] == 1)
		{
			continue;
		}
		visited[i] = 1;
		dfs(y, x, cnt + 1, sum + map[y][x + i], price + map[y][x + i] * map[y][x + i]);
		visited[i] = 0;
	}
}

int main()
{
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> m >> c;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}
		int dat[10][10] = { 0, };
		int maxi = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= n - m; j++)
			{
				if (i == n - 1 and j > n - 2 * m)
				{
					break;
				}
				int l = j + m;
				for (int k = i; k < n; k++, l = 0)
				{
					for (; l <= n - m; l++)
					{
						int suma, sumb;
						temp = 0;
						if (dat[i][j] != 0)
						{
							suma = dat[i][j];
						}
						else
						{
							dfs(i, j, 0, 0, 0);
							suma = temp;
							dat[i][j] = temp;
						}
						temp = 0;
						memset(visited, 0, sizeof(visited));
						if (dat[k][l] != 0)
						{
							sumb = dat[k][l];
						}
						else
						{
							dfs(k, l, 0, 0, 0);
							sumb = temp;
							dat[k][l] = temp;
						}
						if (maxi < suma + sumb)
						{
							maxi = suma + sumb;
						}
					}
				}
			}
		}
		cout << '#' << tc << ' ' << maxi << '\n';
	}
	return 0;
}