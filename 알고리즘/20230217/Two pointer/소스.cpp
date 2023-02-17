#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    //int arr[] = { 1, 2, 3, 1, 2, 3, 5, 6, 7, 8 };
    //// target
    //int target = 1; 
    //// two pointer
    //int left = 0; // slow pointer
    //int right = 0; // fast pointer
    //// ���� ���� left�� right�����Ͱ� ����Ű�� �ִ� ������ �� 
    //int sum = 0; 
    //int cnt = 0; 
    //while (left <= 10 && right <= 10) {
    //    if (sum == target) {
    //        cnt++; 
    //        sum -= arr[left];
    //        left++;
    //    }
    //    else if (sum < target) {
    //        // sum�� fast pointer (right)�� ����Ű�� ���� ���ϰ�
    //        sum += arr[right];
    //        // right�� �� ĭ �̵�
    //        right++; 
    //    }
    //    else if(sum > target){
    //        // sum���� left �����Ͱ� ����Ű�� ���� ���� 
    //        sum -= arr[left];
    //        // left�� ��ĭ �̵�
    //        left++; 
    //    }
    //}
    //cout << cnt;
    int arr[] = { 1, 1, 8, 1, 2, 3, 5, 6, 7, 8 };
    int N = 3; // ���� ũ��

    // sliding window
    // 1. �ʱ� ������ ����
    int left = 0;
    int right = N - 1;  // index�� 0���� �����ϴ� ��� -> ���� ũ�� - 1
    // 2. �ʱ� ���� ���� ���� 
    int sum = 0;
    for (int i = left; i < right; i++)
        sum += arr[i];
    // 3. sliding window
    int ans = 21e8;
    // right �����Ͱ� ������ ����� ���������� 
    while (right < 10) {
        // ���� �ϼ�
        sum += arr[right];
        // ����
        if (sum < ans)
            ans = sum;
        cout << "SUM : " << sum << '\n';
        // ���� ���� ���� �����
        sum -= arr[left];
        // left�� right ������ �̵�
        left++;
        right++;
    }
    cout << ans;
    return 0;
}