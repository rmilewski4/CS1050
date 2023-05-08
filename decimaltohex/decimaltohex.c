#include <stdio.h>
#include <string.h>
char* dectohex(int);

int main(void) {
    int dec = 0;
    printf("Enter a decimal number to be converted to hex: ");
    scanf("%d",&dec);
    printf("%d in hexadecimal is %s\n",dec,dectohex(dec));
}

char* dectohex(int x) {
    char* hex = "";
    int temphex = 0;
    char hexchar = ' ';
    while(x != 0) {
        temphex = x%16;
        
        switch(temphex) {

            case 10:
            hexchar = 'A';
            break;

            case 11:
            hexchar = 'B';
            break;

            case 12:
            hexchar = 'C';
            break;

            case 13:
            hexchar = 'D';
            break;

            case 14:
            hexchar = 'E';
            break;

            case 15:
            hexchar = 'F';
            break;

            default:
            hexchar = (char)temphex;
            break;
        }
        strncat(hex,hexchar,1);
        x /= 16;
    }
}
