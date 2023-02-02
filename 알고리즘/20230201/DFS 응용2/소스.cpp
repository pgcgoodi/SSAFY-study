#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

/*
2
4
9 8 9 8
4 6 9 4
8 7 7 8
4 5 3 5
5
8 2 9 6 6
1 9 3 3 4
8 2 3 3 6
4 3 4 4 9
7 4 6 3 5
*/

int MAP[20][20];
int visited[20][20]; // �湮 ��� 
int DAT[101]; // index : ī�信�� �����ϴ� ����Ʈ ����, value : �湮�ߴ°�? 
int N;
int cnt;
int ans = -21e8; // -21��

// ���� �迭
// ������ �Ʒ� -> ���� �Ʒ� -> ���� �� -> ������ �� 
int ydir[] = { 1,1, -1,-1 };
int xdir[] = { 1,-1,-1,1 };

void dfs(int y, int x, int dir, int dy, int dx) {

    // ���� ���� (option) -> ���� ��� ��Ʈ�� ���Ƽ� �ٽ� ���� ������ �ڸ��� ������
    if (y == dy && x == dx) {
        // �ִ밪->���� �� ��Ʈ�� ���� ���� �� ī���� �� = �ִ��� ���� 
        if (cnt > ans)
            ans = cnt;
        return;
    }

    // �� ���� ����ġ���ؼ� ���������� backtracking
    // #1. �� (����üũ) -> ���� �迭
    if (y < 0 || x < 0 || y >= N || x >= N)
        return;
    // #2. �湮üũ
    if (visited[y][x] == 1)
        return;
    // #3. ���� ������ ī�� �̹� �湮���� �ִ°�? 
    if (DAT[MAP[y][x]] == 1)
        return;

    // ����ġ�⸦ ��� ����ߴٸ� -> �� (y,x) ��ġ�� ������ �� �ִ�!-> ����
    visited[y][x] = 1;
    DAT[MAP[y][x]] = 1;
    cnt++;

    // #1. �� �������� 
    dfs(y + ydir[dir], x + xdir[dir], dir, dy, dx);

    // ���� ���� �ʿ� ���� -> (y,x) �������� ���� ��Ʈ�� ���������̱� ����

    // #2. ������ �ٲ㼭 ��������
    if (dir < 3) {
        dir++;
        dfs(y + ydir[dir], x + xdir[dir], dir, dy, dx);
        dir--;
    }

    visited[y][x] = 0;
    DAT[MAP[y][x]] = 0;
    cnt--;
}

int main() {

    //freopen("input.txt", "r", stdin);

    int T;// test case
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // reset
        memset(MAP, 0, sizeof(MAP));
        memset(DAT, 0, sizeof(DAT));
        memset(visited, 0, sizeof(visited));
        ans = -21e8;
        cnt = 0;

        // input
        cin >> N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> MAP[i][j];

        // solve -> ��� ��ġ�� ��������� �ΰ� dfs Ž�� 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = 1;
                DAT[MAP[i][j]] = 1; // (i,j) ��ġ�� ī�� ������ �̹� �湮�ߴ�!
                cnt++;
                //dfs(���� y, ���� x, ����, ���� y, ���� x);
                dfs(i + 1, j + 1, 0, i, j);
                cnt--;
                visited[i][j] = 0;
                DAT[MAP[i][j]] = 0;
            }
        }

        // output 
        // ���� ��Ʈ�� ã�� ���ߴٸ� -> ans = -21e8; 
        if (ans == -21e8)
            ans = -1;
        cout << "#" << tc << " " << ans << '\n';
    }
}