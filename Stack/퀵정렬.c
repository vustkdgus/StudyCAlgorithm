/* �� ���� : ��ǥ���� ���� ���� �˰��� 
	������ �Ǿ� �������� �������� ����ϸ� ������.
	1. ���ҵ� �߿��� pivot �� ����
	2. �� pivot�� �������� �տ��� ���� ��, �ڿ��� ū������ ��ġ��Ų��.(����)
	3. ���ҵ� ���� ����Ʈ�� ��������� ���۽�Ų��.(����)
	4. ���ĵ� ���� ����Ʈ���� �����Ѵ�. (����)
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

	while (lleft <= lright) {// lleft�� lritght�� ��ü�� �ȵɶ� ����
		while (pary[lleft] <= pary[pivot]) lleft++; // ������ ��
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