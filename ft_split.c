#include "push_swap.h"
#include <stdlib.h>

// Simple split function for space-separated numbers
char    **ft_split(char *str)
{
    int i = 0, j = 0, k = 0, wc = 1;
    while (str[i])
        if (str[i++] == ' ')
            wc++;
    char **res = malloc((wc + 1) * sizeof(char *));
    i = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (!str[i])
            break;
        int start = i;
        while (str[i] && str[i] != ' ')
            i++;
        int len = i - start;
        res[j] = malloc(len + 1);
        for (k = 0; k < len; k++)
            res[j][k] = str[start + k];
        res[j][k] = '\0';
        j++;
    }
    res[j] = NULL;
    return res;
}

void    free_split(char **arr)
{
    int i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}
