#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int MAX = 21e8;

int memo[100000];
int coincnt(int price) {
	if (price < 0)
	{
		return MAX;
	}
	if (price == 0)
	{
		return 0;
	}
	if (memo[price] != 0)
	{
		return memo[price];
	}
	int a = coincnt(price - 10) + 1;
	int b = coincnt(price - 50) + 1;
	int c = coincnt(price - 70) + 1;

	int result = min({ a, b, c });
	memo[price] = result;
	return result;
}

int main()
{
	int n;
	cin >> n;
	cout << coincnt(n);
	return 0;
}