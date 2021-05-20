#include <stdio.h>
int BSearch(int* pary, int sz, int tg)
{
	int first = 0;
	int last = sz - 1;
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (tg == pary[mid]) return mid;
		else {
			if (tg > pary[mid])	first = mid + 1;
			else last = mid - 1;
		}
	}
	return -1;
}
int main()
{
	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int index;

	index = BSearch(ary, size, 6);
	if (index == -1) printf("Å½»ö ½ÇÆÐ!");
	else printf("%d\n", index);

	return 0;
}