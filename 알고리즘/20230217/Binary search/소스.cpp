#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//int arr[] = { 3, 99, 21, 33, 4, 1, 5, 55, 7, 10 };
// binary search = ������ ������ �ʿ��ϴ�. 
// binary search ���� ��� ȿ����? 
// --> ���� �ܼ��ϰ� �ϳ��� ���� �ִ°�? üũ�Ҷ� -> O(N)
// --> ������ ã�ƾ� �Ҷ�
//void bs(int target) {    
//    // #1. ���� � ������ Ž���ϴ°�? 
//    // --> �迭 ������ �����ϴ� ��Ҹ� ã�´� : index 
//    // --> Ư�� ���� ���� �����̴� : ���� �� 
//    int left = 0;
//    int right = 9; 
//    int flag = 0; 
//    
//    while (left <= right) {
//        // mid�� �����Ѵ�! 
//        int mid = (left + right) / 2; 
//        // ���� mid�� ���� ã���� �ϴ� ���̶�� 
//        if (arr[mid] == target) {
//            // ã�Ҵ�! 
//            flag = 1; 
//            // �̹� ã������ �� Ž���غ� �ʿ� X 
//            break; 
//        }
//        else if (target < arr[mid]) {
//            right = mid - 1; 
//        }
//        else if (target > arr[mid]) {
//            left = mid + 1; 
//        }
//    }
//    // ã������ 1, �ƴϸ� 0
//    cout << flag; 
//}
int N;
int arr[4];
int MAX;

bool condition(int val) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > val)
            sum += val; // ���Ѽ���ŭ�ۿ� �ټ� ����
        else
            sum += arr[i];
    }
    if (sum > MAX)
        return false;
    return true;
}

void psearch(int low, int high) {
    int left = low; // ���Ѽ� ������ ���� ������ = 0��
    int right = high; // ���Ѽ� ������ ���� ū �� = ���� ���� ����
    int ans = 0;
    while (left <= right) {
        // ���ɼ� -> �����̶�� ������ �� 
        int mid = (left + right) / 2;
        // �� ���ɼ��� ������ �ɼ� �־�? 
        if (condition(mid) == true) {
            // ������ �� ���ɼ��� �ִ� ���� ã�Ҵ�!
            ans = mid;
            // �� ���� �ݾ��� �� �� �ִ°�?
            // �� ���Ѽ��� ���� ��Ƶ� �����Ѱ�? 
            left = mid + 1;
        }
        else {
            // �� ���� ������ �ɼ� ���� 
            // �ʹ� ���Ѽ��� ���� ��Ҵ�
            // ���Ѽ��� ���� ū ���� ������ �����. 
            right = mid - 1;
        }
    }
    cout << ans;
}

int main() {
    //int target; // ã���� �ϴ� ����
    //cin >> target;
    // arr�ȿ� �� target�� �ִ���? 
    // O(N)
    // ��) 1000���� ������ �ִ� �迭 -> 1000���� Query 
    // O(N) * O(Q) = O(N^2) = 100��
    //int flag = 0;
    //for (int i = 0; i < 10; i++) {
    //    if (arr[i] == target)
    //        flag = 1; 
    //}
    //cout << flag; 
    // binary search
    // target�� ã�ư��� �̺�Ž�� 
    // ��) 1000���� ������ �ִ� �迭 -> 1000���� Query 
    // O(Nlog(2)N) = ����
    // O(NlogN)
    //sort(arr, arr + 10); 
    //// O(logN)
    //bs(target); 
    // parametric search 
    // �� ȸ�� - ���� ����ñ� 
    // N���� �������� �ִ�
    // ���� ���� -> �� �������� �󸶸�ŭ�� �λ��� ���ϴ����� �˰� �ִ�.
    // �� ������ �÷��ټ� �ִ� �ݾ��� ������ �ִ�. 
    // 4
    // 100 200 300 400 
    // 400
    // ��� �ִ��� �ְ� ������, � ���Ѽ��� ���ؾ� �Ѵ�. 
    // ���Ѽ��� ��������, ���� ���Ѽ����� ���� ���ϸ� �� �ְ�
    // �ƴϸ�, ���� �� ���Ѽ� ��ŭ 
    // ���Ѽ��� �󸶷� �����ؾ� �ұ�? 
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> MAX;
    psearch(0, MAX);
    return 0;
}