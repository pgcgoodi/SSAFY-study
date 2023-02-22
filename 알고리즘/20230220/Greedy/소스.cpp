#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int target; // �Ž�����
int N; // ������ ��
int coins[5];

// �Ž����� ����
/*
1500 4
100 50 10 500
*/

bool cmp(int left, int right) {
    if (left > right)
        return true;
    if (left < right)
        return false;
    return false;
}

int main() {
    cin >> target;
    cin >> N;
    // ���� �Է� 
    for (int i = 0; i < N; i++)
        cin >> coins[i];

    // S : Ž�������� ���� ū ������ �������� �����ش�! 
    sort(coins, coins + N, cmp);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int now = coins[i];
        ans += target / now;
        target %= now;
    }
    cout << ans;
}