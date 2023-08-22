#include "headerfile.h"

int **alloc_memo_input_tab(int **input_tab)
{
    int i;

    i = 0;
    input_tab = malloc(sizeof(int *) * 4);
    if (input_tab == NULL)
    {
        display_error();
        return (0);
    }
    while (i < 4)
    {
        input_tab[i] = malloc(sizeof(int) * 10);
        if (input_tab[i] == NULL)
        {
            display_error();
            return (0);
        }
        i++;
    }
    return (input_tab);
}

int **create_input_tab(char *str)
{
    int **input_tab;
    int i;
    int j;
    int k;

    input_tab = alloc_memo_input_tab(NULL);
    i = 0;
    j = 0;
    k = 0;
    while(str[i])
    {
        if (str[i] != ' ')
        {    
            if (k == get_digit_nbr(str) / 4)
            {
                j++;
                k = 0;
            }
            input_tab[j][k++] = str[i] - 48;
        }
        i++;
    }
    return (input_tab);
}