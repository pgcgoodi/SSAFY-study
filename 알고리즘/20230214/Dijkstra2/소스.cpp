#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;
struct Edge {
    int to; // 어디로 향하는 간선이고?
    int cost; // 가중치
};
int N, M; // N : 노드의 개수, M : 간선의 개수
vector<Edge>al[100];
struct cmp {
    bool operator()(Edge& a, Edge& b) {
        if (a.cost < b.cost)
        {
            return false;
        }
        if (a.cost > b.cost)
        {
            return true;
        }
        return false;
    }
};

// PQ를 사용한 dijkstra의 시간복잡도 : O(NlogN)
void dijkstra(int start) {
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push({ start, 0 });
    int dist[100] = { 0, };
    int MAX = 21e8;
    for (int i = 0; i < N; i++)
        dist[i] = MAX;
    dist[start] = 0;
    // int visited[100] = { 0, };

    while (!pq.empty())
    {
        Edge now = pq.top();
        pq.pop();
        /*if (visited[now.to] != 0)
        {
            continue;
        }
        visited[now.to] = 1;*/
        if (now.cost > dist[now.to])
        {
            continue;
        }

        for (int i = 0; i < al[now.to].size(); i++)
        {
            Edge next = al[now.to][i];
            int ncost = dist[now.to] + next.cost;
            if (dist[next.to] <= ncost)
            {
                continue;
            }
            dist[next.to] = ncost;
            pq.push({ next.to, ncost });
        }
    }

    for (int i = 0; i < N; i++) {
        cout << i << " 까지의 최단 거리 : " << dist[i] << '\n';
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        al[from].push_back({ to, cost });
        al[to].push_back({ from, cost });
    }
    dijkstra(0);
    return 0;
}