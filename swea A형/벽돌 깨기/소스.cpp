#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int n, w, h;
int map[15][12];
int mini;
struct node
{
	int y;
	int x;
	int value;
};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

void boom(int line) {
	int idx = -1;
	for (int i = 0; i < h; i++)
	{
		if (map[i][line] != 0)
		{
			idx = i;
			break;
		}
	}
	if (idx == -1)
	{
		return;
	}
	queue<node> q;
	q.push({ idx, line, map[idx][line] });
	while (!q.empty())
	{
		node now = q.front();
		q.pop();
		if (now.value <= 1)
		{
			map[now.y][now.x] = 0;
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j < now.value; j++)
			{
				int toy = now.y + dy[i] * j;
				int tox = now.x + dx[i] * j;
				if (toy < 0 or tox < 0 or toy >= h or tox >= w)
				{
					continue;
				}
				if (map[toy][tox] <= 1)
				{
					map[now.y][now.x] = 0;
					map[toy][tox] = 0;
					continue;
				}
				else
				{
					map[now.y][now.x] = 0;
					q.push({ toy, tox, map[toy][tox] });
				}
			}
		}
	}
}

void down() {
	for (int i = 0; i < w; i++)
	{
		int t = h - 1;
		for (int j = h - 1; j >= 0; j--)
		{
			if (map[j][i] != 0)
			{
				int temp = map[j][i];
				map[j][i] = 0;
				map[t--][i] = temp;
			}
		}
	}
}

void dfs(int lev) {
	if (lev == n)
	{
		int cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] != 0)
				{
					cnt++;
				}
			}
		}
		if (mini > cnt)
		{
			mini = cnt;
		}
		return;
	}
	int backup[15][12] = { 0, };
	memcpy(backup, map, sizeof(map));
	for (int i = 0; i < w; i++)
	{
		boom(i);
		down();
		dfs(lev + 1);
		memcpy(map, backup, sizeof(map));
	}
}

int main()
{
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> w >> h;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}
		mini = 21e8;
		dfs(0);
		cout << '#' << tc << ' ' << mini << '\n';
	}
	return 0;
}