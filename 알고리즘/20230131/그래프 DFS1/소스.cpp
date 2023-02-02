// 그래프 DFS
// 정점 : node, vertex, 간선 : edge
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

// 1. 인접 행렬
// adj[ from ] [ to ] = from에서 to로 갈 수 있는가?
// 단점 : 메모리 낭비가 심함(node 갯수 ^ 2)
// 장점 : 특정 from에서 특정 to로 갈 수 있는지 판별 용이
// 2. 인접 리스트
// 장점 : 메모리 낭비 X(edge 갯수)
// 단점 : 특정 from에서 특정 to로 갈 수 있는지 판별 어려움
using namespace std;
int nodec, edgec;
int adj[6][6];
vector <int> v[6];

// 1. 인접행렬
/* void dfs(int now) {
	for (int to = 1; to <= nodec; to++)
	{
		if (adj[now][to] == 0)
		{
			continue;
		}
		cout << now << "에서 " << to << "로 갑니다!\n";
		dfs(to);
	}
} */

// 2. 인접 리스트
void dfs(int now) {
	for (int i = 0; i < v[now].size(); i++)
	{
		int to = v[now][i];
		cout << now << "에서 " << to << "로 갑니다!\n";
		dfs(to);
	}
}

int main()
{
	cin >> nodec >> edgec;
	/* for (int i = 0; i < edgec; i++)
	{
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}
	dfs(1); */

	// 2. 인접 리스트 (벡터의 배열 형태)
	for (int i = 0; i < edgec; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
	}
	dfs(1);

	return 0;
}