#include "../solong.h"

void    deprint(char *str)
{
    int i = 0;

    while (str[i])
    {
        printf("This is deprint ===> [%c]\n", str[i]);
        i++;
    }
}

void    deprint2d(char **str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i + 1] == NULL)
            printf("%s\n", str[i]);
        else
            printf("%s", str[i]);
        i++;
    }
    printf("\n");
}