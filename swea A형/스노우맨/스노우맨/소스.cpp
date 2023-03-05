#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n, m;
int map[50][50];
int visited[50][50];
int sy, sx, ey, ex;
int limit;
struct node
{
	int y;
	int x;
};
int dy[2] = { -1, 1 };

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

void bfs(int a) {
	queue<node> q;
	for (int i = 0; i < m; i++)
	{	
		q.push({ n - 1, i });
	}
	while (!q.empty())
	{
		node now = q.front();
		q.pop();
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= a; j++)
			{
				int toy = now.y + j * dy[i];
				int tox = now.x;
				if (toy < 0 or toy >= n)
				{
					continue;
				}
				if (map[toy][tox] == 0)
				{
					continue;
				}
				if (visited[toy][tox] != 0)
				{
					continue;
				}
				while (map[toy][tox] != 0)
				{
					visited[toy][tox] = 1;
					q.push({ toy, tox });
					tox--;
				}
				tox = now.x;
				while (map[toy][tox] != 0)
				{
					visited[toy][tox] = 1;
					q.push({ toy, tox });
					tox++;
				}
			}
		}
	}
}

int main()
{
	init();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				sy = i;
				sx = j;
			}
			else if (map[i][j] == 3)
			{
				ey = i;
				ex = j;
			}
		}
	}
	limit = 1;
	while (1)
	{
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < m; i++)
		{
			visited[n - 1][i] = 1;
		}
		bfs(limit);
		if (visited[ey][ex] != 0)
		{
			break;
		}
		limit++;
	}
	cout << limit;
	return 0;
}