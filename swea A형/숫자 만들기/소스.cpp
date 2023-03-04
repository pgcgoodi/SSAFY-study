#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;
int n;
int sign[4];
int arr[12];
int mini;
int maxi;

void dfs(int lev, int result) {
	if (lev == n - 1)
	{
		if (result > maxi)
		{
			maxi = result;
		}
		if (result < mini)
		{
			mini = result;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int temp = 0;
		if (sign[i] == 0)
		{
			continue;
		}
		if (i == 0)
		{
			temp = result + arr[lev + 1];
			sign[i]--;
		}
		else if (i == 1)
		{
			temp = result - arr[lev + 1];
			sign[i]--;
		}
		else if (i == 2)
		{
			temp = result * arr[lev + 1];
			sign[i]--;
		}
		else
		{
			temp = result / arr[lev + 1];
			sign[i]--;
		}
		dfs(lev + 1, temp);
		if (i == 0)
		{
			sign[i]++;
		}
		else if (i == 1)
		{
			sign[i]++;
		}
		else if (i == 2)
		{
			sign[i]++;
		}
		else
		{
			sign[i]++;
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
		cin >> n;
		mini = 21e8;
		maxi = -21e8;
		fill_n(arr, 12, 0);
		fill_n(sign, 4, 0);
		for (int i = 0; i < 4; i++)
		{
			cin >> sign[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		dfs(0, arr[0]);
		cout << '#' << tc << ' ' << maxi - mini << '\n';
	}
	return 0;
}