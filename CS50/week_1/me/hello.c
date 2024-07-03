#include <stdio.h>

int main(void)
{
    char* str;
    printf("What's your name?\n>> ");
    scanf("%s", str);
    printf("hello, %s\n", str);
}
