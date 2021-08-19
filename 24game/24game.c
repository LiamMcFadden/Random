#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void clear();
static void spaces(char * s);
static void nums(int digits[], int print_flag);

int 
main(char *argv[], int argc)
{
    int score = 0;

    // clear the screen
    clear();
    
    printf("\n\n\t\t\t\t*___The 24 Game___*\n\n\n");
    char welcome[600] = "\tEnter an expression that (numerically) evaluates to 24. Only\n\tmulitiplication, division, addition, and subtraction are allowed.\n\tDivision should use floating point or rational arithmetic, etc, to \n\tpreserve remainders.Brackets are allowed. Forming multiple digit\n\tnumbers from the provided numbers is not allowed. The order of the\n\tdigits does not have to be preserved.\n\n\tCommands:\n\t\t'nums': see your four numbers again\n\t\t'help': see this message again\n\t\t'clear': clear the screen\n\t\t'new': generate a new set of numbers\n\t\t'exit': leave the game\n";
    char separator[100] = "*------------------------------------------------------------------------------*\n";
    printf("%s%s%s", separator, welcome, separator);
    
    // generate random digits
    printf(" > ");
    int digits[4];
    nums(digits, 1);

    // take input
    for (;;) {
        char buf[100];
        printf(" > ");

        if ((fgets(buf, sizeof(buf), stdin)) == NULL) {
            fprintf(stderr, "Error in fgets()\n");
            exit(EXIT_FAILURE);
        }
        
        /**********************/
        /* check for commands */
        /**********************/
        // print original message
        if (!strcmp(buf, "help\n"))
            printf("%s", welcome);

        // print the current numbers
        else if (!strcmp(buf, "nums\n")) {
            for (int i = 0; i < 4; i++)
                printf("{ %d }", digits[i]);
            printf("\n");
        }

        // clear the screen
        else if (!strcmp(buf, "clear\n"))
            clear();

        // generate a new set of numbers
        else if (!strcmp(buf, "new\n"))
            nums(digits, 1);
        
        // exit the game
        else if (!strcmp(buf, "exit\n")) {
            printf("You solved %d sets! Bye.\n", score);
            exit(EXIT_SUCCESS);
        }
        
        /************************/
        /* Parse the expression */
        /************************/
        // remove all spaces
		spaces(buf);

    }
} 


/*
 * Clear the screen with regex
 */
static void
clear()
{
    printf("\e[1;1H\e[2J");
}

/*
 * Generates a set of four random numbers
 *
 * Set print_flag to 1 if you want to display the numbers
 */
static void
nums(int digits[], int print_flag)
{
    for (int i = 0; i < 4; i++) {
        digits[i] = rand() % 9 + 1;
        if (print_flag) 
            printf("{ %d }", digits[i]);
        
    }
    if (print_flag) printf("\n");
}



/*
 * Removes all spaces from a string
 */
static void 
spaces(char* s) 
{
	char* d = s;
    while (*s++ = *d++){ while (*d == ' ') d++; };
}
