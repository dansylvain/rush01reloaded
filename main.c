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
    matrix_copy = copy_matrix(matrix_copy, matrix, sqrlen);
    apply_input_filter(matrix, input_tab, sqrlen);
    apply_input_filter(matrix, input_tab, sqrlen);
    apply_matrix_filter(matrix);
    apply_matrix_filter(matrix);
    apply_matrix_filter(matrix);
    printf("Matrix:\n");
    display_matrix(matrix);
    printf("Matrix_copy:\n");
    display_matrix(matrix_copy);
    matrix_copy[3][1][2] = 0;
    matrix_copy[1][3][2] = 0;
    matrix_copy[2][3][0] = 0;
    apply_matrix_filter(matrix);
    apply_matrix_filter(matrix);
    matrix_copy[3][1][2] = 0;
    display_matrix(matrix_copy);

    //printf("get_cell_value: %i\n", get_cell_value(matrix_copy[3][3], sqrlen));
    
    //printf("check_col_up: %i\n", check_col_up(matrix, 2, sqrlen, 2));
    
    //printf("solution_is_correct: %i\n", solution_is_correct(matrix_copy, input_tab));
    
    
    
    
    get_solution(matrix, matrix_copy, sqrlen, input_tab);
    // clean_matrix(matrix, sqrlen);

    free_tab(input_tab);
    free_matrix(matrix, sqrlen);
    return (0);
    (void)matrix_copy;
    (void)matrix;
}