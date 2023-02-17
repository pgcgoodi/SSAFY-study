#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

// Union : ���� �ٸ� �ΰ��� �ٸ� ������ �����ϴ� �۾�
// Find : Ư�� �Ҽӿ� ���� ����� � �Ҽӿ� ���ԵǾ� �ִ����� ã�ư���, �Ǵ��ϴ� �۾�
// Find ����ȭ : path compression(��� ����)

/*
A�� B�� �θ�
18 15
3 0
6 3
9 6
10 6
11 6
4 1
7 4
12 7
13 7
14 7
5 2
8 5
15 8
16 8
17 8
*/

using namespace std;
int parent[101];
int N, M;
// Find�� �ð����⵵ : O(N)
// ��� ���� ���� Find�� �ð����⵵ : O(A(N))
// ���� : �ð��� ȿ������ ���� ����Ѵ�
// ���� : ����ų���� ����

int Find(int now) {
    // ���� ���� 
    // now�� �θ� ���� ���ٸ� -> �Ҽ��� ã�Ҵ�!
    if (now == parent[now])
        return now;
    cout << now << "�� �θ� : " << parent[now] << "\n";

    // ��� ����
    // ���� ������ �ƴϸ� -> ���� �θ� ã�ư���!
    // path compresssion 
    // ���ƿ�����-> �Ҽ��� "�ƴ� ����"�� ������ ���ƿ��ϱ�
    // ���� �θ�(�Ҽ�)�� = ���ƿö� ������ �ִ� ���̴� 
    return parent[now] = Find(parent[now]);
}

int main() {
    // cin >> N >> M;
    // parent�� �׻� �ڱ� �ڽ��� �����̴�! 
    // ��, ������, �������� ����̴�! ��� ���¿��� ����
    for (int i = 0; i < N; i++)
        parent[i] = i; // ���� �θ�� ����! 
    //for (int i = 0; i < M; i++) {
    //    int A, B;
    //    cin >> A >> B;
    //    // A�� �θ�� B�� 
    //    parent[A] = B; 
    //}
    for (int i = 0; i < 100; i++)
        parent[i + 1] = i;
    int num;
    cin >> num;
    cout << num << " �� �Ҽ��� : " << Find(num) << '\n';
    cout << "=======\n";
    cout << num << " �� �Ҽ��� : " << Find(num);
    cout << '\n';
    for (int i = 0; i < 100; i++)
        cout << parent[i] << " ";
}