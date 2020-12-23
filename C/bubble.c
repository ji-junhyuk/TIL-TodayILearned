//
// Created by junto on 12/24/20.
//

#include <stdio.h>
#include <stdlib.h>
#define swap (type, x, y) do { type t = x; x = y; y = t; } while(0)

void bubble(int a[], int n)
{
    int i, j;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(int, a[j-1], a[j]);
    }
}

int main(void)
{
    int i, nx;
    int *x;

    puts("bubble sort");
    printf("number of element:");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; ++i) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);

    puts("ascending order.");
    for (int i = 0; i < nx; ++i) {
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x);

    return 0;
}