#include "headerfile.h"

void    erase_all_but_one_digit(int ***matrix, int x, int y, int z)
{
    int i;
    int winner;
    int sqrlen;

    sqrlen = get_sqrlen(matrix);
    winner = matrix[y][x][z];
    i = 0;
    while (i < sqrlen)
    {
        matrix[y][x][i] = 0;
        i++;
    }
    matrix[y][x][z] = winner;
}

void    erase_tested_number(int ***matrix, int ***matrix_copy, int sqrlen)
{
    // printf("func erase_tested_number!\n");
    // display_matrix(matrix);
    int x;
    int y;
    int z;
    
    y = 0;
    while (y < sqrlen)
    {
        x = 0;
        while (x < sqrlen)
        {
            z = 0;
            while (z < sqrlen)
            {
                if (!cell_iscomplete(matrix, x, y, sqrlen) && matrix[y][x][z] != 0)
                {
                    matrix[y][x][z] = 0;
                    // printf("matrix après delete: \n");
                    // display_matrix(matrix);
                    //printf("et on\n%i\n", matrix[y][x][z]);
                    get_solution(matrix, matrix_copy, sqrlen);
                }
                z++;
            }
            x++;
        }   
        y++;
    }
    //get_solution(matrix, matrix_copy, sqrlen);

    //exit(1);
}

void    get_solution(int ***matrix, int ***matrix_copy, int sqrlen)
{
    int x;
    int y;
    int z;
    
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
                if (!cell_iscomplete(matrix_copy, x, y, sqrlen) && matrix_copy[y][x][z] != 0)
                {
                    erase_all_but_one_digit(matrix_copy, x, y, z);
                    apply_matrix_filter(matrix_copy);
                    display_matrix(matrix_copy);
                    if (matrix_is_complete(matrix_copy))
                        printf("solution found\n");
                    //display_matrix(matrix_copy);
                    //get_solution(matrix, matrix_copy, sqrlen);
                }
                z++;
            }
            x++;
        }   
        y++;
    }
    {
    //    printf("sa mère\n");
        erase_tested_number(matrix, matrix_copy, sqrlen);
    }

     //   printf("ouiz!\n");
       // return;

}