//
// Created by junto on 21. 1. 2..
//

#include <stdio.h>

int main(void)
{
    int i, n;
    int sum;
    puts("Sum of 1 to n.");

    do {
        printf("n: ");
        scanf("%d", &n);
    } while (n <= 0);

    sum = 0;
    for (i = 1; i <= n; i++)
        sum += i;
    printf("Sum of 1 to %d: %d", n, sum);
}