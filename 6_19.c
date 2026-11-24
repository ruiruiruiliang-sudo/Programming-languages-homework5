#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROLLS 36000

int main(void)
{
    int freq[13] = {0};   
    int roll;
    int die1, die2;
    int sum;

    srand(time(NULL));

    for (roll = 1; roll <= ROLLS; roll++)
    {
        die1 = 1 + rand() % 6;   
        die2 = 1 + rand() % 6;   
        sum = die1 + die2;
        freq[sum]++;
    }

    printf("%5s%12s%12s\n", "Sum", "Frequency", "Percent");
    for (sum = 2; sum <= 12; sum++)
    {
        printf("%5d%12d%11.2f%%\n", sum, freq[sum],
            100.0 * freq[sum] / ROLLS);
    }

    printf("\nSum 7 expected about %d times, got %d\n", ROLLS / 6, freq[7]);

    system("pause");
    return 0;
}
