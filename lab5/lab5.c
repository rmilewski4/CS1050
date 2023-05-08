/***************************************************************
 * Course:      CS 1050H
 * Semester:    Fall 2021
 * Date:        October 1, 2021
 * Lab:         Lab 5 with Honors Extension
 * Author:      Ryan Milewski
 * Pawprint:    rsmbby
 * *************************************************************/


//I included math.h for the honors extension
#include <stdio.h>
#include <math.h>

//declaring function prototypes for the two functions that I will need. I declared factorial which
//I got from JimR's function which will return a long and pass an int. I then created my own
//eCalculation function which will return a double and not take in any arguments.
long factorial(int);
double eCalculation(void);

int main(void) 
{
    //Call the eCalculation function and set it equal to the double e.
    double e = eCalculation();

    //I created a for loop to print all powers of e without rewriting the print statement, going from
    //1 to 5.
    for(int i = 1;i<=5;i++)
    {
        //This printf calculates the power by using the pow function from math.h. It gets e from the previously created
        //e variable and gets the power from the i in the for loop. It will print e (and it's powers) to 3 decimal
        //places using %.3lf 
        printf("e to the %d power = %.3lf\n", i, pow(e,i));
    }
}


//Defining the factorial function that will return a long with a integer parameter called n
long factorial(int n)
{
    //Set the initial result equal to 1
    long result= 1;

    //for loop that will start at the biggest value and multiply those values by result and set that
    //equal to result.
    for(int i= n;i>1;i--)
    {
        result *= i;
    }

    //return the calculated result
    return result;
}

//Defining the eCalculation function that will return a double and takes in no parameters (void)
double eCalculation(void)
{
    //creating a double variable and setting it equal to 1 for the initial 1 in the chain
    //of factorials when calculating e.
    double e = 1;

    //for loop that will go from 1 to 65 to find the factorial of i(65 was the maximum factorial you can get before you
    //get an overflow)
    for(int i = 1;i<65;i++)
    {
        //setting e equal to itself plus 1 divided by the factorial of i (from the for loop), 
        //using the factorial function with a parameter of i. The factorial function needed to be 
        //casted as a double so it could be added correctly. 
        e += 1 / ((double)factorial(i));
    }

    //after the for loop is exited, return e.
    return e;
}
