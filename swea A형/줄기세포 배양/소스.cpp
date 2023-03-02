#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n, m, k;
int map[360][360];
int mapcpy[360][360];
int visited[360][360];
struct node
{
	int y;
	int x;
	int value;
};
struct cmp {
	bool operator()(node a, node b) {
		if (a.value > b.value)
		{
			return false;
		}
		if (a.value < b.value)
		{
			return true;
		}
		return false;
	}
};
priority_queue<node, vector<node>, cmp> pq;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

void bfs() {
	while (!pq.empty())
	{
		node now = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int toy = now.y + dy[i];
			int tox = now.x + dx[i];
			if (visited[toy][tox] == 1)
			{
				continue;
			}
			visited[toy][tox] = 1;
			map[toy][tox] = now.value;
			mapcpy[toy][tox] = now.value;
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
		cin >> n >> m >> k;
		memset(map, 0, sizeof(map));
		memset(mapcpy, 0, sizeof(mapcpy));
		memset(visited, 0, sizeof(visited));
		for (int i = 150; i < 150 + n; i++)
		{
			for (int j = 150; j < 150 + m; j++)
			{
				cin >> map[i][j];
				map[i][j] = map[i][j] * 2;
			}
		}
		for (int i = 150; i < 150 + n; i++)
		{
			for (int j = 150; j < 150 + m; j++)
			{
				if (map[i][j] != 0)
				{
					mapcpy[i][j] = map[i][j];
					visited[i][j] = 1;
				}
			}
		}
		while (k > 0)
		{
			for (int i = 0; i < 360; i++)
			{
				for (int j = 0; j < 360; j++)
				{
					if (mapcpy[i][j] != 0)
					{
						if (mapcpy[i][j] == map[i][j] / 2)
						{
							pq.push({ i, j, map[i][j] });
						}
						mapcpy[i][j]--;
					}
				}
			}
			bfs();
			k--;
		}
		int cnt = 0;
		for (int i = 0; i < 360; i++)
		{
			for (int j = 0; j < 360; j++)
			{
				if (mapcpy[i][j] != 0)
				{
					cnt++;
				}
			}
		}
		cout << '#' << tc << ' ' << cnt << '\n';
	}
	return 0;
}