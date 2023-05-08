#include <stdio.h>

int main(void)
{
    int counter = 1;
    
    while(counter <= 10) {
        if(counter % 2 == 0) {
            printf("even - %d\n", counter);    
        }
        else {
            printf("odd - %d\n", counter);
        }
        counter++;
    }
}
