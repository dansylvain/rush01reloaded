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
//***********************************************************************

int check_args(int argc, char**argv)
{
    if (argc != 2)
    {
        display_error();
        return (1);
    }
    if (!inputstr_isvalid(argv[1]))
    {
        display_error();
        return (1);
    }
    return(0);
}