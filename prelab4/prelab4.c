#include <stdio.h>
int main(void) {
    int limit = 0;
   char star= ' ';
    int xcubed = 0;
    printf("Please enter a limit: ");
    scanf("%d", &limit);
    for(int x = 0;x*x*x <= limit; x++) {
        xcubed = x*x*x;
        printf("%d",xcubed);
        star = (xcubed % 3 == 0) ? '*': ' ';
        printf("%c\n", star);        
    }
}
