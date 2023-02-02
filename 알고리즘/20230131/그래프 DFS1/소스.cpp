// �׷��� DFS
// ���� : node, vertex, ���� : edge
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

// 1. ���� ���
// adj[ from ] [ to ] = from���� to�� �� �� �ִ°�?
// ���� : �޸� ���� ����(node ���� ^ 2)
// ���� : Ư�� from���� Ư�� to�� �� �� �ִ��� �Ǻ� ����
// 2. ���� ����Ʈ
// ���� : �޸� ���� X(edge ����)
// ���� : Ư�� from���� Ư�� to�� �� �� �ִ��� �Ǻ� �����
using namespace std;
int nodec, edgec;
int adj[6][6];
vector <int> v[6];

// 1. �������
/* void dfs(int now) {
	for (int to = 1; to <= nodec; to++)
	{
		if (adj[now][to] == 0)
		{
			continue;
		}
		cout << now << "���� " << to << "�� ���ϴ�!\n";
		dfs(to);
	}
} */

// 2. ���� ����Ʈ
void dfs(int now) {
	for (int i = 0; i < v[now].size(); i++)
	{
		int to = v[now][i];
		cout << now << "���� " << to << "�� ���ϴ�!\n";
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

	// 2. ���� ����Ʈ (������ �迭 ����)
	for (int i = 0; i < edgec; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
	}
	dfs(1);

	return 0;
}