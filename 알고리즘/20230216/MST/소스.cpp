#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;
/* ���� 1
10 16
0 3 10
0 2 20
2 3 34
1 2 30
1 5 12
5 2 56
5 8 7
5 6 21
8 6 23
8 9 15
6 9 78
6 7 67
7 9 22
2 7 45
7 4 35
3 4 60
*/

/* ����2
���̺��� 10m �̸��� ��ġ x
MST �����? ��ġ�� �� ���ٸ� -1
5 8
0 1 50
0 2 30
1 2 5
1 3 7
2 4 20
2 3 8
1 4 9
3 4 1
*/
struct Edge {
    int a;
    int b;
    int cost;
};
bool cmp(Edge left, Edge right) {
    if (left.cost < right.cost)
        return true;
    if (left.cost > right.cost)
        return false;
    // ������ false
    return false;
}
int N, M; // ����� ����, ������ ����
vector<Edge>v; // ������ ��� �����ϴ� ����
int parent[100];

int Find(int now) {
    if (now == parent[now])
        return now;
    return parent[now] = Find(parent[now]);
}

void Union(int A, int B) {
    int pa = Find(A);
    int pb = Find(B);
    if (pa == pb)
        return;

    parent[pb] = pa;
}

int kruskal() {
    // ª�� �������� �켱������ Ȯ���ϱ� ���� ���������� ����
    sort(v.begin(), v.end(), cmp);
    // �տ������� ���������� ������ Ȯ��
    // Ȯ�� -> �� ������ MST�� �Ͽ����� ä���Ҽ� �ִ°�? 
    // �̰� �ǴܵǸ� -> �����Ѵ�! (��, ����� �����Ѵ�)
    // �����Ҽ� ������ -> �������� Ȯ�� 
    int sum = 0; // MST�� ���� ���
    int cnt = 0; // ���� ���� Ȯ��
    for (int i = 0; i < v.size(); i++) {
        Edge now = v[i]; //�����غ���? �ϴ� ����
        // A - B + ���
        // now�� ������ �����Ҽ� �ִ����� Ȯ�� 
        // cycle�� �߻��ϴ°�? -> ���� A�� B�� ���� �Ҽ��̶�� 
        if (Find(now.a) == Find(now.b))
            continue;
        
        // ���� 2 -> ���� ����� 10���� ������ ��ġ x
        if (now.cost < 10)
        {
            continue;
        }
        
        // ���� �� ������ ������ ��ų���̴�!
        sum += now.cost;
        // ���� 2 -> 1���� ������ �� �����ߴ�!
        cnt++;
        // ���� now�� A�� now B�� �ϳ��� �Ҽ��� �ȴ�! 
        Union(now.a, now.b);
    }
    // ���� 2 -> MST�� �ϼ��Ǿ������� Ȯ��
    // ���������� ����� ������ ������ N-1���� ok
    if (cnt == N - 1)
    {
        return sum;
    }
    else
    {
        return -1;
    }
}

int main() {
    cin >> N >> M;
    // ���� ���� �Է� 
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        // �׷��� ���� 
        // �˾ƾ� �ϴ� ������ A�� B�� cost�� �������� ����Ǿ��ִ�!
        v.push_back({ from, to, cost });
    }
    // parent�� �ʱ� ����
    for (int i = 0; i < N; i++)
        parent[i] = i;
    // MST�� ����̴ϴ�.
    cout << kruskal(); // ũ����Į
    return 0;
}