#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n, m;
int my, mx, et;
int map[50][50];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int pipe[7][4] =
{
	{1,1,1,1},
	{1,0,1,0},
	{0,1,0,1},
	{1,1,0,0},
	{0,1,1,0},
	{0,0,1,1},
	{1,0,0,1}
};
struct node
{
	int y;
	int x;
};

int bfs() {
	queue<node> q;
	q.push({ my, mx });
	int visited[50][50] = { 0, };
	visited[my][mx] = 1;
	int cnt = 1;
	while (et > 1)
	{
		et--;
		int nowsize = q.size();
		for (int i = 0; i < nowsize; i++)
		{
			node now = q.front();
			q.pop();
			int a = map[now.y][now.x];
			for (int j = 0; j < 4; j++)
			{
				int toy = now.y + dy[j];
				int tox = now.x + dx[j];
				int b = map[toy][tox];
				if (toy < 0 or tox < 0 or toy >= n or tox >= m)
				{
					continue;
				}
				if (b == 0)
				{
					continue;
				}
				if (visited[toy][tox] == 1)
				{
					continue;
				}
				if (pipe[a - 1][j] == 0)
				{
					continue;
				}
				int bdir = -1;
				if (j > 1)
				{
					bdir = j - 2;
				}
				else
				{
					bdir = j + 2;
				}
				if (pipe[b - 1][bdir] == 0)
				{
					continue;
				}
				visited[toy][tox] = 1;
				cnt++;
				q.push({ toy, tox });
			}
		}
	}
	return cnt;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> m >> my >> mx >> et;
		memset(map, 0, sizeof(int) * 50 * 50);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
			}
		}
		int ans = bfs();
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}