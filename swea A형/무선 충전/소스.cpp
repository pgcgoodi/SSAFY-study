#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;
int m, c;
int path[2][100];
int dy[5] = { 0,-1,0,1,0 };
int dx[5] = { 0,0,1,0,-1 };
struct node
{
	int y;
	int x;
	int scope;
	int pwr;
};
node bc[8];
bool cmp(node a, node b) {
	if (a.pwr < b.pwr)
	{
		return true;
	}
	if (a.pwr > b.pwr)
	{
		return false;
	}
	return false;
};

int maxcharge(int ay, int ax, int by, int bx) {
	vector<int> va(2, 0);
	vector<int> vb(2, 0);
	int flag = 0;
	for (int i = 0; i < c; i++)
	{
		int da = abs(ay - bc[i].y) + abs(ax - bc[i].x);
		int db = abs(by - bc[i].y) + abs(bx - bc[i].x);
		if (da <= bc[i].scope)
		{
			flag = 1;
			va.push_back(i + 1);
		}
		if (db <= bc[i].scope)
		{
			flag = 1;
			vb.push_back(i + 1);
		}
	}
	if (flag == 0)
	{
		return 0;
	}
	int idxa = -1;
	for (int i = va.size() - 1; i >= 0; i--)
	{
		for (int j = vb.size() - 1; j >= 0; j--)
		{
			if (va[i] != 0 and vb[j] != 0 and va[i] == vb[j])
			{
				idxa = i;
				break;
			}
		}
	}
	if (idxa == -1)
	{
		if (va.back() == 0 or vb.back() == 0)
		{
			if (va.back() == 0)
			{
				return bc[vb.back() - 1].pwr;
			}
			else
			{
				return bc[va.back() - 1].pwr;
			}
		}
		else
		{
			return bc[va.back() - 1].pwr + bc[vb.back() - 1].pwr;
		}
	}
	else
	{
		if (va.back() == vb.back())
		{
			if (va[va.size() - 2] == 0 and vb[vb.size() - 2] == 0)
			{
				return bc[va.back() - 1].pwr;
			}
			else
			{
				return max(bc[va.back() - 1].pwr + bc[va[va.size() - 2] - 1].pwr, bc[va.back() - 1].pwr + bc[vb[vb.size() - 2] - 1].pwr);
			}
		}
		else
		{
			return bc[va.back() - 1].pwr + bc[vb.back() - 1].pwr;
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> m >> c;
		memset(path, 0, sizeof(int) * 2 * 100);
		memset(bc, 0, sizeof(node) * 8);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> path[i][j];
			}
		}
		for (int i = 0; i < c; i++)
		{
			cin >> bc[i].x >> bc[i].y >> bc[i].scope >> bc[i].pwr;
		}
		sort(bc, bc + c, cmp);
		node A, B;
		A.y = 1;
		A.x = 1;
		B.y = 10;
		B.x = 10;
		int sum = 0;
		int a = 0;
		while (a <= m)
		{
			int temp = maxcharge(A.y, A.x, B.y, B.x);
			sum += temp;
			A.y += dy[path[0][a]];
			A.x += dx[path[0][a]];
			B.y += dy[path[1][a]];
			B.x += dx[path[1][a]];
			a++;
		}
		cout << '#' << tc << ' ' << sum << '\n';
	}
	return 0;
}