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
    int y; // y��ǥ 
    int x; // x��ǥ 
};


void bfs2(int y, int x) {
    // #1. queue �غ�
    queue<Node>q;
    q.push({ y, x });

    // #2. visited �غ�
    int visited[5][5] = { 0, };
    visited[y][x] = 1; // ���� ��� �湮 ��� 

    // #3. ���� �迭 
    int ydir[] = { -1, 1, 0, 0 };
    int xdir[] = { 0, 0, -1, 1 };

    // #4. BFS ���� (flood fill) 
    while (!q.empty()) {
        // queue (��⿭��) �� �տ� �ִ� ��带 ���� 
        Node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            // ���� �� �� �ִ� ��ǥ�� �ϴ� ����.
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            // ���� üũ ������ #1 
            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
                continue; // ����� ������
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

    // ���� -> ĳ���� 
    dist += visited[sy][sx] - 1;
    // ���� -> ����
    dist += visited[by][bx] - 1;
}

int main() 
{

    for (int i = 0; i < 5; i++) {
        cin >> MAP[i];
    }

    cin >> sy >> sx;
    // bfs(���� ���)
    // bfs(���� ��ǥ) -> bfs(y, x); 

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