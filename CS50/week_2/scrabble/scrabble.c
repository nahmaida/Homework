#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scrabble(char *word)
{
    int score = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        word[i] = toupper(word[i]);

        if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'L' ||
            word[i] == 'N' || word[i] == 'O' || word[i] == 'R' || word[i] == 'S' ||
            word[i] == 'T' || word[i] == 'U')
        {
            score++;
        }
        else if (word[i] == 'D' || word[i] == 'G')
        {
            score += 2;
        }
        else if (word[i] == 'B' || word[i] == 'C' || word[i] == 'M' || word[i] == 'P')
        {
            score += 3;
        }
        else if (word[i] == 'F' || word[i] == 'H' || word[i] == 'V' || word[i] == 'W' ||
                 word[i] == 'Y')
        {
            score += 4;
        }
        else if (word[i] == 'K')
        {
            score += 5;
        }
        else if (word[i] == 'J' || word[i] == 'X')
        {
            score += 8;
        }
        else if (word[i] == 'Q' || word[i] == 'Z')
        {
            score += 8;
        }
        else
        {
            continue;
        }
    }
    return score;
}

int main(void)
{
    char *val1 = malloc(sizeof(char) * 50);
    char *val2 = malloc(sizeof(char) * 50);
    printf("Player 1: ");
    scanf("%s", val1);
    printf("Player 2: ");
    scanf("%s", val2);
    int score1 = scrabble(val1);
    int score2 = scrabble(val2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    free(val1);
    free(val2);
}
