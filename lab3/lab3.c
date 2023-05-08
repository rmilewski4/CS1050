/***************************************************************
 * Course:      CS 1050H
 * Semester:    Fall 2021
 * Date:        September 10, 2021
 * Lab:         Lab 3
 * Author:      Ryan Milewski
 * Pawprint:    rsmbby
 * *************************************************************/

#include <stdio.h>

int main(void)
{
    /* initalize the counter to start from 50 so it can count down */
    int counter = 50;

    /* Start of the while loop that will loop until the number gets less than 2 */
    while(counter >=2) {

        /* This if block will check if the number in the counter is evenly divisible
         * by 5 AND if it is evenly divisible by 3 using the mod operator. If it is both
         * then it will print the XY */
        if(counter % 5 == 0 && counter % 3 == 0) {
            printf("XY");
        }
        /* This else if will check if either condition from the first if is true on
         * its own and if so then it will print the specified letter */
        else if(counter % 5 == 0) {
            printf("X");
        }

        else if(counter % 3 == 0) {
            printf("Y");
        }
        /* If none of those conditions end up being true, then it will just print the number
         * from counter */
        else {
            printf("%d", counter);
        }
        
        /*Honors section: This is checking if the counter is a perfect square that will be
         * in use using the OR (||) operator. The use of the OR operator allows for the
         * use of just one if to avoid code repitition */
        if(counter == 36 || counter == 16 || counter == 4) {
            printf("SQUARE\n");
        }
        /*If it isn't a perfect square it will just print a new line to keep formatting
         *right */
        else {
            printf("\n");
        }
        
        /* Decrementing the counter by 2 to make sure it only gets even integers for the
         * loop */
        counter -= 2;
    }
}
