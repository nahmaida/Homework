// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table. Using 10^24.
const unsigned int N = 16777216;

// Hash table
node *table[N];
bool loaded = false;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    if (!loaded)
    {
        return false;
    }

    int size = strlen(word);
    char *copy = malloc((size + 1) * sizeof(char));

    if (copy == NULL)
    {
        return false;
    }

    for (int i = 0; i < size; i++)
    {
        copy[i] = tolower(word[i]);
    }
    copy[size] = '\0';

    unsigned int hashed = hash(copy);
    node *n = table[hashed];

    while (n != NULL)
    {
        if (!strcmp(n->word, copy))
        {
            free(copy);
            return true;
        }
        n = n->next;
    }
    free(copy);
    return false;
}

// Hashes word to a number using djb2 hash
unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        c = word[i];
        hash = ((hash << 5) + hash) + c;
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");

    if (source == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char line[LENGTH + 2];
    while (fgets(line, sizeof(line), source))
    {
        line[strcspn(line, "\n")] = '\0';
        unsigned int hashed = hash(line);

        node *n = malloc(sizeof(node));
        strcpy(n->word, line);
        n->next = NULL;

        if (table[hashed] == NULL)
        {
            table[hashed] = n;
            continue;
        }

        node *cur = table[hashed];
        while (cur->next != NULL)
        {
            cur = cur->next;
        }

        cur->next = n;
    }

    loaded = true;
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (!loaded)
    {
        return 0;
    }

    int words = 0;
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        while (n != NULL)
        {
            words++;
            n = n->next;
        }
    }
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    if (!loaded)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        while (n != NULL)
        {
            node *temp = n->next;
            free(n);
            n = temp;
        }
    }

    loaded = false;
    return true;
}
