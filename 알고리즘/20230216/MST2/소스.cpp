#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;
/*
5 8
0 1 50
0 2 30
1 2 5
1 3 7
2 4 20
2 3 8
1 4 9
3 4 35
*/
struct Edge {
    int to;
    int cost;
    bool operator < (Edge next) const {
        if (cost < next.cost)
            return false;
        if (cost > next.cost)
            return true;
        return false;
    }
};
int N, M;
vector<Edge>al[101];

int prim(int start) {
    // #1. priority queue �غ�
    priority_queue<Edge>pq;
    pq.push({ start, 0 });
    // #2. connected DAT�� �غ�
    // ���� ���� start���� ������ MST�� �Ͽ����� ������ �Ǿ��ִ°�? 
    int connected[101] = { 0, };

    // ���
    int sum = 0;
    int cnt = 0;
    // prim ����
    while (!pq.empty()) {
        // ������ ���� ���� �ͺ��� ���ɴϴ�. 
        Edge now = pq.top();
        pq.pop();
        // �̹� now�� MST�� �Ͽ��̾�? 
        if (connected[now.to] == 1)
            continue;
        // MST�� �Ͽ����� ���� Ȯ���� �Ǵ� ���
        connected[now.to] = 1;
        // ���� �� ������ ���� �� = MST�� �Ͽ�
        // �� ���� ����� ����
        sum += now.cost;
        cnt++;
        // now���� ���� �ִ� ��带 priority queue�� ����
        for (int i = 0; i < al[now.to].size(); i++) {
            Edge next = al[now.to][i];
            // ���� �̹� ���������� �ϴ� ��� = MST�� �Ͽ� = �ٽ� �Ⱥ��� �ȴ�
            if (connected[next.to] == 1)
                continue;
            pq.push(next);
        }
    }
    if (cnt == N)
        return sum;
    return -1;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        al[from].push_back({ to, cost });
        al[to].push_back({ from, cost });
    }
    // prim - MST 
    cout << prim(2);
    return 0;
}