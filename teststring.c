#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void) {
    char str[256] = "HeLLoWOrld";
    int count = 0;
    while(*(str+count)) {
        *(str+count) = toupper(*(str+count));
        count++;
    }
    printf("The string is %s\n",str);
}