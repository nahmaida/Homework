#include <stdio.h>

void printPyramid(int height)
{
    int nSpaces = height - 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < nSpaces; j++)
        {
            printf(" ");
        }
        nSpaces--;
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main(void)
{
    int height;
    do
    {
        printf("Height:\n>> ");
        scanf("%i", &height);
    }
    while (height < 1);
    printPyramid(height);
}
