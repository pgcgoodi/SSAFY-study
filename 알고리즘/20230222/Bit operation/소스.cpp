#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 비트 연산 
// Bit = 가장 작은 데이터 단위
// tb gb mb kb byte -> bit
// 1 byte = 8 bit
// 2진수로 표현 0과 1로만 이루어져있다

// 비트연산자
// A & B (AND) :  A와 B가 모두 1이면 1 아니면 0
// A | B (OR) : A와 B중 하나만 1이여도 1 아니면 0
// A ^ B (XoR, Exclusive or) : 둘이 다르면 1 아니면 0 
// ~A (NOT, *Complement) : 0이면 1, 1이면 0
// << N (left shift) : 모든 비트를 N칸 왼쪽으로 이동 
// >> N (right shift) : 모든 비트를 N칸 오른쪽으로 이동

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

    // XoR -> 암호화 분야에 많이 사용된다
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
    // -> 겁나 큰 값이여야 한다
    int F = ~B;
    cout << F << '\n';

    // shift 연산 
    // 0011
    // ----
    // 앞에 껴들어오는 0 또는 1
    // 부호를 따라간다
    // 0001
    int G = A >> 1;
    cout << G << '\n';

    // 0011
    // ---- 
    // 1100
    int H = A << 2;
    cout << H << '\n';

    // 비트 연산 언제 쓰는데? 
    // #1. 문제가 노골적인 비트연산 문제이다
    // #2. (비트 관련문제) 비트마스킹 (bit masking)

    // Bitmasking #1
    // 특정 비트를 바꾸는 방법
    // B = 5 => 0101
    // 문제 : 특정 비트를 1로 바꾸고 싶다. 
    // N = 1 => 0111 => 7

    //    0101
    //    0010
    // | ------
    //    0111
    int N = 1;
    int res = B | (1 << N);
    cout << res << '\n';

    // Bitmasking #2 
    // 특정 bit를 토글 -> 내가 정한 위치를 바꾸는겁니다.
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
    // 특정 bit를 삭제
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