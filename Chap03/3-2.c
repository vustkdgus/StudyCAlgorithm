#include <stdio.h>

void main() {
	int i, n = 0, * ptr;
	int sale[2][4] = { {63, 84, 140, 130}, {157, 209, 251, 312} };

	ptr = &sale[0][0];
	int (*pptr)[4] = &sale; // �迭 ������

	for (i = 0; i < 8; i++)
	{
		printf("\n address : %u sale %d = %d", ptr, i, *ptr);
		ptr++;
	}

	printf("\n%d", pptr);
	printf("\n%d", (pptr + 1));

	getchar();
}