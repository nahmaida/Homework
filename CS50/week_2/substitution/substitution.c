#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substitute(char *text, char *key)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            int pos = 25 - 'Z' + toupper(text[i]);
            if islower (text[i])
            {
                text[i] = tolower(key[pos]);
            }
            else
            {
                text[i] = toupper(key[pos]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26 - 1; i++)
    {
        if (!(isalpha(argv[1][i])))
        {
            printf("All characters in key must be alphabetic.\n");
            return 1;
        }

        for (int j = i + 1; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key mustn't contain duplicates.\n");
                return 1;
            }
        }
    }

    char *text = malloc(sizeof(char) * 1000);
    printf("plaintext: ");
    fgets(text, 1000, stdin);

    substitute(text, argv[1]);
    printf("ciphertext: %s", text);
    free(text);
}
