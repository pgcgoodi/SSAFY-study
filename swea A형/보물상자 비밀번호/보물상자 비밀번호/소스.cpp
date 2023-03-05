#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
string pwd;
char arr[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
vector<int> v;
bool cmp(int a, int b) {
	return a > b;
}

void init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

int main()
{
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> k;
		cin >> pwd;
		v.clear();
		int len = n / 4;
		int a = 0;
		for (int i = 0; i < 4; i++)
		{
			string s = pwd.substr(a, len);
			int sum = 0;
			int b = 1;
			for (int j = len - 1; j >= 0; j--)
			{
				for (int k = 0; k < 16; k++)
				{
					if (s[j] == arr[k])
					{
						sum += b * k;
						b *= 16;
						break;
					}
				}
			}
			int flag = 0;
			if (v.size() == 0)
			{
				v.push_back(sum);
			}
			else
			{
				for (int j = 0; j < v.size(); j++)
				{
					if (v[j] == sum)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					v.push_back(sum);
				}
			}
			a = a + len;
		}
		for (int l = 0; l < len; l++)
		{
			rotate(pwd.begin(), pwd.begin() + 1, pwd.end());
			int a = 0;
			for (int i = 0; i < 4; i++)
			{
				string s = pwd.substr(a, len);
				int sum = 0;
				int b = 1;
				for (int j = len - 1; j >= 0; j--)
				{
					for (int k = 0; k < 16; k++)
					{
						if (s[j] == arr[k])
						{
							sum += b * k;
							b *= 16;
							break;
						}
					}
				}
				int flag = 0;
				for (int j = 0; j < v.size(); j++)
				{
					if (v[j] == sum)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					v.push_back(sum);
				}
				a = a + len;
			}
		}
		sort(v.begin(), v.end(), cmp);
		cout << '#' << tc << ' ' << v[k - 1] << '\n';
	}
	return 0;
}