#include "headerfile.h"

// ATTENTION: is_OK is a "reversed counter". 0 means OK

int get_cell_value(int *tab, int sqrlen)
{
    int i;

    i = 0;
    while (i < sqrlen)
    {
        if (tab[i] != 0)
            return (tab[i]);
        i++;
    }
        return (0);
}

int check_col_up(int ***matrix, int input, int sqrlen, int x)
{
    int y;
    int val;
    int res;

    res = 1;
    val = 0;
    y = 0;
    while (y < sqrlen)
    {
        if ( y > 1 && val > get_cell_value(matrix[y - 1][x], sqrlen))
            res++;
        if (get_cell_value(matrix[y][x], sqrlen) > val)
            val = get_cell_value(matrix[y][x], sqrlen);
        y++;
    }
    if (val + 1 == input)
        return (0);
    else
        return (res);
}

// int check_col_down(int ***matrix, int input, int sqrlen, int x)
// {
//     int i;

//     i = 4;
//     while ()
//     {
//         i++;
//     }
//     return (0);
// }

// int check_row_left(int ***matrix, int input, int sqrlen, int y)
// {
//     int i;

//     i = 4;
//     while ()
//     {
//         i++;
//     }
//     return (0);
// }

// int check_row_right(int ***matrix, int input, int sqrlen, int y)
// {
//     int i;

//     i = 4;
//     while ()
//     {
//         i++;
//     }
//     return (0);
// }

int solution_is_correct(int ***matrix, int **input_tab)
{  
    int x;
    int y;
    int is_OK;
    int sqrlen;

    sqrlen = get_sqrlen(matrix);
    is_OK = 0;
    y = 0;
    printf("solution_is_correct\n");
    while (y < 4)
    {
        x = 0;
        while (x < 4)
        {
            if (y == 0)
                is_OK += (check_col_up(matrix, input_tab[y][x], sqrlen, x));
            // if (y = 1)
            //     is_OK += (check_col_down(matrix, input_tab[y][x], sqrlen, x));
            // if (y = 2)
            //     is_OK += (check_row_left(matrix, input_tab[y][x], sqrlen, y));
            // if (y = 3)
            //     is_OK += (check_row_right(matrix, input_tab[y][x], sqrlen, y));
            x++;
        }
        y++;
    }
    return (is_OK);
}