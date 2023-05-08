/*****************************************************************************
 * CS1050
 * SP2021
 * Lab  (with bonus)
 * By Ryan Milewski (rsmbby)
 * November 12, 2021
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include "fight.h"
int main(int argc, char * argv[])
{   
    //Checking to see if there is the right amount of arguments (4 arguments), if not, then print the syntax and exit the program.
    if(argc != 4) {
        printf("*** Error: Incorrect number of arguments\n***Syntax:\n./a.out combatant_file combatant1_name combatant2_name\n\n");
        return 0;
    }
    //Copy the file name to the filename string and since it is at index 1 of argv, use that as the source.
    char filename[256];
    strcpy(filename,argv[1]);
    //Creating all of my variables that will be used in the data collection. All of the data will be stored in the temps.
    int tempac, temphp, temphitbonus;
    char tempattack1damage[256];
    char tempattack2damage[256];
    //Since each monster needs its own one of these variables, we have to create them separately, then assign them accordingly later
    int monsterac = 0, monsterhp = 0, monsterhitbonus = 0;
    int monster2ac = 0, monster2hp = 0, monster2hitbonus = 0;
    //Same with each of the string variables, we need two sets of each for each monster later.
    char monsterattack1damage[256];
    char monsterattack2damage[256];
    char monster2attack1damage[256];
    char monster2attack2damage[256];
    char monster[256];
    char monsterfinal[256] = "NotAName";
    //Copying the first monster to monsterfinal from index 2 of argv
    strcpy(monsterfinal, argv[2]);
    char name[256];
    char namefinal[256] = "NotAName";
    strcpy(namefinal, argv[3]);
    //Create and open the file.
    FILE * fp;
    fp = fopen(filename,"r");
    //If the file is able to be opened, enter this if.
    if (NULL!=fp) {
        //Read the first line which is just the header, which will be just discarded since we don't need it.
        fgets(name,255,fp);
        name[255]='\0';
        tempattack1damage[255] = '\0';
        tempattack2damage[255]  = '\0';
        //While the file is still opened, and we haven't reached the end of the file, run this while loop.
        while (fp && !feof(fp))
        {
            int scanfcount = 0;
            //Set fscanf equal to a variable that will hold the number of outputs returned, and since it should be six each time, we compare it to six to move on.
            scanfcount = fscanf(fp," %d,%d,%d,%[^,],%[^,],%s,",&tempac,&temphp,&temphitbonus,tempattack1damage,tempattack2damage,monster);
            if(6==scanfcount) {
                //If the monster is the same as the hardcoded monster above, enter the if.
                if(strcmp(monsterfinal,monster) == 0) {
                    //Set the values into the coded variables above accordingly.
                    monster2ac = tempac;
                    monster2hp = temphp;
                    monster2hitbonus = temphitbonus;
                    //We have to use the strcpy function to copy strings, instead of just setting them equal to each other.
                    strcpy(monster2attack1damage,tempattack1damage);
                    strcpy(monster2attack2damage,tempattack2damage);
                }
                //We will do the same thing for the other monster, but we are checking a different hardcoded. We will fill
                //variables accordingly except for the other monster.
                if(strcmp(namefinal,monster) == 0) {
                    monsterac = tempac;
                    monsterhp = temphp;
                    monsterhitbonus = temphitbonus;
                    strcpy(monsterattack1damage,tempattack1damage);
                    strcpy(monsterattack2damage,tempattack2damage);
                }
            }
        }
        //Of course, we need to close the file when we're done.
        fclose(fp);
    }
    else{
        //Error checking to see if the file can be opened.
        printf("*** Error:  Unable to open %s\n",filename);
        return 0;
    }
    //Checking if the either monster is in the file, (If it was in the file, the sum of their ac, hp, and hitbonus would obviously be greater than 0)
    //So if it is equal to zero, then the monster was never found in the file, and these variables were never set accordingly, therefore
    //The monster must not exist and we should exit the program
    if((monster2ac + monster2hp + monster2hitbonus) == 0) {
        printf("*** Error: Could not find the combatant %s\n",monsterfinal);
        return 0;
    }
    //We will do the same for the other monster, but with its variables
    if((monsterac + monsterhp + monsterhitbonus)==0) {
        printf("*** Error:  Could not find the combatant %s\n",namefinal);
        return 0;
    }
    //If we get through all of this, then we need to actually run the fight command with the correct variables!
    Fight(monsterfinal,monster2ac,monster2hp,monster2hitbonus,monster2attack1damage,monster2attack2damage,namefinal,monsterac,monsterhp,monsterhitbonus,monsterattack1damage,monsterattack2damage);
    // Uncomment the following line if you want to try a sample fight
    //Fight("JimR",21,900,10,"5d6+5","5d12+5","Lar",5,100,5,"1d6","N/A");
}
