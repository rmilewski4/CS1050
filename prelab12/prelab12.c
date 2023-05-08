#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct _Movie {
    char title[30];
    //int64_t grossrevenue; //works on just windows, compiles on TC, but gives warnings (use gcc)
    long long grossrevenue; //compiles fine on either machine.
    int year;
} Movie;
int readMovies(Movie MovieArr[], char * file_name) {
    FILE * filePtr;
    filePtr = fopen(file_name, "r");
    int counter = 0;
    if(NULL != filePtr) {
        while(!feof(filePtr) && filePtr) {
            fscanf(filePtr, "%s %lld %d", MovieArr[counter].title, &MovieArr[counter].grossrevenue, &MovieArr[counter].year);
            counter++;
        }
    }
    return counter;
}
void printMovies(Movie MovieArr[], int numMovies) {
    printf("%30s \t%11s \t%4s\n","Title","Gross","Year");
    for(int i = 0;i<numMovies;i++) {
        printf("%30s \t%11lld \t%4d\n", MovieArr[i].title,MovieArr[i].grossrevenue,MovieArr[i].year);
    }
}
void sortMovies(Movie MovieArr[], int numMovies) {
    Movie hold;
    for(int i = 0; i < numMovies; i++) {
        for(int j = 0; j < numMovies - 1; j++) {
            if(MovieArr[j].year > MovieArr[j+1].year) {
                hold = MovieArr[j];
                MovieArr[j] = MovieArr[j+1];
                MovieArr[j+1] = hold;
            }
        }
    }
}
int main(int argc, char * argv[]) {
    Movie MovieArr[15];
    int numMovies = 0;
    numMovies = readMovies(MovieArr, argv[1]);
    printf("Original:\n");
    printMovies(MovieArr, numMovies);
    sortMovies(MovieArr,numMovies);
    printf("Year:\n");
    printMovies(MovieArr, numMovies);

}