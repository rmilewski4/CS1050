/***************************************************************
 * Course:      CS 1050H
 * Semester:    Fall 2021
 * Date:        October 15, 2021
 * Lab:         Lab 7
 * Author:      Ryan Milewski
 * Pawprint:    rsmbby
 * *************************************************************/

#include <stdio.h>
//Defines given function prototypes
void GetIntArray(int *outputArray, int *count);
void PrintArray(int*array, int count);
int TotalArray(int * array, int count);
float AvgArray(int *array, int count);


int main(void) 
{
    printf("************************\n*  Welcome to Lab 7-8  *\n************************\n\n");
    //Initialize Variables that will hold the number of values that will be entered into the array and the array itself.
    int count = 250;
    int arr1[count];
    //Populate the array using the created array and the address of count, so it can be changed.
    GetIntArray(arr1,&count);
    //Print the array by calling the function and giving it the array and the value of count
    PrintArray(arr1,count);
    //Print the total using the TotalArray function, then print the average using the AvgArray function, with both inputting
    //the array and the size of it
    printf("Total of array = %d\n",TotalArray(arr1,count));
    printf("Average of array = %.2f\n",AvgArray(arr1,count));


    //Honors extension, create a new count variable and a new array.
    int arr2count = 250;
    int arr2[arr2count];
    //Use the GetIntArray Function again to populate the array and find out how big it will be.
    GetIntArray(arr2,&arr2count);
    //Find the total of both arrays by calling the totalarray function for both.
    int TotalBoth = TotalArray(arr1,count) + TotalArray(arr2,arr2count);
    //print the total using the totalBoth variable that was just created.
    printf("Total of array and array2 = %d\n", (TotalBoth));
    //Find the average of both arrays by using that total both and dividing by both counts combined.
    printf("Average of array and array 2 = %.2f\n", ((float)TotalBoth) / (count + arr2count));
}

//This will find the size of the array, by taking in the array (which is a pointer itself to the first element), and the pointer to count
void GetIntArray(int *outputArray, int *count) {
    printf("Enter the number of elements in the array\n");
    //After asking for the number of elements to be in the array, it will return the value that the user enters and place it inside of count
    scanf("%d",count);
    //for loop that will go from 0 to the value of count using the dereference operator to go through each array element
    for(int i = 0; i < *count;i++) {
        //will ask the user to enter whatever element
        printf("Enter element #%d:",i);
        //places the entered value into the array at the index of the given for loop time
        scanf("%d",(&outputArray[i]));
    }
}

//Prints the array by taking in the array as a pointer and the number of values
void PrintArray(int*array, int count) {
    printf("\nHere are the %d elements of your array:\n",count);

    for(int i = 0; i < count; i++) {
        //Prints the element of the array by using the for loop.
        printf("\tElement %d = %d\n",i,array[i]);
    }
}

//Will total the values currently in the array using the array as a pointer and the size of it.
int TotalArray(int * array, int count) {
    //Create a total variable to store values and initalize it to 0.
    int total = 0;
    for(int i = 0; i< count;i++) {
        //Go through the for loop and add up each element of the array up to count-1.
        total += array[i];
    }
    //return whatever total is equal to.
    return total;
}
//Finds the average of the array taking in the array as a pointer and the size of it.
float AvgArray(int *array, int count) {
    //Create a float called average to store the values in, init to 0.
    float avg = 0;
    for(int i = 0; i< count;i++) {
        //Similar to TotalArray, add up all of the values inside the array using a for loop
        avg += array[i];
    }
    //Find the average by dividing the total by the number of values there were, and return that value.
    avg /= count;
    return avg;
}
