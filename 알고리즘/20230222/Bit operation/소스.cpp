#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ��Ʈ ���� 
// Bit = ���� ���� ������ ����
// tb gb mb kb byte -> bit
// 1 byte = 8 bit
// 2������ ǥ�� 0�� 1�θ� �̷�����ִ�

// ��Ʈ������
// A & B (AND) :  A�� B�� ��� 1�̸� 1 �ƴϸ� 0
// A | B (OR) : A�� B�� �ϳ��� 1�̿��� 1 �ƴϸ� 0
// A ^ B (XoR, Exclusive or) : ���� �ٸ��� 1 �ƴϸ� 0 
// ~A (NOT, *Complement) : 0�̸� 1, 1�̸� 0
// << N (left shift) : ��� ��Ʈ�� Nĭ �������� �̵� 
// >> N (right shift) : ��� ��Ʈ�� Nĭ ���������� �̵�

int main() {
    int A = 3; // 0011
    int B = 5; // 0101

    // & 
    // 0011
    // 0101
    //------
    // 0001
    int C = A & B;
    cout << C << '\n';

    // |
    // 0011
    // 0101
    // ----
    // 0111
    int D = A | B;
    cout << D << '\n';

    // XoR -> ��ȣȭ �о߿� ���� ���ȴ�
    // 0011
    // 0101
    // ----
    // 0110
    int E = A ^ B;
    cout << E << '\n';

    int original = 35;
    int a = 123456789;
    int b = 987654321;
    int c = original ^ a ^ b ^ b ^ a;
    cout << c << '\n';

    // ~ : original -> -(original) - 1
    // int = 4byte
    // 0000000 0000101
    // -----
    // 1111111 11111010
    // -> �̳� ū ���̿��� �Ѵ�
    int F = ~B;
    cout << F << '\n';

    // shift ���� 
    // 0011
    // ----
    // �տ� �������� 0 �Ǵ� 1
    // ��ȣ�� ���󰣴�
    // 0001
    int G = A >> 1;
    cout << G << '\n';

    // 0011
    // ---- 
    // 1100
    int H = A << 2;
    cout << H << '\n';

    // ��Ʈ ���� ���� ���µ�? 
    // #1. ������ ������� ��Ʈ���� �����̴�
    // #2. (��Ʈ ���ù���) ��Ʈ����ŷ (bit masking)

    // Bitmasking #1
    // Ư�� ��Ʈ�� �ٲٴ� ���
    // B = 5 => 0101
    // ���� : Ư�� ��Ʈ�� 1�� �ٲٰ� �ʹ�. 
    // N = 1 => 0111 => 7

    //    0101
    //    0010
    // | ------
    //    0111
    int N = 1;
    int res = B | (1 << N);
    cout << res << '\n';

    // Bitmasking #2 
    // Ư�� bit�� ��� -> ���� ���� ��ġ�� �ٲٴ°̴ϴ�.
    // B = 5 => 0101
    // N = 1 => 0111
    // N = 0 => 0100 

    //    0101
    //    0010
    // ^ ------
    //    0101
    N = 2;
    res = B ^ (1 << N);
    cout << res << '\n';

    // Bitmasking #2 
    // Ư�� bit�� ����
    // B = 5 => 0101
    // N = 0 => 0100
    // N = 2 => 0001
    // N = 1 => 0101

    //    0101
    //    1011
    // & ------
    //    0001
    N = 2;
    res = B & ~(1 << N);
    cout << res << '\n';
    return 0;
}