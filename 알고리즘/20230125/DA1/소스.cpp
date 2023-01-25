/* Direction Array
2차원 배열 3 * 5->초기화
해당 좌표의 상하좌우를 1로 바꿈 */

#include <iostream>

using namespace std;

int main()
{
	int arr[3][5] = {0};
	int row, col;
	cin >> row >> col;

	int dr[4] = {-1, 1, 0, 0}; // row쪽에 더해질 값
	int dc[4] = {0, 0, -1, 1}; // col쪽에 더해질 값

	for (int i = 0; i < 4; i++)
	{
		int nr = row + dr[i]; // row에서 양 옆
		int nc = col + dc[i]; // col에서 위 아래

		if (0 > nr or 0 > nc or nr >=3 or nc >= 5)
		{
			continue;
		}
		arr[nr][nc] = 1;
	}
	return 0;
}