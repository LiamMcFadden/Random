#include <stdio.h>
#include <stdlib.h>

int 
main(char *argv[], int argc)
{   
    // clear the screen
    printf("\e[1;1H\e[2J");
    
    printf("\n\n\t\t\t\t*___The 24 Game___*\n\n\n");
    char welcome[500] = "\tEnter an expression that (numerically) evaluates to 24. Only\n\tmulitiplication, division, addition, and subtraction are allowed.\n\tDivision should use floating point or rational arithmetic, etc, to \n\tpreserve remainders.Brackets are allowed. Forming multiple digit\n\tnumbers from the provided numbers is not allowed. The order of the\n\tdigits does not have to be preserved. Type 'nums' to see your four\n\tnumbers again. Type 'help' to see this message again.\n";
    printf("*------------------------------------------------------------------------------*\n");
    printf("%s", welcome);
    printf("*------------------------------------------------------------------------------*\n\n");
    
    // generate random digits
    int digits[4] = {0};
    printf(" > ");
    for (int i = 0; i < 4; i++) {
        digits[i] = rand() % 10;
        printf("{ %d }", digits[i]);
    }
    printf("\n");

    // take input
    char buf[100];
    printf(" > ");
    scanf("%s", buf);
    printf("\n");
} 
