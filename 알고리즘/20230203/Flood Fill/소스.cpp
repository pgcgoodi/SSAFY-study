#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
struct Node
{
	int y;
	int x;
};
int y, x;


void bfs(int y, int x) {
	// 1. queue 준비
	queue<Node> q;
	q.push({ y, x });

	// 2. visited 준비
	int visited[5][5] = { 0, };
	visited[y][x] = 1;

	// 3. 방향 배열(DA)
	int ydir[] = { -1,1,0,0 };
	int xdir[] = { 0,0,-1,1 };

	// 4. BFS 동작(flood fill)
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			// 범위 확인
			if (ny < 0 or nx < 0 or ny >= 5 or nx >= 5)
			{
				continue;
			}
			if (visited[ny][nx] != 0)
			{
				continue;
			}
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny, nx});
		}
	}
}

int main()
{
	cin >> y >> x;
	bfs(y, x);
	return 0;
}