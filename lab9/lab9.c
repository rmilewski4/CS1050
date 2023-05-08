/***************************************************************
 * Course:      CS 1050H
 * Semester:    Fall 2021
 * Date:        October 29, 2021
 * Lab:         Lab 9
 * Author:      Ryan Milewski
 * Pawprint:    rsmbby
 * *************************************************************/
#include <stdio.h>
//Function prototypes
int getstrsegments(char * str, int segmentlength, int * strlen);
void getstr(char * str, int * segmentlength);
void reversestr(char * str, int numsegments, int segmentlength, int strlen);

int main(void) {

    printf("*** Welcome to Lab 9 ***\n");
    //Variables that will be used, segment length is for the honors extension, which will hold how long
    //each segment will be, the string itself, the number of segments there will be, and the length of the string
    int segmentlength = 0;
    char str[256];
    int numsegments = 0;
    int strlen = 0;
    //call to the get string function that will get the string and the segment length
    getstr(str,&segmentlength);
    printf("You entered: %s\n",str);
    //Find the number of segments by calling the getstrsegments function
    numsegments = getstrsegments(str,segmentlength, &strlen);
    //PRint the number of segments and length
    printf("There are %d segments in the string.\n",numsegments);
    //call the reversestr function
    reversestr(str,numsegments,segmentlength,strlen);
    //print the modified string and goodbye message
    printf("The modified string is :%s\n",str);
    printf("*** Thanks for doing Lab 9 ***\n");
}
//The getstr function takes in the string as a char pointer and the segment length as a int pointer
void getstr(char * str, int * segmentlength) {
    printf("Please enter a string: ");
    scanf("%s",str);
    //Putting the values of each specified procedure into their respective variables using scanf
    printf("Please enter a segment length: ");
    scanf(" %d", segmentlength);
}
//Gets the number of segments by taking in the string as a char pointer, the segment length and stringlength as a pointer, which will be returned
//to main as well.
int getstrsegments(char * str, int segmentlength, int * strlen) {
    int counter = 0;
    int numsegments = 0;
    //This will go through each letter of the string until it hits the null terminator
    while(*(str + counter) != '\0') {
        //If the counter finds a full segment using modular division add one to the number of segments.
        if(counter % segmentlength == 0) {
            numsegments++;
        }
        counter++;
    }
    //Set the length equal to the counter using a pointer and return the number of segments.
    *strlen = counter;
    return numsegments;
}
//Reverse the strings using segments by taking in the string itself, the number of segments, the segement length for the honors extension,
//And the length of the string.
void reversestr(char * str, int numsegments, int segmentlength, int strlen) {
    //Create a temp string that will hold the temp string and a counter to count up for the temp string
    char temp[256];
    int count = 0;
    //This loop will go through the number of segments starting at the greatest, through 0 counting down
    for(int i = numsegments - 1; i>=0;i--){
        //This is for the ending fragment, so it will get its own loop to add to temp
        if(i == numsegments - 1){
            //If this is the ending fragment, go from the segmentlength times the ending fragment to the end of the string
            for(int a = segmentlength*i; a <strlen;a++) {
                //Then using pointer arethmetic add the characters to temp.
                *(temp + count) = *(str + a);
                count++;
            }
        }
        else{
            //Similarly if you are on any other segment length, you want to start from the length times i + the segment length to get that number of characters
            for(int z = segmentlength*i; z < (segmentlength*i + segmentlength);z++) {
                //Then add the characters to temp using pointer arethmetic
                *(temp + count) = *(str + z);
                count++;
          }
        }
       
    }
    //This loop is just copying temp to str using pointer arethmetic
    for(int y = 0; y < strlen;y++) {
        *(str + y) = *(temp + y);
    }
  
    
}