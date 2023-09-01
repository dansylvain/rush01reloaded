#include "headerfile.h"

void    erase_all_but_one_digit(int ***matrix, int *xyz, int sqrlen)
{
    int i;
    int winner;
    int x;
    int y;
    int z;
//printf("erase_all_but_one_digit\n");
    x = xyz[0];
    y = xyz[1];
    z = xyz[2];

    winner = matrix[y][x][z];
    i = 0;
    while (i < sqrlen)
    {
        matrix[y][x][i] = 0;
        i++;
    }
    matrix[y][x][z] = winner;
}

int    ***get_the_shit_done(int ***matrix, int ***matrix_copy, int *xyz, int sqrlen)
{
    int x;
    int y;
    int z;
         
    x = xyz[0];
    y = xyz[1];
    z = xyz[2];
    

        if (!get_matrix_state(matrix_copy, sqrlen))
        {
            return (matrix_copy);
        }
        else if (get_matrix_state(matrix, sqrlen) == -1)
        {
            matrix[y][x][z] = z + 1;
            matrix = copy_matrix(matrix_copy, matrix, sqrlen);
        }
        else if (matrix[y][x][z] != 0 && !cell_iscomplete(matrix, x, y, sqrlen))
        {
            erase_all_but_one_digit(matrix_copy, xyz, sqrlen);
            apply_matrix_filter(matrix_copy, sqrlen);            
            get_solution(matrix, matrix_copy, sqrlen);
        }
        return (0);
}

int    ***get_solution(int ***matrix, int ***matrix_copy, int sqrlen)
{
    int x = 0;
    int y = 0;
    int z = 0;
    int xyz[3];

    matrix_copy = copy_matrix(matrix, matrix_copy, sqrlen);
    y = 0;
    while (y < sqrlen)
    {
        x = 0;
        while (x < sqrlen)
        {
            z = 0;
            while (z < sqrlen)
            {
                xyz[0] = x;
                xyz[1] = y;
                xyz[2] = z;
                get_the_shit_done(matrix, matrix_copy, xyz, sqrlen);
                z++;
            }
            x++;
        }   
        y++;
    }
    return (matrix);
}