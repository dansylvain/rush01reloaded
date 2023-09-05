#include "headerfile.h"

void    display_error(void)
{
    write(1, "Error\n", 6);
}
//***********************************************************************

int isnum(char c)
{
    if (c >= '1' && c <= '9')
        return (1);
    else
        return (0);
}

int get_sqrlen(int ***matrix)
{
    int sqrlen;

    sqrlen = 0;
    while (matrix[0][0][sqrlen] != 10)
    {
        sqrlen ++;
    }
    return (sqrlen);
}
//***********************************************************************

