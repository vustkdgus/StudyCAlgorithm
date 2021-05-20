#include <stdio.h>

int LSearch(int* pary, int sz, int tg)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		if (tg != pary[i]) continue;
		else break;
	}
	
	if (i == 7)
		printf("찾는 값이 없습니다.");
	else
		printf("%d번째 값 : %d", i, tg);

	return i;
}
int main()
{
	int index;
	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	LSearch(ary, size, 2);
	return 0;
}