// vector : ���� �迭(�迭 ������ ���� ����)
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> v(5); // capacity 5�� 0���� �ʱ�ȭ

int main()
{
	v.push_back(5); // size�� 1 Ŀ���鼭 �� �ڿ� 5�� ����
	// size�� capcity�� ���� ����
	v.pop_back(); // �� ���� ���Ҹ� ����, size�� ���� �پ��
	vector<int> a(6, 2); // 6�� capacity�� ������ ���͸� 2�� �ʱ�ȭ

	cout << a.front(); // ù ��° ���Ҹ� ������
	cout << a.back(); // ������ ���Ҹ� ������

	return 0;
}