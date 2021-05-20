/* 삽입정렬 : 두번째 자료부터 앞 자료를 비교하여 정렬한다.*/
#include <stdio.h>

void insertionSort(int* , int);
void print(int* , int);
int main()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	insertionSort(ary, size);
	//print(ary, size);

	return 0;
}
void insertionSort(int* pary, int sz)
{
	int i, j, temp;
	for (i = 1; i < sz; i++)
	{
		for (j = i; j > 0; j--)
		{
			if (pary[j] < pary[j - 1])
			{
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
			else break;
		}
		for (int k = 0; k < sz; k++)
		{
			printf("%d ", pary[k]);
		}
		printf("\n");
	}
}
void print(int* pary, int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("ary[%d]	: %d", i, pary[i]);
	}
}