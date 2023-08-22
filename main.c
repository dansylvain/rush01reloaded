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

int main(int argc, char **argv)
{
    int ***matrix;
    int ***matrix_copy;
    int **input_tab;
    int sqrlen;

    sqrlen = get_digit_nbr(argv[1]) / 4;
    if (check_args(argc, argv))
        return (1);
    input_tab = create_input_tab(argv[1]);
    matrix = create_matrix(sqrlen);
    matrix_copy = create_matrix(sqrlen);
    apply_input_filter(matrix, input_tab, sqrlen);
    apply_matrix_filter(matrix, sqrlen);
    matrix = get_solution(matrix, matrix_copy, sqrlen);
    clean_matrix(matrix, sqrlen);
    display_solution(matrix, sqrlen);

    free_tab(input_tab);
    free_matrix(matrix, sqrlen);
    return (0);
}