#include <stdio.h>
#include <stdlib.h>

int getSize(const char *str)
{
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++)
        size++;
    return size;
}

int isNumeric(const char *str)
{
    for (int i = 0; i < getSize(str); i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

void luhnsCheck(const char *num)
{
    int sum = 0;
    int size = getSize(num);
    for (int i = size - 1; i >= 0; i -= 2)
    {
        sum += num[i] - '0';
        int val = (num[i - 1] - '0') * 2;
        if (val == 0 || i == 0)
            continue;
        char *str = malloc(5 * sizeof(char));
        sprintf(str, "%d", val);
        int valSize = getSize(str);
        for (int j = 0; j < valSize; j++)
        {
            sum += (str[j] - '0');
        }
    }

    if (sum % 10)
    {
        printf("INVALID\n");
    }
    else if (size == 15 && num[0] == '3' && (num[1] == '4' || num[1] == '7'))
    {
        printf("AMEX\n");
    }
    else if ((size == 13 || size == 16) && num[0] == '4')
    {
        printf("VISA\n");
    }
    else if (size == 16 && num[0] == '5' && num[1] > '0' && num[1] < '6')
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{
    char *num = malloc(50 * sizeof(char));
    do
    {
        printf("Enter your card number:\n>> ");
        scanf("%s", num);
    }
    while (!isNumeric(num));
    luhnsCheck(num);
    free(num);
}
