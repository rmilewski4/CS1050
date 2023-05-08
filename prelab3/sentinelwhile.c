#include <stdio.h>

int main(void) 
{
    printf("Enter a limit to go to: ");
    int limit = 0;
    scanf("%d",&limit);
    int counter = 1;
    while (counter <= limit) {
        if(counter % 2 == 0) {
            printf("Even -- %d\n", counter);
        }
        else {
            printf("Odd -- %d\n", counter);
        }
        counter++;
    }
}
