#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// �Ž����� 
/*
1200 5
500 400 100 50 10
*/

// Memoization (Top-Down)
// - �������� ��� (��� ���ۿ� ���� ���ص��� �ִ�) 
// - �Ƹ� �� ����� �����ϱ� �� ����. 
// - ����ġ��, backtracking, return ���� �̷��͸� �����ϰ� ����
//   ���� ������ ��ٷο��� �������� �ڵ� ¥�°� ����� ������. 
// - ��� ȣ�� + return ���� -> tabulation���ٴ� ���� ����
// - ��� ������ Ǯ�� ���� (���� Ǯ��� �ϴ� ������ Ǭ��.) 

// Tabulation (Bottom-Up)
// - ��ȭ�� ������ �ʿ��ϹǷ� ��������� ���� ���� X 
// - ��ȭ�� ������ ������ ��ٷο�� ��ȭ�� ����⵵ ���� �ʴ�. 
// - ������ �����κ��� N���� ��� ������ Ǭ��. 


// index : Ư�� �Ž����� �׼�
// value : �� �Ž������� �����ֱ� ���� �ּ� ���� ����
int dp[10001];
int target; // ������ �ϴ� �Ž����� 
int N;
int coins[100];

// #1. Top-Down
int func(int now) {
    // ���� ����(base case) 
    if (now == 0) //���� ã�Ҵ�!
        //���信 ������ ���� �ʴ� �� return 
        return 0;

    if (now < 0) // �����̴�! 
        //now������ ��Ͽ� �ּҰ��� ����� �� �ֵ���
        // ������ ��ĥ �� ��, ��~�� ū ���� return
        return 21e8;

    // ���� now�� ���� ���� ���(���)�ǰ� �ִٸ� 
    if (dp[now] != 0)
        return dp[now];

    // ��� ����(recursive case)
    // now���� ��� ������ �ϳ��� �����鼭 �� �� ����������
    int MIN = 21e8;
    for (int i = 0; i < N; i++) {
        // now�� �ٽ� �ö���� 
        // func(now-coins[i]) + 1 
        int temp = func(now - coins[i]) + 1;
        // �� temp�� �ּ��ΰ�? 
        if (temp < MIN)
            MIN = temp;
    }

    // now���� �ö������, ���� ������ ���� ��� �����Ͽ�
    // �� �� ���� ���� ���� dp[now]�� ��� 
    return dp[now] = MIN;
}

int main() {
    cin >> target >> N;
    for (int i = 0; i < N; i++)
        cin >> coins[i];
    // cout << func(target);

    // Bottom-Up
    // #0. �ּҰ�
    for (int i = 0; i <= target; i++)
        dp[i] = 21e8;
    // #1. ã�� �� �ִ� ���� ���� ������ ���� �ش� 
    dp[0] = 0;

    // ��� ���ο� ���ؼ� ���̺��� ä���
    for (int i = 0; i < N; i++) {
        int now = coins[i];
        for (int j = now; j <= target; j++) {
            // ���� ��ġ���� �� ������ ����ŭ�� �� ��������
            // ������ �ϳ� �� �߰������� -> ���� now�� ���� �� �ִ� ���� ���´�
            // �̹� dp�� ��ϵ� ������ ���� ������ ����� �ȴٸ� -> ���� X
            if (dp[j - now] + 1 < dp[j])
                dp[j] = dp[j - now] + 1;
        }
    }
    cout << dp[target];
    return 0;
}