#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int n;
int map[20][20];
int visited[20][20];
int dy[4] = { 1,1,-1,-1 };
int dx[4] = { 1,-1,-1,1 };
int dat[101];
int cnt;
int ans;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

void dfs(int y, int x, int dir, int ey, int ex) {
	if (y == ey and x == ex)
	{
		if (ans < cnt)
		{
			ans = cnt;
		}
		return;
	}
	if (y < 0 or x < 0 or y > n - 1 or x > n - 1)
	{
		return;
	}
	if (dat[map[y][x]] > 0)
	{
		return;
	}
	if (visited[y][x] == 1)
	{
		return;
	}
	visited[y][x] = 1;
	dat[map[y][x]] = 1;
	cnt++;
	dfs(y + dy[dir], x + dx[dir], dir, ey, ex);
	if (dir < 3)
	{
		dir++;
		dfs(y + dy[dir], x + dx[dir], dir, ey, ex);
		dir--;
	}
	visited[y][x] = 0;
	dat[map[y][x]] = 0;
	cnt--;
}

int main()
{
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}
		ans = -1;
		for (int i = 0; i <= n - 3; i++)
		{
			for (int j = 1; j <= n - 2; j++)
			{
				cnt = 1;
				visited[i][j] = 1;
				dat[map[i][j]] = 1;
				dfs(i + 1, j + 1, 0, i, j);
				visited[i][j] = 0;
				dat[map[i][j]] = 0;
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}