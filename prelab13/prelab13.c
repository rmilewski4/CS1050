#include <stdio.h>
#include "basicplayer.h"

typedef struct _stats {
    int AB;
    int Walk;
    int Single;
    int Double;
    int Triple;
    int Homerun;
} Stats;

void printAllStats(BasicPlayer playerarr[], Stats playerStats[], int numplayers) {

    /*playerStats.AB = GetStat(player.id,ATBATS);
    playerStats.Walk = GetStat(player.id,WALKS);
    playerStats.Single = GetStat(player.id,SINGLES);
    playerStats.Double = GetStat(player.id,DOUBLES);
    playerStats.Triple = GetStat(player.id,TRIPLES);
    playerStats.Homerun = GetStat(player.id,HOMERUNS);
    */
   for(int i =0;i<numplayers;i++) {
        printf("ID=%d,Name=%s\n",playerarr[i].id,playerarr[i].name);
        printf("\tAB=%d Walks=%d Singles=%d Doubles=%d Triples=%d HomeRuns=%d\n",playerStats[i].AB,playerStats[i].Walk,playerStats[i].Single,playerStats[i].Double,playerStats[i].Triple,playerStats[i].Homerun);
    }
}
int loadPlayers(BasicPlayer playerarr[], Stats playerStats[]) {
    int counter = 0;
    while(GetNextPlayer(&playerarr[counter])) {
        playerStats[counter].AB = GetStat(playerarr[counter].id,ATBATS);
        playerStats[counter].Walk = GetStat(playerarr[counter].id,WALKS);
        playerStats[counter].Single = GetStat(playerarr[counter].id,SINGLES);
        playerStats[counter].Double = GetStat(playerarr[counter].id,DOUBLES);
        playerStats[counter].Triple = GetStat(playerarr[counter].id,TRIPLES);
        playerStats[counter].Homerun = GetStat(playerarr[counter].id,HOMERUNS);
        counter++;
    }
    return counter;
}
int main(void)
{
    BasicPlayer players[22];
    Stats statsarr[22];
    //int walks;
    int numplayers = loadPlayers(players,statsarr);
    printAllStats(players,statsarr,numplayers);
    /*while (GetNextPlayer(&player))
    {
        printAllStats(player);
        if ((-1)!=(walks=GetStat(player.id,WALKS)))
        {
            printf("%s had %d walks.\n",player.name,walks);
        }*/
    //}
}
