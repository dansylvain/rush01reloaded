#ifndef HEADERFILE
#define HEADERFILE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//************************ APPLY_INPUT_FILTER.C **************************
void    set_counters(int *x, int *y, int sqrlen);
void    min_filter(int ***matrix, int *y, int *x, int sqrlen);
void    apply_input_filter(int ***matrix,int **input_tab, int sqrlen);

//************************ APPLY_MATRIX_FILTER.C *************************
void    matrix_filter(int ***matrix, int x, int y, int sqrlen);
void    clean_cell(int ***matrix, int x, int y, int sqrl);
void    clean_matrix(int ***matrix, int sqrlen);
void    apply_matrix_filter(int ***matrix, int sqrlen);
//********************** CHECK_INPUT.C ***********************************
int get_digit_nbr(char *str);
int chars_arevalid(char *str);
int digits_areseparate(char *str);
int inputstr_isvalid(char *str);
//********************CHECK_MATRIX_STATE.C *******************************
int cell_iscomplete(int ***matrix, int x, int y, int sqrlen);
int get_matrix_state(int ***matrix, int sqrlen);
//*************************** CREATE_MATRIX.C ****************************
int ***alloc_memo_matrix(int ***matrix);
int ***fill_matrix(int ***matrix, int sqrlen);
int ***create_matrix(int sqrlen);
int ***copy_matrix(int ***matrix, int ***matrix_copy, int sqrlen);

//************************** CREATE_TAB.C ********************************
int **alloc_memo_input_tab(int **input_tab);
int **create_input_tab(char *str);
//*************************** FREE.C *************************************
void free_tab(int **input_tab);
void free_matrix(int ***matrix, int sqrlen);
//************************ FUNC.C ****************************************
void    display_error(void);
int isnum(char c);
int check_args(int argc, char**argv);
//************************ GET_SOLUTION.C ********************************
int    ***get_solution(int ***matrix, int ***matrix_copy, int sqrlen);
//************************ MAIN.C ****************************************
int    check_matrix_state(int ***matrix, int sqrlen);
void    display_solution(int ***matrix, int sqrlen);
void    display_matrix(int ***matrix, int sqrlen);
//**************************** MAX_FILTERS.C *****************************
void    max_filter_top(int ***matrix, int x, int sqrlen);
void    max_filter_bottom(int ***matrix, int x, int sqrlen);
void    max_filter_left(int ***matrix, int x, int sqrlen);
void    max_filter_right(int ***matrix, int x, int sqrlen);
void    max_filter(int ***matrix, int x, int y, int sqrlen);


void    display_input_tab(int **input_tab, int sqrlen);
void    display_matrix(int ***matrix, int sqrlen);



#endif