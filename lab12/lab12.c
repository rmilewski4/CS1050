/*****************************************************************************
 * CS1050
 * SP2021
 * Lab 12 
 * By Ryan Milewski (rsmbby)
 * November 19, 2021
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
//Creating my struct which will be called with a typedef of Movie. It holds the title which will never be more
//than 50 characters, the gross revenue, which has to be of type long long (8 bytes) to hold the gross which
//is in the billions. Finally the year which is just a regular int.
typedef struct _Movie {
    char title[50];
    long long grossrevenue; 
    int year;
} Movie; 
//countMovies function for the bonus
int countMovies(char * file_name) {
    //Create a file pointer to read in the file and open it.
    FILE * filePtr;
    filePtr = fopen(file_name, "r");
    int counter = 0;
    if(NULL != filePtr) {
        //if the file can be opened, and there is more to be read.
        while(!feof(filePtr) && filePtr) {
            char throwawaytitle[50];
            long long grossthrow;
            int yearthrow;
            //just put the data into throwaway variables since we won't be using it and add one to our counter
            fscanf(filePtr, "%s %lld %d", throwawaytitle, &grossthrow, &yearthrow);
            counter++;        
        }
        //close our file when we're done.
        fclose(filePtr);
    }
    else {
        //If the file can't be opened, print a message and end the program by sending a sentiel value back to main.
        printf("*** Error: Cannot open file %s\n",file_name);
        return -1;
    }
    //return the number of movies.
    return counter;
}
//My readMovies function takes in the movie array and file name.
int readMovies(Movie MovieArr[], char * file_name) {
    //Create a filepointer and open it for reading with fopen and the given file name.
    FILE * filePtr;
    filePtr = fopen(file_name, "r");
    int counter = 0;
    //If the file is able to be opened, procceed.
    if(NULL != filePtr) {
        //While there is still more to be read in the file.
        while(!feof(filePtr) && filePtr) {
            //fScanf into the file, take in the title, revenue, and year which are separated by spaces and place them into
            //the respective array number with the use of the counter
            fscanf(filePtr, "%s %lld %d", MovieArr[counter].title, &MovieArr[counter].grossrevenue, &MovieArr[counter].year);
            counter++;
        }
        //Close our file once we're done with it.
        fclose(filePtr);
    }
    else {
        //If the file can't be opened, print a message and end the program by sending a sentiel value back to main.
        printf("*** Error: Cannot open file %s\n",file_name);
        return -1;
    }
    return counter;
}
//To print the movies, take in the movie array and the number of total  movies.
void printMovies(Movie MovieArr[], int numMovies) {
    printf("Sorted Movies:\n");
    //formatting message with spacing.
    printf("%50s \t%11s \t%4s\n","Title","Gross","Year");
    for(int i = 0;i<numMovies;i++) {
        //Print all of the movies in their respective order.
        printf("%50s \t%11lld \t%4d\n", MovieArr[i].title,MovieArr[i].grossrevenue,MovieArr[i].year);
    }
}
//Function to sort the movies taking in the movie array, then number of movies, the sort field and sort order for honors
void sortMovies(Movie MovieArr[], int numMovies, int sortField, int sortOrder) {
    //CHART FOR UNDERSTANDING WHAT sortField and sortORDER hold:
    //SortField:               Meaning:
    //0                        Title
    //1                        GrossRevenue
    //2                        Year

    //sortOrder:                Meaning:
    //0                         Ascending
    //1                         Descending

    //In each if, it is using bubble sort to sort through the arrays, but is changing things slightly for each one.
    //year and ascending
    if(sortField == 2 && sortOrder == 0) {
        //Create a hold variable otherwise data will be lost.
        Movie hold;
        for(int i = 0; i < numMovies; i++) {
            //Nested for loop so we can fully sort each element.
            for(int j = 0; j < numMovies - 1; j++) {
                //Since we are checking years, we look at the respective year values in the array, and then use the greater than
                //in the if for ascending
                if(MovieArr[j].year > MovieArr[j+1].year) {
                    //If the value ends up being greater than the one next to it, swap the values using the hold variable.
                    hold = MovieArr[j];
                    MovieArr[j] = MovieArr[j+1];
                    MovieArr[j+1] = hold;
                }
            }
        }
    }
    //gross and ascending
    if(sortField == 1 && sortOrder == 0) {
        Movie hold;
        for(int i = 0; i < numMovies; i++) {
            for(int j = 0; j < numMovies - 1; j++) {
                //Same as above, except check grossrevenue
                if(MovieArr[j].grossrevenue > MovieArr[j+1].grossrevenue) {
                    hold = MovieArr[j];
                    MovieArr[j] = MovieArr[j+1];
                    MovieArr[j+1] = hold;
                }
            }
        }
    }
    //title ascending
    if(sortField == 0 && sortOrder == 0) {
        Movie hold;
        for(int i = 0; i < numMovies; i++) {
            for(int j = 0; j < numMovies - 1; j++) {
                //Since we are comparing Strings, just use strcmp instead, and if the first one is bigger than the second (Closer to the
                //beginning of the alphabet), then shift it.
                if(strcmp(MovieArr[j].title,MovieArr[j+1].title) > 0) {
                    hold = MovieArr[j];
                    MovieArr[j] = MovieArr[j+1];
                    MovieArr[j+1] = hold;
                }
            }
        }
    }
    //Year and descending
    if(sortField == 2 && sortOrder == 1) {
        Movie hold;
        for(int i = 0; i < numMovies; i++) {
            for(int j = 0; j < numMovies - 1; j++) {
                //Since we are checking our decsending values now, we change the greater than sign in our if to a less than
                //to sort descending, otherwise it remains the same.
                if(MovieArr[j].year < MovieArr[j+1].year) {
                    hold = MovieArr[j];
                    MovieArr[j] = MovieArr[j+1];
                    MovieArr[j+1] = hold;
                }
            }
        }
    }
    //gross and descending
    if(sortField == 1 && sortOrder == 1) {
        Movie hold;
        for(int i = 0; i < numMovies; i++) {
            for(int j = 0; j < numMovies - 1; j++) {
                if(MovieArr[j].grossrevenue < MovieArr[j+1].grossrevenue) {
                    hold = MovieArr[j];
                    MovieArr[j] = MovieArr[j+1];
                    MovieArr[j+1] = hold;
                }
            }
        }
    }
    //title and descending
    if(sortField == 0 && sortOrder == 1) {
        Movie hold;
        for(int i = 0; i < numMovies; i++) {
            for(int j = 0; j < numMovies - 1; j++) {
                if(strcmp(MovieArr[j].title,MovieArr[j+1].title) < 0) {
                    hold = MovieArr[j];
                    MovieArr[j] = MovieArr[j+1];
                    MovieArr[j+1] = hold;
                }
            }
        }
    }
}
//Need these arguments to read in from command line
int main(int argc, char * argv[]) {
    //Making sure we have the right number of fields from the command line.
    if(argc < 2 || argc > 4) {
        printf("Syntax: ./a.out filename [sort_field [sort_order]]\n");
        printf("\t - sort_field must be one of \"Title\", \"Gross\", or \"Year\" if specified\n");
        printf("\t - sort_order must be one of \"Ascending\" or \"Descending\" if specified.\n");
        return 0;
    }
    int sortFieldnum;
    int sortOrdernum;
    //Getting the number of movies that are in the file using malloc and a countMovies function.
    int numMovies = countMovies(argv[1]);
    if(numMovies == -1) {
        //If the file couldn't be read, then exit the program.
        return 0;
    }
    //Set our MovieArray to be however many movies there are times the size of the struct.
    Movie * MovieArr = malloc(numMovies * sizeof(Movie));
    //Actually read in the movies with that 2nd argument being the file name.
    numMovies = readMovies(MovieArr, argv[1]);
    if(numMovies == -1) {
        //If the file couldn't be read, then exit the program.
        return 0;
    }
    char * sortField;
    if(argc == 2) {
        //If we only have 2 arguments, and the sorting field isn't specified, automatically set it to Title
        sortField = "Title";
    }
    else {
        //Otherwise set it to the 3rd command line argument.
        sortField = argv[2];
    }
    char * sortOrder;
    //Similarly, if there are 4 command line arguments, set the sort order equal to whatever is the 4th argument.
    if(argc == 4) {
        sortOrder = argv[3];
    }
    else {
        //Otherwise default it to ascending
        sortOrder = "Ascending";
    }
    //This is for checking the 2nd field which is the sort field. If it is equal to any of the phrases, set
    //The variable sortFieldnum equal to a specific value which corresponds to the field. See above in the sortMovies function
    //for a chart of their meaning if you can't tell here.
    if(strcmp(sortField,"Title") == 0) {
        sortFieldnum = 0;
    }
    else if(strcmp(sortField,"Gross")== 0) {
        sortFieldnum = 1;
    }
    else if(strcmp(sortField,"Year")==0) {
        sortFieldnum = 2;
    }
    //If we have the right number of argments, but we haven't found the sorting field yet, the user must've
    //entered in an incorrect field, so tell them of the fields and exit.
    else if(argc == 3 || argc == 4){
        printf("Syntax: ./a.out filename [sort_field [sort_order]]\n");
        printf("\t - sort_field must be one of \"Title\", \"Gross\", or \"Year\" if specified\n");
        printf("\t - sort_order must be one of \"Ascending\" or \"Descending\" if specified.\n");
        //before we exit, free the memory declared for MovieArr, otherwise we'll have a memory leak.
        free(MovieArr);
        return 0;
    }
    else {
        //Otherwise set the field equal to 0 for title.
        sortFieldnum = 0;
    }
    //Same as above, but we are checking for ascending or descending and setting a variable that has a different
    //meaning for each accordingly.
    if(strcmp(sortOrder,"Ascending")==0) {
        sortOrdernum = 0;
    }
    else if(strcmp(sortOrder,"Descending")==0){
        sortOrdernum = 1;
    }
    //Once again, if we have the right amount of arguments but it couldn't be found, print the syntax and exit.
    else if(argc == 3 || argc == 4){
        printf("Syntax: ./a.out filename [sort_field [sort_order]]\n");
        printf("\t - sort_field must be one of \"Title\", \"Gross\", or \"Year\" if specified\n");
        printf("\t - sort_order must be one of \"Ascending\" or \"Descending\" if specified.\n");
        //before we exit, free the memory declared for MovieArr, otherwise we'll have a memory leak.
        free(MovieArr);
        return 0;
    }
    else {
        //Otherwise sort ascendingly.
        sortOrdernum = 0;
    }
    //Actually go into the sort function and sort with the created values.
    sortMovies(MovieArr, numMovies, sortFieldnum, sortOrdernum);
    //print the array of movies out with the printMovies function.
    printMovies(MovieArr,numMovies);
    //free our memory declared for array that we made with malloc
    free(MovieArr);
}