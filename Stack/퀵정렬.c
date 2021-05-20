/* 퀵 정렬 : 대표적인 분할 정복 알고리즘 
	정렬이 되어 있지않은 구조에서 사용하면 빠르다.
	1. 원소들 중에서 pivot 을 고른다
	2. 이 pivot을 기준으로 앞에는 작은 값, 뒤에는 큰값들을 위치시킨다.(분할)
	3. 분할된 작은 리스트를 재귀적으로 동작시킨다.(정복)
	4. 정렬된 작은 리스트들을 결합한다. (결합)
*/
#include <stdio.h>

void quickSort(int*, int, int);
int main()
{
	int ary[] = { 3, 5, 2, 4, 7, 6, 1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	quickSort(ary, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", ary[i]);
	}

	return 0;
}
void quickSort(int* pary, int left, int right)
{
	if (left >= right) return;
	int pivot = left;
	int lleft = pivot + 1;
	int lright = right;
	int temp;

	while (lleft <= lright) {// lleft와 lritght가 교체가 안될때 까지
		while (pary[lleft] <= pary[pivot]) lleft++; // 정렬이 됨
		while (pary[lright] >= pary[pivot] && lright > left) lright--;

		if (lleft > lright)
		{
			temp = pary[lright];
			pary[lright] = pary[pivot];
			pary[pivot] = temp;
		}
		else {
			temp = pary[lright];
			pary[lright] = pary[lleft];
			pary[lleft] = temp;
		}
	}
	for(int k = 0; k < right + 1; k++)
	quickSort(pary, left, lright - 1);
	quickSort(pary, lright + 1, right);
}