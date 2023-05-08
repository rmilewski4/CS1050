/*
 * starter_finalexamprep.c
 *
 *  Created on: Dec 7, 2021
 *      Author: Ryan
 */

#include "finalexamprep.h"
Data *readFileIntoArray(const char *filename, int *rows){
    FILE * fp;
    fp = fopen(filename,"r");
    fscanf(fp,"%d", rows);
    Data  * monsters = malloc(sizeof(Data) * (*rows));
    if(NULL != fp) {
        while(!feof(fp) && fp) {
            for(int i = 0;i<*rows;i++) {
                fscanf(fp,"%s %s",monsters[i].monster,monsters[i].attack);
            }

        }
    fclose(fp);
    }
    
    return monsters;
}

char *alphaSortMonster(Data *dataArray, int index){
    char * monsterptr = dataArray[index].monster;
    int stringlen = strlen(monsterptr);
    char * MonsterName = malloc(sizeof(char) * 256);
    strcpy(MonsterName,monsterptr);
    char hold;
    for(int i = 0; i < stringlen; i++) {
            for(int j = 0; j < stringlen - 1; j++) {
                if((MonsterName[j]>MonsterName[j+1])) {
                    hold = MonsterName[j];
                    MonsterName[j] = MonsterName[j+1];
                    MonsterName[j+1] = hold;
                }
            }
        }
    return MonsterName;
}

void freeData(Data *dataArray){
    free(dataArray);
}
