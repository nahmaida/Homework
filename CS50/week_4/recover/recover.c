#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t BYTE;

void recoverImages(FILE *input);
bool checkSignature(BYTE bytes[]);

bool end = false;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover input.raw\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    recoverImages(input);
    fclose(input);
    return 0;
}

void recoverImages(FILE *input)
{
    BYTE b = 0;
    BYTE buffer[512];
    FILE *output = NULL;
    int nPics = 0;
    bool opened = false;
    while (fread(buffer, sizeof(BYTE), 512, input) == 512)
    {
        end = (feof(input));
        if (end)
        {
            return;
        }

        else if (checkSignature(buffer))
        {
            if (opened)
            {
                fclose(output);
                nPics++;
            }
            char *out = malloc(10 * sizeof(char));
            sprintf(out, "%03d.jpg", nPics);
            output = fopen(out, "wb");
            opened = true;
            free(out);
            fwrite(buffer, sizeof(BYTE), 512, output);
        }
        else if (output != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, output);
        }
    }
    fclose(output);
}

bool checkSignature(BYTE bytes[])
{
    return (!memcmp(bytes, "\xFF\xD8\xFF", 3) && bytes[3] >= 0xE0 && bytes[3] <= 0xEF);
}
