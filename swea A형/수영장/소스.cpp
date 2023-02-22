#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;
int cost[4];
int plan[15];
int mini;

void dfs(int now, int sum) {
	if (now >= 12)
	{
		if (mini > sum)
		{
			mini = sum;
		}
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (plan[now] == 0)
		{
			dfs(now + 1, sum);
		}
		if (i == 0)
		{
			int temp = plan[now] * cost[i];
			dfs(now + 1, sum + temp);
		}
		if (i == 1)
		{
			int temp = cost[i];
			dfs(now + 1, sum + temp);
		}
		if (i == 2)
		{
			int temp = cost[i];
			dfs(now + 3, sum + temp);
		}
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		for (int i = 0; i < 4; i++)
		{
			cin >> cost[i];
		}
		for (int i = 0; i < 12; i++)
		{
			cin >> plan[i];
		}
		mini = cost[3];
		dfs(0, 0);
		cout << '#' << tc << ' ' << mini << '\n';
	}
	return 0;
}