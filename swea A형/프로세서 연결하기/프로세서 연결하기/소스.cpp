#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n;
int map[12][12];
int visited[12][12];
struct node
{
	int y;
	int x;
};
vector<node> st;
int corecnt;
int len;
int maxi;
int mini;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

void dfs(int lev, int core, int line) {
	if (lev == len)
	{
		if (core >= maxi)
		{
			if (core == maxi)
			{
				if (line < mini)
				{
					mini = line;
				}
			}
			else
			{
				maxi = core;
				mini = line;
			}
		}
		return;
	}
	int visitedcpy[12][12] = { 0, };
	memcpy(visitedcpy, visited, sizeof(visited));
	for (int i = 0; i < 5; i++)
	{
		int flag = 0;
		if (i == 0)
		{
			for (int j = 0; j < st[lev].y; j++)
			{
				if (visited[j][st[lev].x] == 1)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				continue;
			}
			for (int j = 0; j < st[lev].y; j++)
			{
				visited[j][st[lev].x] = 1;
			}
			dfs(lev + 1, core + 1, line + st[lev].y);
		}
		else if (i == 1)
		{
			for (int j = st[lev].y + 1; j < n; j++)
			{
				if (visited[j][st[lev].x] == 1)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				continue;
			}
			for (int j = st[lev].y + 1; j < n; j++)
			{
				visited[j][st[lev].x] = 1;
			}
			dfs(lev + 1, core + 1, line + (n - 1 - st[lev].y));
		}
		else if (i == 2)
		{
			for (int j = 0; j < st[lev].x; j++)
			{
				if (visited[st[lev].y][j] == 1)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				continue;
			}
			for (int j = 0; j < st[lev].x; j++)
			{
				visited[st[lev].y][j] = 1;
			}
			dfs(lev + 1, core + 1, line + st[lev].x);
		}
		else if (i == 3)
		{
			for (int j = st[lev].x + 1; j < n; j++)
			{
				if (visited[st[lev].y][j] == 1)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				continue;
			}
			for (int j = st[lev].x + 1; j < n; j++)
			{
				visited[st[lev].y][j] = 1;
			}
			dfs(lev + 1, core + 1, line + (n - st[lev].x - 1));
		}
		else
		{
			dfs(lev + 1, core, line);
		}
		memcpy(visited, visitedcpy, sizeof(visited));
	}
}

int main()
{
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n;
		corecnt = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		st.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)
				{
					visited[i][j] = 1;
					if (i == 0 or j == 0 or i == n - 1 or j == n - 1)
					{
						corecnt++;
					}
					else
					{
						st.push_back({ i, j });
					}
				}
			}
		}
		len = st.size();
		maxi = -21e8;
		mini = 21e8;
		dfs(0, corecnt, 0);
		cout << '#' << tc << ' ' << mini << '\n';
	}
	return 0;
}