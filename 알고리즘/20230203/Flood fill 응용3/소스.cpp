#include <iostream>

#include <queue> 
using namespace std;

int sy, sx;

string MAP[8] = {
    "####",
    "###_",
    "#___",
    "_###",
    "_###",
    "____",
    "##__",
    "#___"
};

struct Node {
    int y; // y��ǥ 
    int x; // x��ǥ 
};

// �ܰ躰 floodfill 
/*
void bfs(int y, int x) {
    // #1. queue �غ�
    queue<Node>q;
    q.push({ y, x });

// #2. visited �غ�
int visited[5][5] = { 0, };
visited[y][x] = 1; // ���� ��� �湮 ���

// #3. ���� �迭
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };

int day = 1;
cout << "DAY #" << day << '\n';
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        cout << visited[i][j];
    }
    cout << '\n';
}

while (!q.empty()) {
    // ���� ���� �Ǿ���!
    day++;

    // ���� queue���� ���� ��¥�� ������ node ��ŭ���� �����ؼ� ���
    int cursize = q.size();
    for (int j = 0; j < cursize; j++) {

        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
                continue; //

            if (visited[ny][nx] == 1)
                continue;

            visited[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }

    cout << "DAY #" << day << '\n';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << visited[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}
}
*/

int cnt = 0;
// visited�� �������� flood fill���� �����Ҽ� �ֵ��� ��
int visited[8][8] = { 0, };

void bfs(int y, int x) {
    // #1. queue �غ�
    queue<Node>q;
    q.push({ y, x });

    // #2. visited �غ�
    visited[y][x] = 1; // ���� ��� �湮 ��� 

    // #3. ���� �迭 
    int ydir[] = { -1, 1, 0, 0 };
    int xdir[] = { 0, 0, -1, 1 };

    while (!q.empty()) {

        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8)
                continue; // 

            if (visited[ny][nx] == 1)
                continue;

            // ����� ���̶�� -> ���
            if (MAP[ny][nx] == '_')
                continue;

            visited[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // ���� �� ��ġ�� ���̶�� && ���� Ȯ������ ���� ���̶��
            if (MAP[i][j] == '#' && visited[i][j] == 0) {
                bfs(i, j);
                // �ѹ��� �÷������� ����ȴٸ� -> �ϳ��� ����� ���� ã�Ҵ�!
                cnt++;
            }
        }
    }
    cout << cnt;
}