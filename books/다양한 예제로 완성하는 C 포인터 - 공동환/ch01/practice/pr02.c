#include <stdio.h>
int main()
{
	printf("%ld\n", sizeof(char));
	printf("%ld\n", sizeof(int));
	printf("%ld\n", sizeof(long));
	printf("%ld\n", sizeof(float));
	printf("%ld\n", sizeof(double));
	puts("===========");
	printf("%ld\n", sizeof(char *));
	printf("%ld\n", sizeof(int *));
	printf("%ld\n", sizeof(long *));
	printf("%ld\n", sizeof(float *));
	printf("%ld\n", sizeof(double *));
}
