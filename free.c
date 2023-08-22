#include "headerfile.h"

void free_tab(int **input_tab)
{
    int i;

    i = 0;
    while (i < 4)
        free(input_tab[i++]);
    free(input_tab);
}

void free_matrix(int ***matrix, int sqrlen)
{
    int i;
    int j;

    i = 0;
    while (i < sqrlen)
    {
        j = 0;
        while (j < sqrlen)
            free(matrix[i][j++]);
        free(matrix[i]);
        i++;
    }
    free(matrix);
}