#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	char str[50];
	int i;
	int cnt = 0;
	printf("���ڸ� �Է��� �ּ��� : ");
	scanf("%s", str);
	printf("�Է��� ���� : ");
	for (i = 0; str[i]; i++)
	{
		printf("%c", str[i]);
		cnt++;
	}

	printf("\n���� ���� : %d", cnt);
}