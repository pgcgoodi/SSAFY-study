#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;
/* 예제 1
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

/* 예제2
케이블이 10m 미만은 설치 x
MST 비용은? 설치할 수 없다면 -1
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
    // 무지성 false
    return false;
}
int N, M; // 노드의 개수, 간선의 개수
vector<Edge>v; // 간선을 모두 저장하는 벡터
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
    // 짧은 간선부터 우선적으로 확인하기 위해 간선정보를 정렬
    sort(v.begin(), v.end(), cmp);
    // 앞에서부터 순차적으로 간선을 확인
    // 확인 -> 이 간선을 MST의 일원으로 채택할수 있는가? 
    // 이게 판단되면 -> 연결한다! (즉, 비용을 누적한다)
    // 연결할수 없으면 -> 다음간선 확인 
    int sum = 0; // MST의 최종 비용
    int cnt = 0; // 간선 개수 확인
    for (int i = 0; i < v.size(); i++) {
        Edge now = v[i]; //연결해볼까? 하는 간선
        // A - B + 비용
        // now번 간선을 연결할수 있는지를 확인 
        // cycle이 발생하는가? -> 만약 A와 B가 같은 소속이라면 
        if (Find(now.a) == Find(now.b))
            continue;
        
        // 예제 2 -> 만약 비용이 10보다 작으면 설치 x
        if (now.cost < 10)
        {
            continue;
        }
        
        // 이제 이 간선은 연결을 시킬것이다!
        sum += now.cost;
        // 예제 2 -> 1개의 간선을 더 연결했다!
        cnt++;
        // 이제 now의 A와 now B는 하나의 소속이 된다! 
        Union(now.a, now.b);
    }
    // 예제 2 -> MST가 완성되었는지를 확인
    // 최종적으로 연결된 간선의 개수가 N-1개면 ok
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
    // 간선 정보 입력 
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        // 그래프 구성 
        // 알아야 하는 정보는 A와 B가 cost의 간선으로 연결되어있다!
        v.push_back({ from, to, cost });
    }
    // parent를 초기 세팅
    for (int i = 0; i < N; i++)
        parent[i] = i;
    // MST를 만들겁니다.
    cout << kruskal(); // 크러스칼
    return 0;
}