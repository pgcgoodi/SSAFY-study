#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;
struct node
{
	int y;
	int x;
	int num;
	int dir;
};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
bool cmp(node a, node b) {
	return a.num > b.num;
}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		int n, m, k;
		cin >> n >> m >> k;
		node arr[1000] = {0, };
		for (int i = 0; i < k; i++)
		{
			cin >> arr[i].y >> arr[i].x >> arr[i].num >> arr[i].dir;
		}
		sort(arr, arr + k, cmp);
		while (m > 0)
		{
			for (int i = 0; i < k; i++)
			{
				if (arr[i].num == 0)
				{
					continue;
				}
				arr[i].y += dy[arr[i].dir - 1];
				arr[i].x += dx[arr[i].dir - 1];
			}
			for (int i = 0; i < k; i++)
			{
				if (arr[i].num == 0)
				{
					continue;
				}
				if (arr[i].y == 0 or arr[i].x == 0 or arr[i].y == n - 1 or arr[i].x == n - 1)
				{
					arr[i].num = arr[i].num / 2;
					if (arr[i].dir % 2 ==0) 
					{
						arr[i].dir--;
					}
					else
					{
						arr[i].dir++;
					}
				}
			}
			for (int i = 0; i < k - 1; i++)
			{
				if (arr[i].num == 0)
				{
					continue;
				}
				for (int j = i + 1; j < k; j++)
				{
					if (arr[j].num == 0)
					{
						continue;
					}
					if (arr[i].y == arr[j].y and arr[i].x == arr[j].x)
					{
						arr[i].num += arr[j].num;
						arr[j].num = 0;
					}
				}
			}
			sort(arr, arr + k, cmp);
			m--;
		}
		int sum = 0;
		for (int i = 0; i < k; i++)
		{
			if (arr[i].num > 0)
			{
				sum += arr[i].num;
			}
		}
		cout << '#' << tc << ' ' << sum << '\n';
	}
	return 0;
}