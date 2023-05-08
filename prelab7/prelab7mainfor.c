#include <stdio.h>

void GetCount(int * outputInt);
void GetIntegerArray(int * outputIntArray,int count);
void printArray(int a[], int size);

int main(void) {
    printf("***************************\n*  Welcome to Prelab 7-8  *\n***************************\n");
    int * arrsizeptr = NULL, arrsize = 0;
    arrsizeptr = &arrsize;
  //  int * arrptr = NULL;
    GetCount(arrsizeptr);
    int array[*arrsizeptr];
    
    for(int i = 0; i< arrsize;i++) {
       // arrptr = &array[i];
        GetIntegerArray((array + i),i);
    }

    printArray(array,*arrsizeptr);
}

void GetCount(int * outputInt) {
    printf("How many integers would you like to enter?\n");
    scanf("%d", outputInt);
}

void GetIntegerArray(int * outputIntArray,int count) {
        printf("Enter Integer #%d: ",count +1);
        scanf("%d",outputIntArray);
}

void printArray(int a[], int size) {
    printf("*********************\nYou entered an array with %d elements:\n",size);
    for(int i = 0; i < size; i++) {
        printf("\tarray[%d]=%d\n",i,a[i]);
    }
}