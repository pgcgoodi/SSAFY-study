#include <iostream>
#include <queue>

/*
7 6
0 1   
0 2
1 3
1 4
4 5
4 6
*/
/*
4 5
0 1
0 2
1 2
1 3
2 3
*/

using namespace std;
int N, M;
// int mat[10][10];
vector<int>v[10];

void bfs(int start) {
	queue<int>q;
	q.push(start);

	/* while (!q.empty())
	{
		int now = q.front();
		q.pop();
		cout << now << ' ';
		for (int next = 0; next < N; next++)
		{
			if (mat[now][next] == 0)
			{
				continue;
			}
			q.push(next);
		}
	} */

	int visited[10] = { 0, };
	visited[start] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		cout << now << ' ';
		for (int i = 0; i < v[now].size(); i++)
		{
			int to = v[now][i];
			if (visited[to] != 0)
			{
				continue;
			}

			q.push(to);
			visited[to] = visited[now] + 1;
		}
	}
	cout << '\n';
	for (int i = 0; i < N; i++)
	{
		cout << i << "까지의 최단 경로 : " << visited[i] - 1 << '\n';
	}
}

int main()
{
	// queue 사용법
	// queue<int>q : 선언
	// 1 q.push(값) : 삽입
	// 2 q.front() : queue의 맨 앞의 값 확인
	// 3 q.size() : queue에 몇개의 원소가 있는가
	// 4 q.empty() : queue가 비어있으면 true, 아니면 false
	// 5 q.pop() : queue의 맨 앞의 요소를 삭제

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	bfs(0);
	return 0;
}