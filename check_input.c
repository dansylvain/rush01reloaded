#include "headerfile.h"

int get_digit_nbr(char *str)
{
    int i;
    int digit_nbr;

    i = 0;
    digit_nbr = 0;
    while (str[i])
    {
        if(isnum(str[i]))
            digit_nbr++;
        i++;
    }
    return (digit_nbr);
}
//***********************************************************************

int chars_arevalid(char *str)
{
    int i;
    int digit_nbr;

    digit_nbr = get_digit_nbr(str);
    i = 0;
    while (str[i])
    {
        if ((!isnum(str[i]) && str[i] != ' ') || str[i] - 48 > digit_nbr / 4)
            return (0);
        i++; 
    }
    return (1);
}
//***********************************************************************

int digits_areseparate(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (isnum(str[i]) && isnum(str[i - 1]) && i != 0)
            return (0);
        i++; 
    }
    return (1);
}
//***********************************************************************

int inputstr_isvalid(char *str)
{
    int digit_nbr = get_digit_nbr(str);
    if (digit_nbr == 0 || digit_nbr > 36 || digit_nbr % 4 != 0)
        return (0);
    if (!chars_arevalid(str))
        return (0);
    if (!digits_areseparate(str))
        return (0);
    return (1);
}