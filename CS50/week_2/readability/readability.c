#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define LIMIT 1000

float readability(char *text)
{
    int sentences = 1;
    int word = 0;
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] == '.' || text[i] == '?' || text[i] == '!') && text[i + 1] == ' ')
        {
            sentences++;
        }
    }

    char *words = strtok(text, " ,.!\"?:;\n");
    while (words != NULL)
    {
        word++;
        for (int i = 0, n = strlen(words); i < n; i++)
        {
            if (isalpha(words[i]))
            {
                letters++;
            }
        }
        words = strtok(NULL, " ,.!\"?:;\n");
    }

    const float L = letters / (word / 100.0);
    const float S = sentences / (word / 100.0);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    return index;
}

int main(void)
{
    char *text = malloc(sizeof(char) * LIMIT);
    printf("Text: ");
    fgets(text, LIMIT, stdin);

    int index = round(readability(text));
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
    free(text);
}
