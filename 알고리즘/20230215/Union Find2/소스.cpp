#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

/*
// 9���� ���, 6���� ���� ����
9 7
0 3
3 6
6 8
3 7
1 4
2 5
4 3
*/
// Find : �Ҽ��� ã�ư��� �˰��� 
// #1. ���� (�θ� ����)�� ������ parent�� �ʿ�
int parent[101];
int N, M;
// ������ �� ����
int pop[101];
int Find(int now) {
    if (now == parent[now])
        return now;
    return parent[now] = Find(parent[now]);
}
void Union(int A, int B) {
    // #1. �� A�� B�� �Ҽ��� Ȯ��
    int pa = Find(A);
    int pb = Find(B);
    // ���� A�� B�� �̹� ���� �Ҽ��̶�� �Ʒ� �պ��� ��ġ�� ����!
    if (pa == pb)
        return; // �Լ� ����
    // #2. B�� �Ҽ��� A�� �Ҽ��� ���Ϸ� �����!
    parent[pb] = pa;
    // �պ��� �Ǹ鼭, Aȸ�簡 Bȸ���� �����ڸ� 10�� �����´�! 
    pop[A] += 10;
    pop[B] -= 10;
}
int main() {
    //cin >> N >> M;
    //// parent�� �׻� �ڱ� �ڽ��� �����̴�! 
    //// ��, ������, �������� ����̴�! ��� ���¿��� ����
    //for (int i = 0; i < N; i++)
    //    parent[i] = i; // ���� �θ�� ����! 
    //// �Ҽ� ���� ���� 
    //for (int i = 0; i < M; i++) {
    //    // A�� B�� ���յȴ�! 
    //    int A, B;
    //    cin >> A >> B;
    //    Union(A, B); 
    //}
    //int a, b;
    //cin >> a >> b;
    //// a�� b�� ���� �׷��ΰ�? 
    //// --> ���� ���� parent�� ��Ȳ���� �� X
    //// --> �ѹ� �� ������Ʈ
    //// if (parent[a] == parent[b])
    //// -> A�� ��ǥ�� �ٽ� �ѹ� ã�ư��鼭 parent�� update 
    //// --> A�� ���� ��忡 ���� path compression
    //if(Find(a) == Find(b))
    //    cout << "���� �׷�";
    //else
    //    cout << "�ٸ� �׷�";
    // ����
    // N���� ȸ�簡 �ֽ��ϴ� (IT ȸ��)
    // ȸ����� ������ �����Ƽ� ���ϸ鼭 M���� �μ��պ� ������ ��ƿ�
    // A�� B�� �μ��Ҷ�, Aȸ�簡 ��ǥȸ�簡 �ǰ�, 
    // Bȸ��κ��� 10���� �����ڵ��� ���ð̴ϴ�. 
    // M���� �μ��պ� ������ ��ģ ��, �� ȸ�翡 �� ���� �����ڰ� �����ִ����� ��� 
    // input 
    /*
    6 5
    10 20 30 40 50 60
    0 1
    3 0
    3 4
    4 3
    2 5
    */
    // output : 10 10 40 60 40 50
    cin >> N >> M;

    // parent ����
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        int temp;
        cin >> temp;
        pop[i] = temp;
    }
    // �պ� ����
    for (int i = 0; i < M; i++) {
        // A�� B�� �պ��Ѵ�!
        int A, B;
        cin >> A >> B;
        // Union�� �ϱ� ����, �̷� ����������, �̹� ���յ� �Ҽ��� �ٽ� �����ϸ� ������ ���� �� �ִ�! 
        // #1. Union�� �ϱ� ���� ���� ���� Ȯ�� 
        if (Find(A) == Find(B))
            continue; // �̹� ���� �Ҽ��̶�� �������� �ʾ�! 
        Union(A, B);
    }
    for (int i = 0; i < N; i++) {
        cout << i << " : " << pop[i] << '\n';
    }
}