#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

// hash map
// C++���� �����ִ� map�� ������ �ΰ��� �ִ�. 
// #1. unordered_map // <-�긦 ������ (���ĵ��� ���� ��)
// -> hash-table ������ �̿�
// -> �����, ����, Ž�� O(1)~O(logN)
// string�� �����͸� ���� ��ȯ 

// #2. map <-- ���ĵ� �� 
// -> red-black tree 
// -> ���� �����, ����, Ž�� -> O(logN)
// �������� ���� ���� ��� �Ҹ��ϴ�
// string�� key�� ����

int main() {
    // MAP = ������ Ű ���� ������.
    // �̹� �����ϴ°� �ִٸ� -> ��������°� �ƴ϶�
    // �����ϰ� �˴ϴ�. 
    int arr[] = { 1, 200000000, 200000000, 1, 5 };
    // MAP ����
    // unordered_map<key type, value type>
    unordered_map<int, int>um;

    /*
    for (int i = 0; i < 5; i++) {
        um.insert({ arr[i], i});
    }

    cout << um[200000000];
    */

    for (int i = 0; i < 5; i++) {
        // ���� �̹� MAP�� Ű�� ��ϵǾ��ִٸ�
        // �ش� Ű���� ����� value + 1
        // find(��) -> ������ um.end()
        if (um.find(arr[i]) != um.end()) {
            um[arr[i]]++;
        }
        // ���� key�� ���ٸ� 
        // ���� ã�� ���� = value = 1 
        else {
            // inset(key, value); 
            um.insert({ arr[i], 1 });
        }
    }
    // 1. ���� ��µɱ�?
    // 2. map�� �����ұ�? 
    // um[key] -> key�� ���� �˴ϴ�. 
    // cout << um[3]; 

    // ������ 3�̶�� key�� ��� ���������. 
    um[3] = 1;
    int de = 1;
    cout << um[3] << '\n';

    // traversal / iteration 
    // �ð��� �� �ɸ��ϴ�
    for (auto it = um.begin(); it != um.end(); it++) {
        cout << it->first << " " << it->second << '\n';
    }
    return 0;
}