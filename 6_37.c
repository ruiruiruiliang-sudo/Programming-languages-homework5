#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

int recursiveMaximum(const int a[], int size);

int main(void)
{
    int a[SIZE] = {3, 17, 9, 42, 8, 25, 1, 30};
    int i;

    printf("Array: ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", a[i]);

    printf("\nMaximum: %d\n", recursiveMaximum(a, SIZE));

    system("pause");
    return 0;
}

int recursiveMaximum(const int a[], int size)
{
    int max;

    if (size == 1)
        return a[0];

    max = recursiveMaximum(a, size - 1);
    return (a[size - 1] > max) ? a[size - 1] : max;
}
