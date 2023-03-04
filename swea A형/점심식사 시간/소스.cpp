#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
int map[10][10];
struct node
{
	int y;
	int x;
	int dis1;
	int dis2;
};
node people[10];
node stair[2];
int peoplen;
int mini;
vector<int> v;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

int calc() {
	vector<int> stair1;
	vector<int> stair2;
	for (int i = 0; i < peoplen; i++)
	{
		if (v[i] == 0)
		{
			stair1.push_back({ people[i].dis1 });
		}
		else
		{
			stair2.push_back({ people[i].dis2 });
		}
	}
	sort(stair1.begin(), stair1.end());
	sort(stair2.begin(), stair2.end());
	for (int i = 0; i < stair1.size(); i++)
	{
		if (i - 3 < 0)
		{
			continue;
		}
		if (stair1[i] < stair1[i - 3] + stair[0].dis1)
		{
			stair1[i] = stair1[i - 3] + stair[0].dis1;
		}
	}
	for (int i = 0; i < stair2.size(); i++)
	{
		if (i - 3 < 0)
		{
			continue;
		}
		if (stair2[i] < stair2[i - 3] + stair[1].dis1)
		{
			stair2[i] = stair2[i - 3] + stair[1].dis1;
		}
	}
	int first = 0;
	int second = 0;
	if (stair1.size() != 0)
	{
		first = stair1.back() + stair[0].dis1 + 1;
	}
	if (stair2.size() != 0)
	{
		second = stair2.back() + stair[1].dis1 + 1;
	}
	return max(first, second);
}

void dfs(int lev) {
	if (lev == peoplen)
	{
		int temp = calc();
		if (mini > temp)
		{
			mini = temp;
		}
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		v.push_back(i);
		dfs(lev + 1);
		v.pop_back();
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
		memset(map, 0, sizeof(map));
		memset(people, 0, sizeof(people));
		memset(stair, 0, sizeof(stair));
		v.clear();
		int a = 0;
		int b = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)
				{
					people[a].y = i;
					people[a].x = j;
					a++;
				}
				else if (map[i][j] > 1)
				{
					stair[b].y = i;
					stair[b].x = j;
					stair[b].dis1 = map[i][j];
					b++;
				}
			}
		}
		peoplen = a;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int dy = abs(people[i].y - stair[j].y);
				int dx = abs(people[i].x - stair[j].x);
				if (j == 0)
				{
					people[i].dis1 = dy + dx;
				}
				else
				{
					people[i].dis2 = dy + dx;
				}
			}
		}
		mini = 21e8;
		dfs(0);
		cout << '#' << tc << ' ' << mini << '\n';
	}
	return 0;
}