
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(int wDeck[][FACES]);
void deal(const int wDeck[][FACES], const char *wFace[], const char *wSuit[]);

int main(void)
{
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int deck[SUITS][FACES] = {0};

    srand(time(NULL));

    shuffle(deck);
    deal(deck, face, suit);

    system("pause");
    return 0;
}

void shuffle(int wDeck[][FACES])
{
    int row;
    int column;
    int card;

    for (card = 1; card <= CARDS; card++)
    {
        do
        {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (wDeck[row][column] != 0);

        wDeck[row][column] = card;
    }
}

void deal(const int wDeck[][FACES], const char *wFace[], const char *wSuit[])
{
    int card;
    int row;
    int column;

    for (card = 1; card <= CARDS; card++)
    {
        for (row = 0; row < SUITS; row++)
        {
            for (column = 0; column < FACES; column++)
            {
                if (wDeck[row][column] == card)
                {
                    printf("%5s of %-8s%c", wFace[column], wSuit[row],
                        card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
}
