#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
// ����ġ�� ���� �ִܰ�� -> BFS
// ����ġ�� �ִ� �ִܰŸ� -> Dijkstra -> ����ġ�� ���� ���� �� ���ַ� ��� ��
// �غ�ܰ�
// 1. dist DAT �ʿ� -> dist[���] = 0
// 2. visited �ʿ� -> ���� �� ����� �ִ� �Ÿ��� Ȯ���Ǿ��°�?
// ���� �ܰ�
// 1. ��� ����� �ִ� �Ÿ����� Ȯ���� ������
// 2. ���� dist�� ��ϵǾ� �ִ� [�ĺ� �Ÿ�] �� ���� ���� ������ ���� ��带 ã�´�.
// -> �ش� ����� �ִ� �Ÿ��� Ȯ��
// 3. �ش� ��忡�� �� �� �ִ� ��� �������� Ȯ���ϸ鼭 dist�� �ĺ����� ����
// -> ���� �̹� ���� �ĺ������� ũ�ų� ���� ��ΰ� ��Ÿ���� ����X

using namespace std;
struct Edge {
    int to; // ���� ���ϴ� �����̰�?
    int cost; // ����ġ
};
int N, M; // N : ����� ����, M : ������ ����
vector<Edge>al[100];


// �ð����⵵ : O(V^2)
void dijkstra(int start) {
    // dist �غ�
    int dist[100] = { 0, };
    // ��� ���� ū ���� ������ ����
    int MAX = 21e8;
    for (int i = 0; i < N; i++)
        dist[i] = MAX;
    // ����������� ����ġ = 0
    dist[start] = 0;

    // visited �غ�
    // index: ���, value: ���� �� ����� �ִ� �Ÿ��� Ȯ���� �Ǿ��°�? 
    int visited[100] = { 0, };

    // dijkstra ������ ���� 
    // ����� ������ŭ �ݺ� -> �ѹ� �������� �ϳ��� ����� �ִ� �Ÿ��� Ȯ��
    // ��, ��� ����� �ִܰŸ��� Ȯ���ɶ����� 
    for (int i = 0; i < N; i++) {

        int mincost = 21e8; // ���� ���� ���� ����ġ�� ���� ������ ��
        int now = -1; // ���� ���� ������ �ϴ� ��� 

        // ���� ���� ����ġ�� ���� ������ ã���� 
        for (int j = 0; j < N; j++) {
            // j��° ��忡 ��ϵ� �ĺ����� �ּҰ����� ������ -> ���� 
            if (dist[j] >= mincost)
                continue;
            // �̹� Ȯ���� ����� -> �ٽ� �� �ʿ� X
            if (visited[j] == 1)
                continue;
            // ���ο� �ּҰ��� ã�Ҵ�! 
            mincost = dist[j];
            now = j;
        }

        // now������ �ִ� �Ÿ� = Ȯ��
        visited[now] = 1;

        for (int j = 0; j < al[now].size(); j++) {
            Edge next = al[now][j];
            // ���� �������� ��� = ���� Ȯ���� �������� ���(�Ÿ�) + next���� ���� ���
            int ncost = dist[now] + next.cost;
            // ���ο� ��θ� ã�Ҵ�
            // ������, �̹� ��ϵ� �ĺ������� �� �����ɸ��� ��θ� ���� ���� 
            if (dist[next.to] <= ncost)
                continue; // ���ο� �ĺ����� ������� �ʴ´�. 
            dist[next.to] = ncost;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << i << " ������ �ִ� �Ÿ� : " << dist[i] << '\n';
    }
}

int main() {
    cin >> N >> M;
    // ���� ���� �Է�
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        al[from].push_back({ to, cost });
        al[to].push_back({ from, cost });
    }
    dijkstra(0);
    return 0;
}