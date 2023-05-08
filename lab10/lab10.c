/***************************************************************
 * Course:      CS 1050H
 * Semester:    Fall 2021
 * Date:        November 5, 2021
 * Lab:         Lab 10
 * Author:      Ryan Milewski
 * Pawprint:    rsmbby
 * *************************************************************/

// includes
#include <stdio.h>
// Need any other includes?
#include <stdlib.h>
#include <ctype.h>

// Symbolic Constants
#define CLEARTEXT \
"Haven't felt right in a week\n"\
"And I'm thinning out\n"\
"And it hurts bad\n"\
"I gotta get back\n"\
"\n"\
"Hot head and dreamless sleep\n"\
"I could just slip down\n"\
"And on the wrong track\n"\
"I gotta get back\n"\
"\n"\
"I wanna spend the entire year\n"\
"Just face down\n"\
"And on my own time\n"\
"I wanna waste mine\n"\
"\n"\
"And spend the rest of it asking myself\n"\
"\"Is this who you are?\"\n"\
"And I don't know\n"\
"It just feels gross\n"\
"\n"\
"I don't think there's anything wrong\n"\
"I don't think there's anything wrong\n"\
"And I don't think there's anything wrong\n"\
"I don't think there's anything wrong\n"\
"\n"\
"Sunlight on the back of my arms\n"\
"Just thins me out\n"\
"To a different time\n"\
"I wanna waste mine\n"\
"\"\\\?\n\n\t\t- Snail Mail"

// Prototypes
void Encrypt(const char * in, char * out, int displacement);
void Decrypt(const char * in, char * out, int displacement);


// Main
int main(void)
{   
    //Creation of variables that hold will hold the encrypted and unencrypted text
    char encrypted[] = CLEARTEXT;
    char decrypted[] = CLEARTEXT;
    //Call to the encrypt function with the symbolic constant and encrypt variable
    Encrypt(CLEARTEXT,encrypted,99);
    //Printf formatting to print the output
    printf("***************************\n");
    printf("* Cleartext:              *\n");
    printf("%s\n",CLEARTEXT);
    printf("***************************\n");
    printf("* CipherText using   99   *\n");
    printf("%s\n",encrypted);
    //Decyrpt call to decrypt the encyrpted functiona and place it in decrypted, which will then be printed.
    Decrypt(encrypted,decrypted,99);
    printf("***************************\n");
    printf("\n*************************\n");
    printf("* Decrypted CipherText:   *\n");
    printf("%s\n",decrypted);
    printf("***************************\n");
}



// Function implementations
void Encrypt(const char * in, char * out, int displacement)
{   
    //Creation of 2 counters, one will be used to count through each characters, the other will count the displacement
    int count = 0;
    int charcount = 0;
    while(*(in + count) != '\0') {
        //If the character is upper case it will enter this if
        if(isupper(*(in + count))) {
            charcount = 0;
            //While the counter is less than the displacement this loop will run.
            while(charcount < displacement) {
                //The output will be equal to itself plus 1 which will shift it one character.
                *(out + count) = *(out + count) + 1;
                //If you hit the max character, you will enter this loop using ASCII values
                if(*(out + count) == 91 ) {
                    //This will then set the charachter back to the beginning (26 letters in the alphabet)
                    *(out + count) = *(out + count) - 26;
                }
                charcount++;
            }
        }
        //The same is repeated if the character is lowercase
        else if(islower(*(in + count))) {
            charcount = 0;
            while(charcount < displacement) {

                *(out + count) = *(out + count) + 1;
                //Except that if the charachter is passed the max ascii for lowercase it will do this if.
                if(*(out + count) == 123 ) {

                    *(out + count) = *(out + count) - 26;
                }
                charcount++;
            }
        }            
        count++;
    }
}

void Decrypt(const char * in, char * out, int displacement) {
    int count = 0;
    int charcount = 0;
    int backcounter = 1;
    int shift = 0;
    while(*(in + count) != '\0') {
        //Similar to encyrpt, it will check if the character is uppercase or lowercase.
        if(isupper(*(in + count))) {
            //I have a new counter that will for help with changing the letter back.
            charcount = 0;
            backcounter = 1;
            while(charcount < displacement) {
                //So this will change out to whatever the input is minus a counter that is counting backwards (subtraction)
                *(out + count) = *(in + count) - backcounter;
                if(*(out + count) == 64 ) {
                    //If this is equal to 64 and we need to loop around, we need to know the current shift of the characters, then change
                    //backcounter to that plus 25 (because it is all 26 characters, plus one for the shift overlap)
                    shift = backcounter;
                    backcounter = -25 + shift;
                }
                //If its not at the end, increment the backcounter normally
                if(*(out + count) != 64) {
                    backcounter++;
                }
                charcount++;
            }
        }
        //This if is the exact same as before, except the ending value to loop around changes from 64 to 96
        else if(islower(*(in + count))) {
            charcount = 0;
            backcounter =1;
            while(charcount < displacement) {

                *(out + count) = *(in + count) - backcounter;
                if(*(out + count) == 96 ) {
                    shift = backcounter;
                    backcounter = -25 + shift;
                }
                
                if(*(out + count) != 96) {
                    backcounter++;
                }
                charcount++;
            }
        }            
        count++;
    }
}
