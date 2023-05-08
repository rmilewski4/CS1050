/***************************************************************
 * Course:      CS 1050H
 * Semester:    Fall 2021
 * Date:        October 8, 2021
 * Lab:         Lab 6
 * Author:      Ryan Milewski
 * Pawprint:    rsmbby
 * *************************************************************/

#include <stdio.h>

//Creating all the function prototypes, one for doing the multiply arrays, one for the reverse multiply,
//One for initalizing the arrays to populate the values I need into those arrays, and one to print the arrays
void MultArrays(int array1[], int array2[], int arrayOut[], int size);
void ReverseMultiply(int array1[], int array2[], int arrayOut[], int size);
int initalizeArray(int arr[], int begin, int end, int increment);
void PrintArrays(int arr1[], int arr2[], int arr3[], int size);

int main(void) 
{
    //Initialize Variables with my 3 arrays all that have 100 elements that all equal 0 to remove garbage values
    int array1[100] = {0};
    int array2[100] = {0};
    int array3[100] = {0};

    //I also included an array size variable which is needed each time I run through a for loop so I know when to stop
    int arrsize = 0;

    //Execute Body of Code

    //Call the initalize array function and use the values given to populate array1 and array2 repectively
    //Since they both have the same size, we only need to set arrsize to one of them to get the size returned
    arrsize = initalizeArray(array1,1,31,3);
    initalizeArray(array2,2,52,5);

    //Do the multiplication by calling MultArrays and putting in all 3 arrays with their size
    MultArrays(array1,array2,array3,arrsize);
    //Print Results
    printf("First Arrays: \n");
    //Call the PrintArrays Function to print the Arrays Nicely
    PrintArrays(array1,array2,array3,arrsize);

    //Honors extension with Reverse Multiply
    //Do the same thing as MultArrays, but overwrite those values with the values that will be done in
    //ReverseMultiply
    ReverseMultiply(array1,array2,array3,arrsize);

    //Similarly, we print the arrays using the PrintArrays Function again
    printf("First Arrays Reverse Multiplied: \n");
    PrintArrays(array1,array2,array3,arrsize);

    //Second group of arrays with same process as before, except with new numbers being placed
    //into initalizeArray
    arrsize = initalizeArray(array1, 22, 0, 2);

    //NOTE: I put 7 in as the ending value as stated from the Canvas announcement
    initalizeArray(array2,84,7,7);
    MultArrays(array1,array2,array3,arrsize);
    //Print results
    printf("Second Arrays: \n");
    PrintArrays(array1,array2,array3,arrsize);
    
    //Honors section with second arrays
    ReverseMultiply(array1,array2,array3,arrsize);
    printf("Second Arrays Reverse Multiplied: \n");
    PrintArrays(array1,array2,array3,arrsize);
}

//InitalizeArray function takes in an array to initalize, the first value to set, the last value, and what to increment between them
int initalizeArray(int arr[], int begin, int end, int increment) {
    //Create an increment variable to count up in the loop so each value is going to its own element.
    //This same value will then be returned as the size of the array
    int inc = 0;

    //This is checking if the first value is smaller than the last because if it is, then the loop will
    //count up when placing values into the array, otherwise the loop will count down.
    if(begin < end) {

        //This for loop is done for the first set of arrays by entering the if. It will just count
        //up using the values given and set the array of the increment variable equal to the loop variable
        for(int i = begin;i <= end;i += increment) {
            arr[inc] = i;
            inc++;
        }
    }
    else {

        //for loop done for the second set of arrays that starts at the biggest value and counts down using an if
        for(int i = begin; i >= end; i -= increment) {
            arr[inc] = i;
            inc++;
        }
    }

    //returning the size of the populated array
    return inc;
}

//Multiplying the arrays by taking in the first two arrays, the result array, and the size
void MultArrays(int array1[], int array2[], int arrayOut[], int size) {
    
    //for loop that is going from the lowest array value (0), to the greatest which is i<size.
    for(int i = 0;i<size;i++) {

        //setting the specified arrayOut equal to the array1 element of i, times the array2 element of i
        arrayOut[i] = (array1[i] * array2[i]);
    }

}

//Prints all 3 Arrays by taking in each and the size of them
void PrintArrays(int arr1[], int arr2[], int arr3[], int size) {

    //for loop that goes from the 0th element in the arrays to the largest which is size-1
    for (int i = 0;i<size;i++) {
        //Printing each element of the array on the same line with some formatting using %2d or %4d

        printf("\tArray 1 Element %2d = %2d Array 2 Element %2d = %2d Array 3 Element %2d = %4d\n"
        ,i,arr1[i], i, arr2[i], i, arr3[i]);

    }
}

//Doing the ReverseMultiply Honors extension by taking in each array and the size
void ReverseMultiply(int array1[], int array2[], int arrayOut[], int size) {
    //for loop similar to the one in MultArrays
    for(int i = 0;i<size;i++) {

        //setting the ith element in the result array to the for loop variable of the first array
        //times the size-1 - i of array2. Size -1 is needed because the first index of an array
        //is 0 not 1. We subtract from that of i so we stay on the same page as array1.
        arrayOut[i] = array1[i] * array2[(size-1) - i];
    }
}
