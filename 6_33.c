#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

int binarySearch(const int b[], int searchKey, int low, int high);

int main(void)
{
    int a[SIZE];
    int i;
    int key;
    int result;

    for (i = 0; i < SIZE; i++)
        a[i] = 2 * i;

    printf("Enter a number between 0 and 28: ");
    scanf("%d", &key);

    result = binarySearch(a, key, 0, SIZE - 1);

    if (result != -1)
        printf("%d found in array element %d\n", key, result);
    else
        printf("%d not found\n", key);

    system("pause");
    return 0;
}

int binarySearch(const int b[], int searchKey, int low, int high)
{
    int middle;

    if (low > high)
        return -1;

    middle = (low + high) / 2;

    if (searchKey == b[middle])
        return middle;
    else if (searchKey < b[middle])
        return binarySearch(b, searchKey, low, middle - 1);
    else
        return binarySearch(b, searchKey, middle + 1, high);
}
