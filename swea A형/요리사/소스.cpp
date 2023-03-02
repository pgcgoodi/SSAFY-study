#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[16][16];
int mini;
int sum1, sum2;
int visited[16];
vector<int> v;
vector<int> v1;

void dfs(int lev) {
	if (lev == n / 2 - 1)
	{
		for (int i = 0; i < v.size() - 1; i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				sum1 += arr[v[i]][v[j]];
				sum1 += arr[v[j]][v[i]];
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == 0)
			{
				v1.push_back(i);
			}
		}
		for (int i = 0; i < v1.size() - 1; i++)
		{
			for (int j = i + 1; j < v1.size(); j++)
			{
				sum2 += arr[v1[i]][v1[j]];
				sum2 += arr[v1[j]][v1[i]];
			}
		}
		int result = sum1 - sum2;
		if (result < 0)
		{
			result *= -1;
		}
		if (result < mini)
		{
			mini = result;
		}
		v1.clear();
		sum1 = 0;
		sum2 = 0;
		return;
	}
	for (int i = 1; i < n; i++)
	{
		if (lev > 0 and v.back() >= i)
		{
			continue;
		}
		visited[i] = 1;
		v.push_back(i);
		dfs(lev + 1);
		v.pop_back();
		visited[i] = 0;
	}

}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n;
		fill_n(&arr[0][0], 16 * 16, 0);
		fill_n(visited, 16, 0);
		v.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		mini = 21e8;
		sum1 = 0;
		sum2 = 0;
		visited[0] = 1;
		v.push_back(0);
		dfs(0);
		cout << '#' << tc << ' ' << mini << '\n';
	}
	return 0;
}