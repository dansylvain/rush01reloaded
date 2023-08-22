#include "headerfile.h"

int get_winner(int  *matrix, int sqrlen)
{
    int z;
    int winner;
    z = 0;

    while (z < sqrlen)
    {
        if (matrix[z] != 0)
            winner = matrix[z];
        z++;
    }
    return (winner);
    
}

void    matrix_filter(int ***matrix, int x, int y, int sqrlen)
{
    int winner;
    int z;
    int i;
    winner = get_winner(matrix[y][x], sqrlen);
    i = 0;
    while (i < sqrlen)
    {
        z = 0;
        while (z < sqrlen)
        {
            if (matrix[i][x][z] == winner && i != y)
                matrix[i][x][z] = 0;
            z++;
        }
        z = 0;
        while (z < sqrlen)
        {
            if (matrix[y][i][z] == winner && i != x)
                matrix[y][i][z] = 0;
            z++;
        }
        i++;
    }
}

void    clean_cell(int ***matrix, int x, int y, int sqrlen)
{
    int z;
    int winner;

    z = 0;
    while (z < sqrlen)
    {
        if (matrix[y][x][z] != 0)
            winner = z + 1;
        matrix[y][x][z] = 0;
        z++;
    }
    matrix[y][x][0] = winner;
}

void    clean_matrix(int ***matrix, int sqrlen)
{
    int x;
    int y;

    y = 0;
    while (y < sqrlen)
    {
        x = 0;
        while (x < sqrlen)
        {
            if(cell_iscomplete(matrix, x, y, sqrlen))
                    clean_cell(matrix, x, y, sqrlen);
            x++;
        }
        y++;
    }
}


void    apply_matrix_filter(int ***matrix, int sqrlen)
{
    int x;
    int y;

    y = 0;
    while (y < sqrlen)
    {
        x = 0;
        while (x < sqrlen)
        {
            if (cell_iscomplete(matrix, x, y, sqrlen) == 1)
            {
                matrix_filter(matrix, x, y, sqrlen);
            }
            x++;
        }
        y++;
    }
}