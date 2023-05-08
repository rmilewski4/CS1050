/*
 * CS1050
 * Fall 2021
 * Prelab 11 
 * by Ryan Milewski
 */
#include <stdio.h>

// Symbolic Constants
#define FILENAME "DnDMonsterScores.csv"

// Main
int main(void)
{
    FILE * fp;
    char name[256];
    int count = 0;
    double avgAC = 0;
    double avgHP;
    fp = fopen(FILENAME,"r");
    // Only keep going if we are able to open the file
    if (NULL!=fp)
    {
        fgets(name,255,fp);
        name[255]='\0';
        printf("Header line was: %s\n",name);

        // Read some important data
        while (fp && !feof(fp))
        {
            int ac,hp,dummy;
            

            // Only print if we can read all of the (9) fields we expect
            if (9==fscanf(fp," %[^,],%d,%d,%d,%d,%d,%d,%d,%d,",
                name,&ac,&hp,&dummy,&dummy,&dummy,&dummy,&dummy,&dummy))
            {   
                count++;
                avgAC += ac;
                avgHP += hp;
                printf("%d) \"%s\" : AC=%d,HP=%d\n",count,name,ac,hp);
            }
        }
        printf("Total monster count = %d\n",count);
        printf("Average AC = %.2f\n", avgAC / count);
        printf("Average HP = %.2f\n", avgHP / count);
        // If you successfully open a file, you had better close it
        fclose(fp);
    }
    else    // Print an error message if we can't open the file
    {
        printf("Unable to open file %s\n",FILENAME);
    }
}
