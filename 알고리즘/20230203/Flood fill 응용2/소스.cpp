#include <iostream>

#include <queue> 
using namespace std;

int sy;
int sx;
int by;
int bx;
int my;
int mx;

string MAP[5];
int dist = 0;

struct Node {
    int y; // y좌표 
    int x; // x좌표 
};


void bfs2(int y, int x) {
    // #1. queue 준비
    queue<Node>q;
    q.push({ y, x });

    // #2. visited 준비
    int visited[5][5] = { 0, };
    visited[y][x] = 1; // 시작 노드 방문 기록 

    // #3. 방향 배열 
    int ydir[] = { -1, 1, 0, 0 };
    int xdir[] = { 0, 0, -1, 1 };

    // #4. BFS 동작 (flood fill) 
    while (!q.empty()) {
        // queue (대기열의) 맨 앞에 있는 노드를 추출 
        Node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            // 다음 갈 수 있는 좌표를 일단 본다.
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            // 범위 체크 무조건 #1 
            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
                continue; // 여기는 못간다
            if (visited[ny][nx] != 0)
                continue;
            if (MAP[ny][nx] == '#')
                continue;
            visited[ny][nx] = visited[now.y][now.x] + 1;
            q.push({ ny, nx });
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << visited[i][j] << " ";
        cout << '\n';
    }

    cout << visited[sy][sx] - 1 << '\n';
    cout << visited[by][bx] - 1 << '\n';

    // 무기 -> 캐릭터 
    dist += visited[sy][sx] - 1;
    // 무기 -> 보스
    dist += visited[by][bx] - 1;
}

int main() 
{

    for (int i = 0; i < 5; i++) {
        cin >> MAP[i];
    }

    cin >> sy >> sx;
    // bfs(시작 노드)
    // bfs(시작 좌표) -> bfs(y, x); 

    cin >> by >> bx;
    cin >> my >> mx;

    bfs2(my, mx);

    cout << dist;
}

/*
__###
___#_
#_##_
__#__
#____
0 0
1 4
1 2
*/