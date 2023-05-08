#include <stdio.h>
#include <math.h>
int myPow(int, int);

int main(void) 
{
    for(int x = 1;x<=6;x++) 
    {
        for(int y = 1;y<=5;y++) 
        {
            printf("myPow(%d,%d) = %5d ",x,y,myPow(x,y));
            printf("pow(%d,%d) = %d\n",x,y,(int)pow(x,y));
        }
    }
}

int myPow(int x, int y) 
{
    int power;
    power = x;
    for(int i = 1;i<y;i++) 
    {
        power *= x;
    }
    return power;
}
