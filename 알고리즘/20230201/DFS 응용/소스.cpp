#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int D;
int W;
int K;
int film[13][20];
int Copy[13][20]; // 복사본
int cnt; // 약품 주입 횟수
int ans;

bool test() {
	for (int j = 0; j < W; j++)
	{
		int base = Copy[0][j];
		int cnt = 0;
		int flag = 0;
		for (int i = 0; i < D; i++)
		{
			if (base == Copy[i][j])
			{
				cnt++;
				if (cnt >= K)
				{
					flag = 1;
					break;
				}
			}
			else
			{
				base = Copy[i][j];
				cnt = 1;
			}
		}
		if (flag == 0)
		{
			return false;
		}
	}
	return true;
}

void func(int lev) {
	// 기저 조건 : D번 행에 도달 시
	if (lev == D)
	{
		if (test() == true)
		{
			if (cnt < ans)
			{
				ans = cnt;
			}
		}
		return;
	}
	if (cnt > ans)
	{
		return;
	}
	// 재귀 구성
	// 1. 아무 것도 안함
	func(lev + 1);
	// 2. A 약품 투약
	for (int i = 0; i < W; i++)
	{
		Copy[lev][i] = 0;
	}
	cnt++;
	func(lev + 1); // 재귀 위는 진행하면서 실행할 부분, 아래는 되돌릴 부분
	for (int i = 0; i < W; i++)
	{
		Copy[lev][i] = film[lev][i];
	}
	cnt--;
	// 3. B 약품 투약
	for (int i = 0; i < W; i++)
	{
		Copy[lev][i] = 1;
	}
	cnt++;
	func(lev + 1);
	for (int i = 0; i < W; i++)
	{
		Copy[lev][i] = film[lev][i];
	}
	cnt--;
}

int main()
{
	// freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		// 1. reset
		cnt = 0;
		ans = 13;
		memset(film, 0, sizeof(film));
		memset(Copy, 0, sizeof(Copy));
		// 2. input
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> film[i][j];
				Copy[i][j] = film[i][j];
			}
		}
		// 3. solve
		if (test())
		{
			ans = 0;
		}
		else
		{
			func(0);
		}
		// 4. output
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}