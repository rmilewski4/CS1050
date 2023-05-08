#include <stdio.h>

int main(void) {
    int x= 0;
    int y= 0;
/*How to scan for two ints on the same line or is it necessary*/
    printf("Enter two integers separated by spaces:\n");
    scanf("%d %d",&x,&y);
    /*Can you concatenate with printf and integers in them to have less printf statements?*/
    printf("X = %d\n",x);
    printf("Y = %d\n\n", y);
    printf("*** CALCULATED VALUES ***\n");
    printf("X times Y:%d\n", x * y);
    printf("X divided by Y:%d\n", x / y);
    printf("X mod Y (remainder):%d\n",x % y);
    printf("X plus 1, quantity times Y:%d\n", (x+1)*(y));
    printf("*** FINAL VALUES ***\n");
    printf("X = %d\n",x);
    printf("Y = %d\n",y);
}
