#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ���̳��� ���α׷��� = ����ϱ� ���α׷��� (���) 
int dp[101];

// N��° �Ǻ���ġ�� ���ϴ� ���α׷� 
// Top-Down (memoization)
// ū ���� -> ���� ������ �����Ͽ� �ذ��ϴ� ���
int fibo(int now) {
    // ��������
    if (now <= 2)
        return 1;

    // �� ���ӿ��� now�� ���� ������ ����ϰ� �ִٸ�
    if (dp[now] != 0)
        return dp[now];

    // ��� ����
    // now = now - 1 + now - 2 
    // �ٽ� ������� ���ƿ��� ����
    // = now������ ������ ã�Ҵ�! 
    // now��°�� ������ �ƴϱ� -> ���� �ȵ��� ���(���)
    return dp[now] = fibo(now - 1) + fibo(now - 2);
}

int main() {
    int N;
    cin >> N;
    // cout << fibo(N); 

    // Bottom-Up (Tabulation) 
    // �Ʒ���(���� ������ ����)���� ���������� �� ���� ������ �ذ��ϴ� ���
    // * ��ȭ���� ������ �� �־�� �Ѵ� 
    // ���� ���� ������ ���� �ش��� ���ؾ� �Ѵ�

    if (dp[N] != 0)
        cout << dp[N];

    dp[1] = 1;
    dp[2] = 1; // �˰� �ִ� ���� ���� ������ ���� ��
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 2] + dp[i - 1];

    cout << dp[N];
    return 0;
}
