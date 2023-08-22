#include "headerfile.h"

void    max_filter_top(int ***matrix, int x, int sqrlen)
{
    int z;
    int i;

    i = 0;
    while (i < sqrlen)
    {
        z = 0;
        while (z < sqrlen)
        {
            matrix[i][x][z++] = 0;
        }
        matrix[i][x][i] = i + 1;
        i++;
    }
}

void    max_filter_bottom(int ***matrix, int x, int sqrlen)
{
    int z;
    int i;

    i = sqrlen - 1;
    while (i >= 0)
    {
        z = 0;
        while (z < sqrlen)
        {
            matrix[i][x][z++] = 0;
        }
        matrix[i][x][i] = sqrlen - i ;        
        i--;
    }
}

void    max_filter_left(int ***matrix, int x, int sqrlen)
{
    int z;
    int i;

    i = 0;
    while (i < sqrlen)
    {
        z = 0;
        while (z < sqrlen)
        {
            matrix[x][i][z++] = 0;
        }
        matrix[x][i][i] = i + 1;
        i++;
    }
}

void    max_filter_right(int ***matrix, int x, int sqrlen)
{
    int z;
    int i;

    i = sqrlen - 1;
    while (i >= 0)
    {
        z = 0;
        while (z < sqrlen)
        {
            matrix[x][i][z++] = 0;
        }
        matrix[x][i][i] = sqrlen - i ;
        i--;
    }
}

void    max_filter(int ***matrix, int x, int y, int sqrlen)
{
    if (y == 0)
        max_filter_top(matrix, x, sqrlen);
    if (y == 1)
        max_filter_bottom(matrix, x, sqrlen);
    if (y == 2)
        max_filter_left(matrix, x, sqrlen);
    if (y == 3)
        max_filter_right(matrix, x, sqrlen);
}