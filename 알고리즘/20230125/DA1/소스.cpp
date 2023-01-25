/* Direction Array
2���� �迭 3 * 5->�ʱ�ȭ
�ش� ��ǥ�� �����¿츦 1�� �ٲ� */

#include <iostream>

using namespace std;

int main()
{
	int arr[3][5] = {0};
	int row, col;
	cin >> row >> col;

	int dr[4] = {-1, 1, 0, 0}; // row�ʿ� ������ ��
	int dc[4] = {0, 0, -1, 1}; // col�ʿ� ������ ��

	for (int i = 0; i < 4; i++)
	{
		int nr = row + dr[i]; // row���� �� ��
		int nc = col + dc[i]; // col���� �� �Ʒ�

		if (0 > nr or 0 > nc or nr >=3 or nc >= 5)
		{
			continue;
		}
		arr[nr][nc] = 1;
	}
	return 0;
}