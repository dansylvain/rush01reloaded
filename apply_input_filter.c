#include "headerfile.h"

void    set_counters(int *x, int *y, int sqrlen)
{
    if (*y == 1)
        *y = sqrlen - 1;
    else if (*y == 2)
    {
        *y = *x;
        *x = 0;
    }
    else if (*y == 3)
    {
        *y = *x;
        *x = sqrlen - 1;
    }
}

void    min_filter(int ***matrix, int *y, int *x, int sqrlen)
{
    int z;
    int save_x;
    int save_y;

    save_x = *x;
    save_y = *y;
    set_counters(x, y, sqrlen);
    z = 0;
    if (cell_iscomplete(matrix, *x, *y, sqrlen) && matrix[*y][*x][0] != sqrlen)
    {
        matrix[*y][*x][0] = 0;
    }
    else
    {
        while (z < sqrlen)
            matrix[*y][*x][z++] = 0;
        matrix[*y][*x][sqrlen - 1] = sqrlen;
    }
    *x = save_x;
    *y = save_y;
}

void    apply_input_filter(int ***matrix,int **input_tab, int sqrlen)
{
    int *y;
    int *x;
    int i;
    int j;

    y = &i;
    x = &j;
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < sqrlen)
        {
            if (input_tab[i][j] == 1)
                min_filter(matrix, y, x, sqrlen);
            if (input_tab[i][j] == sqrlen)
                max_filter(matrix, j, i, sqrlen);
            j++;
        }
        i++;
    }
}