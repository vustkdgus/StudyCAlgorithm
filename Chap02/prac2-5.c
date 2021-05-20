#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	char str[50];
	int i;
	int cnt = 0;
	printf("문자를 입력해 주세요 : ");
	scanf("%s", str);
	printf("입력한 문자 : ");
	for (i = 0; str[i]; i++)
	{
		printf("%c", str[i]);
		cnt++;
	}

	printf("\n문자 길이 : %d", cnt);
}