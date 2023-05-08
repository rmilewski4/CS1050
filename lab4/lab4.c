/***************************************************************
 * Course:      CS 1050H
 * Semester:    Fall 2021
 * Date:        September 17, 2021
 * Lab:         Lab 4
 * Author:      Ryan Milewski
 * Pawprint:    rsmbby
 * *************************************************************/

#include <stdio.h>

int main(void) 
{
    //Initialize Variables that are needed
    int start= 0;
    int limit= 1;
    int increment= 1;

    //Error checking for the start variable, that will continue prompting for input
    //using a while if start is less than 1 or greater than 150.
    do {
        printf("Enter Start: ");
        scanf("%d", &start);
    } while (start < 1 || start > 150);

    //Error checking using the exact same mechanism as the previous while loop
    //for the limit variable.
    do {
        printf("Enter Limit: ");
        scanf("%d", &limit);
    } while (limit < 1 || limit > 150);

    //Error checking for the Increment. The if is checking if start is greater than
    //limit, which means that the increment should be counting down.
    if(start > limit) {

        //Since the increment should be counting down, the while loop is asking for input
        //until it gets a increment value less than 0 (not including 0 though).
        do {
            printf("Enter Increment: ");
            scanf("%d", &increment);
        } while (increment >= 0);
    }

    //Otherwise, the while loop is going to look for an increment value that is greater
    //than 0 (not including 0).
    else {
        do {
            printf("Enter Increment: ");
            scanf("%d", &increment);
        } while (increment <= 0);
    }
    //Execute Body of Code

    //Using a switch, we check if start is less than or equal to the limit (so the counter
    //should be counting up).
    switch(start <= limit) {
        //If the case is 1, or true, then it will use a for loop with the i variable
        //counting up. It will also evaluate i while it is less than the limit and print i.
        case 1:
            for(int i = start; i <= limit; i += increment) {
                printf("%d ",i);
            }
            break;
        //If the original condition is false, it will use a for loop with a decrementing
        //operator (although it looks like it's adding, it is subtracting since the
        //increment variable holds a negative integer). It will follow the same syntax
        //as the previous loop except starting at the largest number and going down.
        case 0:
            for(int x = start; x >= limit; x += increment) {
                printf("%d ",x);
            }
            break;
    
    }
    //Print a new line for spacing when the program is complete.
    printf("\n");
}
