#include "headerfile.h"

int cell_iscomplete(int ***matrix, int x, int y, int sqrlen)
{
    int z;
    int i;

    z = 0;
    i = 0;
    while(z < sqrlen)
    {
        if (matrix[y][x][z] == 0)
            i++;
        z++;
    }
    if (i == sqrlen - 1) //     only one digit left
        return 1;
    else if (i == sqrlen) //    no digit left
        return 2;
    else
        return (0);         //      more than one digit left
}

int matrix_is_complete(int  ***matrix)
{
    int sqrlen;

    sqrlen = get_sqrlen(matrix);
    apply_matrix_filter(matrix);
    apply_matrix_filter(matrix);
    apply_matrix_filter(matrix);
    apply_matrix_filter(matrix);
    apply_matrix_filter(matrix);
    if (!get_matrix_state(matrix, sqrlen))
    {
        display_solution(matrix, sqrlen);
        return (1);
    }
    else
        return (0);
}

int get_matrix_state(int ***matrix, int sqrlen)
{
    int i;
    int j;
    int writable_cellsnbr;

    i = 0;
    writable_cellsnbr = 0;
    while (i < sqrlen)
    {
        j = 0;
        while(j < sqrlen)
        {
            if (cell_iscomplete(matrix, j, i, sqrlen) == 2)
            {
                // printf("xyz!");
                return(-1); // -1 => no possible solution
            }
            if (!cell_iscomplete(matrix, j, i, sqrlen))
                writable_cellsnbr++;       
            j++;
        }
        i++;
    }
    return (writable_cellsnbr); // >0 => not finished. 0 =>finished
}