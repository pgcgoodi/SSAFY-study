#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int n, k;
int map[8][8];
int visited[8][8];
struct node
{
	int y;
	int x;
	int chance;
	int len;
};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int ans;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

void dfs(int y, int x, int a, int b) {
	if (b > ans)
	{
		ans = b;
	}
	for (int i = 0; i < 4; i++)
	{
		int toy = y + dy[i];
		int tox = x + dx[i];
		if (toy < 0 or tox < 0 or toy >= n or tox >= n)
		{
			continue;
		}
		if (visited[toy][tox] == 1)
		{
			continue;
		}
		if (map[toy][tox] >= map[y][x])
		{
			if (a == 1)
			{
				for (int i = 1; i <= k; i++)
				{
					int temp = map[toy][tox];
					int newm = map[toy][tox] - i;
					if (newm < map[y][x])
					{
						visited[toy][tox] = 1;
						map[toy][tox] = newm;
						dfs(toy, tox, a - 1, b + 1);
						map[toy][tox] = temp;
						visited[toy][tox] = 0;
					}
				}
			}
		}
		else
		{
			visited[toy][tox] = 1;
			dfs(toy, tox, a, b + 1);
			visited[toy][tox] = 0;
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
		cin >> n >> k;
		memset(visited, 0, sizeof(int) * 8 * 8);
		memset(map, 0, sizeof(int) * 8 * 8);
		int maxi = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] > maxi)
				{
					maxi = map[i][j];
				}
			}
		}
		vector<node> st;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] == maxi)
				{
					st.push_back({ i, j, 1, 1 });
				}
			}
		}
		ans = -1;
		for (int i = 0; i < st.size(); i++)
		{
			visited[st[i].y][st[i].x] = 1;
			dfs(st[i].y, st[i].x, st[i].chance, st[i].len);
			visited[st[i].y][st[i].x] = 0;
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}