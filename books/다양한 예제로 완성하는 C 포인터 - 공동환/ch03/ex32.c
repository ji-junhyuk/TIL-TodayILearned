#include <stdio.h>
int main()
{
	int iarr2[2][3] = {1,2,3,4,5,6};

	printf("%p\n", iarr2);
	printf("%d %d %d %d %d %d\n", iarr2[0][0], iarr2[0][1], iarr2[0][2], iarr2[1][0], iarr2[1][1], iarr2[1][2]);
	printf("%d\n", *((int *)(0x12ff68)));
}
