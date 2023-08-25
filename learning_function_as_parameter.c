#include <stdio.h>
void printNumber(int nbr)  
{
    printf("%d\n", nbr);
}
void myFunction(void (*f)(int), int nbr2)  
{
    for(int i = 0; i < 5; i++) 
    {
        (*f)(i * 2);
        printf("hey hey%i\n", nbr2);
    }
}
