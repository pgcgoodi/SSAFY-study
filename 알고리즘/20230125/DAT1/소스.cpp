// ���ڿ� �� �� ���ĺ��� �� �� �ΰ�?
// DAT: Direct Access Table -> �迭�� index�� �ǹ̸� �ο�
// int DAT[]; // index : ����, value : �ش� ������ �� ��?

#include <iostream>

using namespace std;

int main()
{
	char temp[100];
	cin >> temp;

	int DAT[256] = { 0, }; // �⺻���� ����(Ascii code) : 128����, char��� data�� ǥ�� ������ ���� = 256����
	// index : ����
	// value : �ش� ���ڰ� �� ��?
	for (int i = 0; i < temp[i]; i++)
	{
		char now = temp[i]	;
		DAT[now]++; // now��� ���ڰ� 1�� �߰�
	}

	return 0;
}