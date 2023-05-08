/***************************************************************
 * Course:      CS 1050
 * Semester:    Fall 2021
 * Date:        September 3, 2021
 * Lab:         Lab 2
 * Author:      Ryan Milewski
 * Pawprint:    rsmbby
 * *************************************************************/

#include <stdio.h>

int main()
{
    /* Declared all initial variables and set them equal to 0 just in case
     * memory decides to dump a random value into it */
    int A= 0;
    int B= 0;
    int C= 0;
    int D= 0;

    /* Prompts the user for input and will give the inital variables values
     * based on what the user inputs using scan. */
    printf("Enter 4 integers (A,B,C,D) separated by spaces: \n");
    scanf("%d %d %d %d", &A, &B, &C, &D);

    /* Just prints the values of all of the initial variables and what was
     * just put inside each */
    printf("\n*** INITIAL VALUES ***\n");
    printf("A=%d\n", A);
    printf("B=%d\n", B);
    printf("C=%d\n", C);
    printf("D=%d\n\n", D);

    /* Start of the arithmetic, I placed the arithmetic in parenthesis
     * just in case something weird doesn't occur with order of operations.
     */
    printf("*** CALCULATED VALUES ***\n");
    printf("The sum of A and D = %d\n", (A + D));
    printf("The product of B and C = %d\n", (B * C));
    printf("The integer quotient of C divided by A = %d\n", (C / A));
    printf("The integer remainded of D divided by C = %d\n", (D % C));
    printf("The product of A and B divided by the quantity sum of C and D = %d\n\n", (A*B) / (C+D));

    printf("*Honors:\n");
    /* This chain of ifs will check if the number is odd or even, and if it
     * is even then it will just do the normal division, otherwise it will 
     * add on a .5 to the end of the number after the quotient. */
    if(A % 2 == 0)
    {
        printf("A/2 = %d\n", (A / 2));
    }
    else
    {
        printf("A/2 = %d.5\n", (A / 2));
    }

    if(B % 2 == 0)
    {
        printf("B/2 = %d\n", (B / 2));
    }
    else
    {
        printf("B/2 = %d.5\n", (B / 2));
    }

    if(C % 2 == 0)
    {
        printf("C/2 = %d\n", (C / 2));
    }
    else
    {
        printf("C/2 = %d.5\n",(C / 2));
    }

    if(D % 2 == 0)
    {
        printf("D/2 = %d\n", (D / 2));
    }
    else
    {
        printf("D/2 = %d.5\n", (D / 2));
    }
}
