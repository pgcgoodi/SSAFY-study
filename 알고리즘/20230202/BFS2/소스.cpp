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
	// 1. �ʱ� ����
	q.push(0);

	while (!q.empty())
	{
		// 2. �� �� �ϳ� ����
		int now = q.front();
		q.pop();

		cout << now;
		for (int i = 0; i < 5; i++)
		{
			// 3. ����� ���� ��� �ֱ�
			if (mat[now][i] == 0)
			{
				continue;
			}
			q.push(i);
		}
	}

	return 0;
}