#include <stdio.h>   // Include the standard input/output header file.

void main()
{
    int chk_year;   // Declare an integer variable 'chk_year'.

    printf("Input a year :");   // Prompt the user to input a year.
    scanf("%d", &chk_year);   // Read and store the user's input in 'chk_year'.
    if ((chk_year % 400) == 0)   // Check if 'chk_year' is divisible by 400 with no remainder.
        printf("%d is a leap year.\n", chk_year);   // Print a message indicating that 'chk_year' is a leap year.
    else if ((chk_year % 100) == 0)   // Check if 'chk_year' is divisible by 100 with no remainder.
        printf("%d is not a leap year.\n", chk_year);   // Print a message indicating that 'chk_year' is not a leap year.
    else if ((chk_year % 4) == 0)   // Check if 'chk_year' is divisible by 4 with no remainder.
        printf("%d is a leap year.\n", chk_year);   // Print a message indicating that 'chk_year' is a leap year.
    else
        printf("%d is not a leap year \n", chk_year);   // Print a message indicating that 'chk_year' is not a leap year.
}
