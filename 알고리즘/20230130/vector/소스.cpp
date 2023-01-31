// vector : 동적 배열(배열 사이즈 변경 가능)
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> v(5); // capacity 5가 0으로 초기화

int main()
{
	v.push_back(5); // size가 1 커지면서 멘 뒤에 5가 저장
	// size와 capcity가 같지 않음
	v.pop_back(); // 맨 뒤의 원소를 지움, size도 같이 줄어듬
	vector<int> a(6, 2); // 6의 capacity를 가지는 벡터를 2로 초기화

	cout << a.front(); // 첫 번째 원소를 참조함
	cout << a.back(); // 마지막 원소를 참조함

	return 0;
}