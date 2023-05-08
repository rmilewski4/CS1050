#include <stdio.h>
#define SIZE 256
int strlength(char * str);
void getstr(char * str);
void reversestr(char * str, int strlen);

int main(void) {
    printf("***Welcome to Prelab 9***\n");
    char str[SIZE];
    getstr(str);
    int strlen = strlength(str);
    printf("That string is %d in length.\n",strlen);
    reversestr(str,strlen);
    printf("The reversed string is : %s\n",str);
    strlen = strlength(str);
    printf("That string is %d in length.\n",strlen);
    printf("*** Thanks for doing Prelab 9 ***\n");
}

void getstr(char * str) {
    printf("Please enter a string: ");
    scanf("%s",str);
}

int strlength(char * str) {
  //  int count = 0;
    int inc = 0;
    while(*(str + inc) != '\0') {
        inc++;
    }
    return inc;
}
void reversestr(char * str, int strlen) {
    int start = 0;
    char temp = ' ';
    for(int i = strlen - 1; i >= (strlen / 2); i--) {
        temp = *(str + start);
        *(str + start) = *(str + i); //copies end value to beginining of str
        *(str + i) = temp;//copies beginning value to end.
        start++;
    }
        

}