#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m;
int map[30][30];
int visited[30][30];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
struct node1
{
	int y;
	int x;
};
struct node2
{
	int y1;
	int x1;
	int y2;
	int x2;
	int cost;
	int sum;
};
vector<node2> tunnel;
queue<node1> q;
bool cmp(node2 a, node2 b) {
	return a.sum < b.sum;
}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

void bfs(int y, int x) {
	q.push({ y, x });
	while (!q.empty())
	{
		node1 now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int toy = now.y + dy[i];
			int tox = now.x + dx[i];
			if (tox < 0 or toy < 0 or toy >= n or tox >= n)
			{
				continue;
			}
			if (visited[toy][tox] != 0)
			{
				if (map[toy][tox] < map[now.y][now.x])
				{
					if (visited[toy][tox] > visited[now.y][now.x])
					{
						visited[toy][tox] = visited[now.y][now.x];
						q.push({ toy, tox });
						continue;
					}
					else
					{
						continue;
					}
				}
				else if (map[toy][tox] == map[now.y][now.x])
				{
					if (visited[toy][tox] > visited[now.y][now.x] + 1)
					{
						visited[toy][tox] = visited[now.y][now.x] + 1;
						q.push({ toy, tox });
						continue;
					}
					else
					{
						continue;
					}
				}
				else
				{
					int a = map[toy][tox] - map[now.y][now.x];
					if (visited[toy][tox] > visited[now.y][now.x] + 2 * a)
					{
						visited[toy][tox] = visited[now.y][now.x] + 2 * a;
						q.push({ toy, tox });
						continue;
					}
					else
					{
						continue;
					}
				}
			}
			if (map[toy][tox] < map[now.y][now.x])
			{
				visited[toy][tox] = visited[now.y][now.x];
			}
			else if (map[toy][tox] == map[now.y][now.x])
			{
				visited[toy][tox] = visited[now.y][now.x] + 1;
			}
			else
			{
				int a = map[toy][tox] - map[now.y][now.x];
				visited[toy][tox] = visited[now.y][now.x] + 2 * a;
			}
			q.push({ toy, tox });
		}
	}
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
		memset(visited, 0, sizeof(visited));
		tunnel.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < m; i++)
		{
			int a, b, c, d, e;
			cin >> a >> b >> c >> d >> e;
			a--;
			b--;
			c--;
			d--;
			int f = a + b + c + d;
			tunnel.push_back({ a, b, c, d, e, f });
		}
		sort(tunnel.begin(), tunnel.end(), cmp);
		visited[0][0] = 1;
		bfs(0, 0);
		for (int i = 0; i < m; i++)
		{
			if (visited[tunnel[i].y1][tunnel[i].x1] == visited[tunnel[i].y2][tunnel[i].x2])
			{
				continue;
			}
			else if (visited[tunnel[i].y1][tunnel[i].x1] > visited[tunnel[i].y2][tunnel[i].x2])
			{
				if (visited[tunnel[i].y1][tunnel[i].x1] > visited[tunnel[i].y2][tunnel[i].x2] + tunnel[i].cost)
				{
					visited[tunnel[i].y1][tunnel[i].x1] = visited[tunnel[i].y2][tunnel[i].x2] + tunnel[i].cost;
					bfs(tunnel[i].y1, tunnel[i].x1);
				}
				else
				{
					continue;
				}
			}
			else
			{
				if (visited[tunnel[i].y2][tunnel[i].x2] > visited[tunnel[i].y1][tunnel[i].x1] + tunnel[i].cost)
				{
					visited[tunnel[i].y2][tunnel[i].x2] = visited[tunnel[i].y1][tunnel[i].x1] + tunnel[i].cost;
					bfs(tunnel[i].y2, tunnel[i].x2);
				}
				else
				{
					continue;
				}
			}
		}
		cout << '#' << tc << ' ' << visited[n - 1][n - 1] - 1 << '\n';
	}
	return 0;
}