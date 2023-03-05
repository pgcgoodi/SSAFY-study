#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
int mat[8][8];
int pop[8];
int visited[8];
vector<int> A;
vector<int> B;
int mini;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

void runa(int from) {
	for (int to = 0; to < A.size(); to++)
	{
		if (visited[A[to]] == 1)
		{
			continue;
		}
		if (mat[from][A[to]] == 1)
		{
			visited[A[to]] = 1;
			runa(A[to]);
		}
	}
}

void runb(int from) {
	for (int to = 0; to < B.size(); to++)
	{
		if (visited[B[to]] == 1)
		{
			continue;
		}
		if (mat[from][B[to]] == 1)
		{
			visited[B[to]] = 1;
			runb(B[to]);
		}
	}
}

void dfs(int lev) {
	if (lev == n)
	{
		if (A.size() == 0 or B.size() == 0)
		{
			return;
		}
		memset(visited, 0, sizeof(visited));
		visited[A[0]] = 1;
		runa(A[0]);
		for (int i = 0; i < A.size(); i++)
		{
			if (visited[A[i]] == 0)
			{
				return;
			}
		}
		visited[B[0]] = 1;
		runb(B[0]);
		for (int i = 0; i < B.size(); i++)
		{
			if (visited[B[i]] == 0)
			{
				return;
			}
		}
		int suma = 0;
		int sumb = 0;
		for (int i = 0; i < A.size(); i++)
		{
			suma += pop[A[i]];
		}
		for (int i = 0; i < B.size(); i++)
		{
			sumb += pop[B[i]];
		}
		int tmp = abs(suma - sumb);
		if (tmp < mini)
		{
			mini = tmp;
		}
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			A.push_back({lev});
			dfs(lev + 1);
			A.pop_back();
		}
		else
		{
			B.push_back({lev});
			dfs(lev + 1);
			B.pop_back();
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
		cin >> n;
		memset(mat, 0, sizeof(mat));
		memset(pop, 0, sizeof(pop));
		A.clear();
		B.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> mat[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			cin >> pop[i];
		}
		mini = 21e8;
		dfs(0);
		cout << '#' << tc << ' ' << mini << '\n';
	}
	return 0;
}