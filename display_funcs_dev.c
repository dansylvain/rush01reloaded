#include "headerfile.h"

void    display_solution(int ***matrix, int sqrlen)
{
    int x;
    int y;
    int num;

    y = 0;
    printf("Solution :\n");
    while (y < sqrlen)
    {
        x = 0;
        while (x < sqrlen)
        {
            num = matrix[y][x][0] + 48;
            write(1, &num, 1);
            write(1, " ", 1);
            x++;
        }
        write(1, "\n", 1);
        y++;
    }
    
}

void    display_input_tab(int **input_tab, int sqrlen)
{
    int i;
    int j;
    int k;

    i = 0;
    printf("Input_tab :\n  ");
    j = 0;
    while (j < sqrlen)
        printf("%i ", input_tab[i][j++]);
    i++;
    printf("\n");
    j = 0;
    i = 2;
    while (j < sqrlen)
    {
        printf("%i ", input_tab[i][j]);
        k = 0;
        while (k < sqrlen)
        {
            printf("  ");
            k++;
        }
        printf("%i\n", input_tab[i + 1][j]);
        j++;
    }
    printf(" ");
    i = 1;
    j = 0;
    while (j < sqrlen)
        printf(" %i", input_tab[i][j++]);
    printf("\n");
}

void    display_matrix(int ***matrix)
{
    int x;
    int y;
    int z;
    int sqrlen;

    sqrlen = get_sqrlen(matrix);
    x = 0;
    y = 0;
    z = 0;
    while (y < sqrlen)
    {
        x = 0;
        printf("| ");
        while (x < sqrlen)
        {

            z = 0;
            while (z < sqrlen)
            {
                printf("%i ", matrix[y][x][z]);
                z++;
            }
            x++;
            printf(" | ");
        }
        y++;
        printf ("\n");
    }
        printf ("\n");
}