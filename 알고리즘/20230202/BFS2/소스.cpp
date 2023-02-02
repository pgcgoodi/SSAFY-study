#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int mat[5][5] =
{
	0,1,0,0,1,
	0,0,1,1,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0
};
char v[6] = { "ACTSB" };
queue<int> q;

int main()
{
	// 1. 초기 세팅
	q.push(0);

	while (!q.empty())
	{
		// 2. 맨 앞 하나 빼기
		int now = q.front();
		q.pop();

		cout << now;
		for (int i = 0; i < 5; i++)
		{
			// 3. 연결된 인접 노드 넣기
			if (mat[now][i] == 0)
			{
				continue;
			}
			q.push(i);
		}
	}

	return 0;
}