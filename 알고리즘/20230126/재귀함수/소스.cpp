#include <iostream>

using namespace std;

/* ��� ���� ���� : for������ ���� �� �� ���� �� ���� ����
ex) �Է��� ���ڸ�ŭ for�� �ݺ� ��Ű�� �� */
/* ���� ��� ȣ�� ���� ��
1. ���� ����
2. �Ű� ���� */


void bbq(int x) {
	if (x == 2)
	{
		return;
	}

	bbq(x+1);

	int d = 1;
}

int main()
{
	bbq(0);
	return 0;
}