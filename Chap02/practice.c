#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	
	int n, i;
	
	while (1)
	{
		printf("n�� ���� �Է��ϼ���(1~9) : ");
		scanf("%d", &n);
		if (n < 0 || n >= 10)
		{
			printf("������ �ʰ��Դϴ�.");
			break;
		}

		for (i = 1; i < 10; i++)
		{
			int res = n * i;
			printf("%d * %d = %d\n", n, i, res);
		}
	}
	return 0;
}