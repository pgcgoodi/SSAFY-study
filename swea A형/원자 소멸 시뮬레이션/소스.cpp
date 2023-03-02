#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct node
{
	int x;
	int y;
	int d;
	int k;
};
struct pos
{
	int len;
	int a;
	int b;
};
vector<pos> boom;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

bool cmp(pos a, pos b) {
	return a.len < b.len;
}

int main()
{
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		int n;
		cin >> n;
		vector<node> atoms;
		boom.clear();
		for (int i = 0; i < n; i++)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			atoms.push_back({ a, b, c, d });
		}
		int dat[1000] = { 0, };
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int dy = atoms[i].y - atoms[j].y;
				int dx = atoms[i].x - atoms[j].x;
				if (atoms[i].d == 0)
				{
					if (dy <= 0 and ((atoms[i].x == atoms[j].x and atoms[j].d == 1) or (dy == dx and atoms[j].d == 2) or (dy == -dx and atoms[j].d == 3)))
					{
						boom.push_back({ abs(dy) + abs(dx), i, j });
					}
				}
				else if (atoms[i].d == 1)
				{
					if (dy >= 0 and ((atoms[i].x == atoms[j].x and atoms[j].d == 0) or (dy == dx and atoms[j].d == 3) or (dy == -dx and atoms[j].d == 2)))
					{
						boom.push_back({ abs(dy) + abs(dx), i, j });
					}
				}
				else if (atoms[i].d == 2)
				{
					if (dx >= 0 and ((atoms[i].y == atoms[j].y and atoms[j].d == 3) or (dy == dx and atoms[j].d == 0) or (dy == -dx and atoms[j].d == 1)))
					{
						boom.push_back({ abs(dy) + abs(dx), i, j });
					}
				}
				else
				{
					if (dx <= 0 and ((atoms[i].y == atoms[j].y and atoms[j].d == 2) or (dy == dx and atoms[j].d == 1) or (dy == -dx and atoms[j].d == 0)))
					{
						boom.push_back({ abs(dy) + abs(dx), i, j });
					}
				}
			}
		}
		int ans = -1;
		if (boom.size() == 0)
		{
			ans = 0;
		}
		else
		{
			sort(boom.begin(), boom.end(), cmp);
			int dis = boom[0].len;
			dat[boom[0].a]++;
			dat[boom[0].b]++;
			ans = atoms[boom[0].a].k + atoms[boom[0].b].k;
			int len = boom.size();
			for (int i = 1; i < len; i++)
			{
				if (boom[i].len == dis and (boom[i].a == boom[i - 1].a or boom[i].a == boom[i - 1].b or boom[i].b == boom[i - 1].a or boom[i].b == boom[i - 1].b))
				{
					if (dat[boom[i].a] == 0 and dat[boom[i].b] > 0)
					{
						ans += atoms[boom[i].a].k;
						dat[boom[i].a]++;
					}
					else if (dat[boom[i].b] == 0 and dat[boom[i].a] > 0)
					{
						ans += atoms[boom[i].b].k;
						dat[boom[i].b]++;
					}
				}
				else
				{
					if (dat[boom[i].a] == 0 and dat[boom[i].b] == 0)
					{
						ans += atoms[boom[i].a].k + atoms[boom[i].b].k;
						dis = boom[i].len;
						dat[boom[i].a]++;
						dat[boom[i].b]++;
					}
				}
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}