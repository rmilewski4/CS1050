//
// Created by matt on 12/11/21.
//

#include "battle.h"
#include <limits.h>
Player *readPlayersIntoArray(const char *playerFilename, const char *monsterFilename, int *numPlayers){
    FILE * playerfile;
    playerfile = fopen(playerFilename,"r");
    FILE * monsterfile;
    monsterfile = fopen(monsterFilename,"r");
    int  monsterrows = 0;
    fscanf(monsterfile,"%d", &monsterrows);
    Data  * monsters = malloc(sizeof(Data) * (monsterrows));
    if(NULL != monsterfile) {
        while(!feof(monsterfile) && monsterfile) {
            for(int x = 0;x<monsterrows;x++) {
                fscanf(monsterfile,"%s %s",monsters[x].monster,monsters[x].attack);
            }

        }
    fclose(monsterfile);
    }
    fscanf(playerfile,"%d", numPlayers);
    Player * playerarr = malloc(sizeof(Player) * (*numPlayers));
    int monsterindex= 0;
    if(playerfile!=NULL) {
       // while(!feof(playerfile)&&playerfile) {
            for(int i = 0; i<*numPlayers;i++) {
                fscanf(playerfile,"%s %d %s %d",playerarr[i].name,&playerarr[i].gamesPlayed,playerarr[i].time,&monsterindex);
                strcpy(playerarr[i].monster,monsters[monsterindex].monster);
                strcpy(playerarr[i].attack,monsters[monsterindex].attack);
            }
       // }
        fclose(playerfile);
    }
    free(monsters);
    return playerarr;
}

char *whoHasMostExperience(Player *players, int numPlayers){
    int index = 0;
    int numplayed = 0;
    for (int i = 0; i< numPlayers;i++) {
        if(players[i].gamesPlayed > numplayed) {
            numplayed = players[i].gamesPlayed;
            index = i;
        }
    }
    return players[index].name;
}

char *whoHasLeastExperience(Player *players, int numPlayers){
    int index = 0;
    int numplayed = INT_MAX;
    for (int i = 0; i< numPlayers;i++) {
        if(players[i].gamesPlayed < numplayed) {
            numplayed = players[i].gamesPlayed;
            index = i;
        }
    }
    return players[index].name;
    return NULL;
}

char *whoLeavesFirst(Player *players, int numPlayers){
    int timeindex = 0;
    for(int i = 1;i<numPlayers;i++) {
        if(strcmp(players[i].time,players[timeindex].time) < 0) {
            
            timeindex = i;
        }
    }
    return players[timeindex].name;
}

char *whoLeavesLast(Player *players, int numPlayers){
    int timeindex = 0;
    for(int i = 1;i<numPlayers;i++) {
        if(strcmp(players[i].time,players[timeindex].time) > 0) {
            
            timeindex = i;
        }
    }
    return players[timeindex].name;
}

char *whoPlaysFirst(Player *players, int numPlayers, PlayOrder playOrder){

    switch(playOrder) {
        case 0:
            return whoHasMostExperience(players,numPlayers);
        break;

        case 1:
            return whoHasLeastExperience(players,numPlayers);
        break;

        case 2:
            return whoLeavesFirst(players,numPlayers);
        break;

        case 3:
            return whoLeavesLast(players,numPlayers);
        break;

        default:

        break;
    }
    return "JimR";
}

char *battle(Player *players, int numPlayers, char *player1Name, char *player2Name){
    int p1index = 0;
    int p2index = 0;
    for(int i = 0;i<numPlayers;i++) {
        if(strcmp(players[i].name,player1Name)==0) {
            p1index = i;
        }
        else if(strcmp(players[i].name,player2Name)==0) {
            p2index = i;
        }
    }
    if(strcmp(players[p1index].attack,players[p2index].attack) > 0) {
        return players[p1index].name;
    }
    else {
        return players[p2index].name;
    }
    
}

void freePlayers(Player *players){
    free(players);
}
