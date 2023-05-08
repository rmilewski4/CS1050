#include <stdio.h>
int main(void) {
    int limit = 0;
    int xcubed = 0;
    printf("Please enter a limit: ");
    scanf("%d", &limit);
    for(int x = 0;x*x*x <= limit; x++) {
        xcubed = x*x*x;
        printf("%d",xcubed);
        switch(xcubed % 3) {

            case 0:
            printf("*\n");
            break;

            default:
            printf("\n");
            break;
        }
    }
}
