#include "headerfile.h"

int check_args(int argc, char**argv)
{
    if (argc != 2)
    {
        display_error();
        return (0);
    }
    if (!inputstr_isvalid(argv[1]))
    {
        display_error();
        return (0);
    }
    return(1);
}

int main(int argc, char **argv)
{
    int ***matrix;
    int ***matrix_copy;
    int **input_tab;
    int sqrlen;

    sqrlen = get_digit_nbr(argv[1]) / 4;
    if (!check_args(argc, argv))
        return (1);
    input_tab = create_input_tab(argv[1]);
    display_input_tab(input_tab, sqrlen);
    matrix = create_matrix(sqrlen);
    //display_matrix(matrix, sqrlen);
    matrix_copy = create_matrix(sqrlen);
    apply_input_filter(matrix, input_tab, sqrlen);
    apply_input_filter(matrix, input_tab, sqrlen);
    display_matrix(matrix, sqrlen);

        // apply_matrix_filter(matrix, sqrlen);
        // matrix = get_solution(matrix, matrix_copy, sqrlen);
        // clean_matrix(matrix, sqrlen);
        // display_solution(matrix, sqrlen);

        // free_tab(input_tab);
        // free_matrix(matrix, sqrlen);
    return (0);
    (void)matrix_copy;
    (void)matrix;
}