#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m, k, A, B;
int a[9];
int b[9];
int people[1000][3];
struct node
{
	int num;
	int fint;
	int origin;
};
vector<node> fina;
bool cmp(node a, node b) {
	if (a.fint < b.fint)
	{
		return true;
	}
	if (a.fint > b.fint)
	{
		return false;
	}
	if (a.num < b.num)
	{
		return true;
	}
	if (a.num > b.num)
	{
		return false;
	}
}


void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

void first() {
	int receipt[9] = { 0, };
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (people[i][0] >= receipt[j])
			{
				receipt[j] = people[i][0] + a[j];
				people[i][1] = j;
				fina.push_back({ j, receipt[j], i });
				break;
			}
			else
			{
				if (j == n - 1)
				{
					people[i][0]++;
					j = -1;
				}
			}
		}
	}
}

void second() {
	sort(fina.begin(), fina.end(), cmp);
	int repair[9] = { 0, };
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (fina[i].fint >= repair[j])
			{
				repair[j] = fina[i].fint + b[j];
				people[fina[i].origin][2] = j;
				break;
			}
			else
			{
				if (j == m - 1)
				{
					fina[i].fint++;
					j = -1;
				}
			}
		}
	}
}

int main()
{
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> m >> k >> A >> B;
		A--;
		B--;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(people, 0, sizeof(people));
		fina.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}
		for (int i = 0; i < k; i++)
		{
			cin >> people[i][0];
		}
		first();
		second();
		int ans = 0;
		vector<int> v;
		for (int i = 0; i < k; i++)
		{
			if (people[i][1] == A and people[i][2] == B)
			{
				v.push_back(i);
			}
		}
		if (v.size() == 0)
		{
			ans = -1;
		}
		else
		{
			for (int i = 0; i < v.size(); i++)
			{
				ans += v[i] + 1;
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}