#include "headerfile.h"

// ATTENTION: is_OK is a "reversed counter". 0 means OK

int get_cell_value(int *tab, int sqrlen)
{
    int i;
    
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

    val = 1;
    y = 0;
    while (y < sqrlen)
    {
        if ( x > 1 && get_cell_value(matrix[y][x], sqrlen) > get_cell_value(matrix[y][x - 1], sqrlen))
            val++;
        y++;
    }
    if (val == input)
        return (0);
    else
        return (val);
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
    is_OK;
    y = 0;
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