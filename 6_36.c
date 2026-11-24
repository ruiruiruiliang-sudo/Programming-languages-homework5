#include <stdio.h>
#include <stdlib.h>

void stringReverse(const char s[]);

int main(void)
{
    char string[100];

    printf("Enter a string: ");
    scanf("%99s", string);

    printf("Reversed: ");
    stringReverse(string);
    printf("\n");

    system("pause");
    return 0;
}

void stringReverse(const char s[])
{
    if (s[0] == '\0')
        return;

    stringReverse(&s[1]);
    putchar(s[0]);
}
