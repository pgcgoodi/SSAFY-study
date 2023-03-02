#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n;
int map[102][102];
struct node
{
	int y;
	int x;
	int d;
};
vector<node> st;
vector<node> worm[15];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int path(int sty, int stx, int dir) {
	queue<node> q;
	q.push({ sty, stx, dir });
	int cnt = 0;
	while (!q.empty())
	{
		node now = q.front();
		q.pop();
		int toy = now.y + dy[now.d];
		int tox = now.x + dx[now.d];
		int tod = now.d;
		if (map[toy][tox] == -1)
		{
			return cnt;
		}
		if (toy == sty and tox == stx)
		{
			return cnt;
		}
		if (map[toy][tox] == 1)
		{
			if (now.d == 0 or now.d == 3)
			{
				return cnt * 2 + 1;
			}
			else if (now.d == 1)
			{
				tod = 3;
			}
			else if (now.d == 2)
			{
				tod = 0;
			}
			cnt++;
			q.push({ toy, tox, tod });
		}
		else if (map[toy][tox] == 2)
		{
			if (now.d == 0)
			{
				tod = 3;
			}
			else if (now.d == 1 or now.d == 3)
			{
				return cnt * 2 + 1;
			}
			else if (now.d == 2)
			{
				tod = 1;
			}
			cnt++;
			q.push({ toy, tox, tod });
		}
		else if (map[toy][tox] == 3)
		{
			if (now.d == 0)
			{
				tod = 2;
			}
			else if (now.d == 1 or now.d == 2)
			{
				return cnt * 2 + 1;
			}
			else
			{
				tod = 1;
			}
			cnt++;
			q.push({ toy, tox, tod });
		}
		else if (map[toy][tox] == 4)
		{
			if (now.d == 0 or now.d == 2)
			{
				return cnt * 2 + 1;
			}
			else if (now.d == 1)
			{
				tod = 2;
			}
			else
			{
				tod = 0;
			}
			cnt++;
			q.push({ toy, tox, tod });
		}
		else if (map[toy][tox] == 5)
		{
			return cnt * 2 + 1;
		}
		else if (map[toy][tox] >= 6 and map[toy][tox] <= 10)
		{
			int a = map[toy][tox];
			for (int i = 0; i < worm[a].size(); i++)
			{
				if (worm[a][i].y == toy and worm[a][i].x == tox)
				{
					continue;
				}
				q.push({ worm[a][i].y, worm[a][i].x, tod });
			}
		}
		else
		{
			q.push({ toy, tox, tod });
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n;
		memset(map, 0, sizeof(int) * 102 * 102);
		st.clear();
		for (int i = 0; i < 15; i++)
		{
			worm[i].clear();
		}
		for (int i = 0; i < n + 2; i++)
		{
			map[0][i] = 5;
		}
		for (int i = 1; i <= n; i++)
		{
			map[i][0] = 5;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 0)
				{
					st.push_back({ i, j });
				}
				else if (map[i][j] >= 6 and map[i][j] <= 10)
				{
					int a = map[i][j];
					worm[a].push_back({ i, j });
				}
			}
		}
		for (int i = 0; i <= n + 1; i++)
		{
			map[n + 1][i] = 5;
		}
		for (int i = 0; i < n + 2; i++)
		{
			map[i][n + 1] = 5;
		}
		int ans = -21e8;
		int visited[102][102][4] = { 0, };
		for (int i = 0; i < st.size(); i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (visited[st[i].y][st[i].x][j] == 1)
				{
					continue;
				}
				visited[st[i].y][st[i].x][j] = 1;
				int a = 1;
				while (1)
				{
					if (map[st[i].y][st[i].x + a] != 0)
					{
						break;
					}
					visited[st[i].y][st[i].x][2] = 1;
					visited[st[i].y][st[i].x][3] = 1;
					a++;
				}
				int b = 1;
				while (1)
				{
					if (map[st[i].y + b][st[i].x] != 0)
					{
						break;
					}
					visited[st[i].y][st[i].x][0] = 1;
					visited[st[i].y][st[i].x][1] = 1;
					b++;
				}
				int result = path(st[i].y, st[i].x, j);
				if (ans < result)
				{
					ans = result;
				}
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}