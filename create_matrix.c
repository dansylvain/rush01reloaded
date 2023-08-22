#include "headerfile.h"

int ***copy_matrix(int ***matrix, int ***copy_matrix, int sqrlen)
{
    int x;
    int y;
    int z;

    x = 0;
    y = 0;
    z = 0;
    while (y < sqrlen)
    {
        x = 0;
        while (x < sqrlen)
        {
            z = 0;
            while (z < sqrlen)
            {
                copy_matrix[y][x][z] = matrix[y][x][z];
                z++;
            }
            x++;
        }
        y++;
    }
    return (matrix);
}


int ***alloc_memo_matrix(int ***matrix)
{
    int i;
    int j;

    i = 0;
    matrix = malloc(sizeof(int **) * 9);
    if (matrix == NULL)
        display_error();
    while (i < 9)
    {
        j = 0;
        matrix[i] = malloc(sizeof(int *) * 9);
        if (matrix[i] == NULL)
            display_error();
        while(j < 9)
        {
            matrix[i][j] = malloc(sizeof(int) * 9);
            if (matrix == NULL)
                display_error();
            j++;
        }
        i++;
    }
    return (matrix);
}


int ***fill_matrix(int ***matrix, int sqrlen)
{
    int x;
    int y;
    int z;

    x = 0;
    y = 0;
    z = 0;
    while (y < sqrlen)
    {
        x = 0;
        while (x < sqrlen)
        {
            z = 0;
            while (z < sqrlen)
            {
                matrix[y][x][z] = z + 1;
                z++;
            }
            x++;
        }
        y++;
    }
    return (matrix);
}

int ***create_matrix(int sqrlen)
{
    int ***matrix;

    matrix = alloc_memo_matrix(NULL);
    matrix = fill_matrix(matrix, sqrlen);
    return (matrix);
}