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
    //Initialize Variables. Start and limit are set to -1 so they can fall into the switch.
    int start= -1;
    int limit= -1;
    int increment= 1;
    //Getting initial start value from the user.
    printf("Enter Start: ");
    scanf("%d", &start);
    //goto label for use instead of a while loop
    startswitch:
    //This switch will check if start is less than 1 or greater than 150.
    switch(start < 1 || start > 150) {
        //If the initial statement returns true (1), then it will ask for another input
        //then using goto, it will go back up to the startswtich label.
        case 1:
        printf("Enter Start: ");
        scanf("%d", &start);
        goto startswitch;
        break;
    }
    //Following similar syntax as the start variable, we will ask the user for an initial
    //value.
    printf("Enter Limit: ");
    scanf("%d", &limit);
    //label to return to the top of the limit switch/
    limitswitch:
    //checking if limit is less than 1 or greater than 150.
    switch(limit < 1 || limit > 150) {
        //If the statement in the switch returned true (1) enter this case and ask the
        //user for another limit.
        case 1:
        printf("Enter Limit: ");
        scanf("%d", &limit);
        //Go to the limitswitch label above the switch and reenter the switch to check
        //the conditions again.
        goto limitswitch;
        break;
    }
    //HONORS EXTENSION
    //Get initial Increment value
    printf("Enter Increment: ");
    scanf("%d",&increment);
    //Increment label for later use
    incrementswitch:
    
    switch(start > limit) {
        //If the start variable is greater than the limit, it will enter this case as it
        //returned true(1). Since start is greater than limit, increment must be a negative
        //number.
        case 1:
            //Using another switch to evaluate if the increment variable is greater than 
            //or equal to 0. If this is the case, it will prompt the user for input again
            //then using the goto it will return to outside the first switch.
            switch(increment >= 0) {
                case 1:
                    printf("Enter Increment: ");
                    scanf("%d", &increment);
                    goto incrementswitch;
                break;
            }
        break;
        //If the outer switch returns false, then that means that limit must be greater
        //than start so increment has to be a positive number.
        case 0:
            //Using similar syntax as the nested switch above, we are checking if the
            //increment variable is a negative number or 0 and if so it will prompt 
            //the user for a new input, then using the goto, return to the first switch.
            switch(increment <= 0) {
                case 1:
                    printf("Enter Increment: ");
                    scanf("%d", &increment);
                    goto incrementswitch;
                break;
            }
        break;
    }
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
