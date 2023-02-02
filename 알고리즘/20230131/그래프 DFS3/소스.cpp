/*
* 7 7
* 1 2
* 1 3
* 2 4
* 3 4
* 4 5
* 4 6
* 5 7
* 6 7
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int nodec, edgec;
int adj[6][6];
vector <int> v[8];
int used[8];
vector <int> path;

void dfs(int now) {
	if (now == 7)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < v[now].size(); i++)
	{
		int to = v[now][i];
		if (used[to] == 1)
		{
			continue;
		}
		cout << now << "에서 " << to << "로 갑니다!\n";
		used[to] = 1;
		path.push_back(to);
		dfs(to);
		path.pop_back();
		used[to] = 0;
	}
}

int main()
{
	cin >> nodec >> edgec;
	for (int i = 0; i < edgec; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
	}

	path.push_back(1);
	used[1] = 1;
	dfs(1);
	return 0;
}