#include <stdio.h>

void printArray(int [], int);
int initalizeArray(int [], int, int ,int);

int main(void) {
    int arr[256];
    int arrsize = initalizeArray(arr, 2, 20 , 2);
    printf("First Array\n");
    printArray(arr, arrsize);
    arrsize = initalizeArray(arr,1,97,3);
    printf("Second Array\n");
    printArray(arr,arrsize);
}

void printArray(int arr[], int size) {
    for(int i = 0; i< size; i++) {
        printf("\tElement %d = %d\n",i,arr[i]);
    }
}

int initalizeArray(int arr[], int begin, int end, int increment) {
    int inc = 0;
    for(int i = begin;i <= end;i += increment) {
        arr[inc] = i;
        inc++;
    }
    return inc;
}