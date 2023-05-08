/*****************************************************************************
 * hw2Template.c
 * By Jim Ries
 * September 22, 2019
 * 
 * This file is "starter code" for CS1050 Homework #2, Fall 2019
 * Students should use this code as a starting point for implementing the 
 * assignment.  Note, however, that code will need to be added to this
 * and it might be necessary to modify some of the provided code in order
 * to meet the specifications provided.
 *****************************************************************************/
#include <stdio.h>

/* Prototypes */
void PrintAtBats(int atbats[]);
void CalculateBattingAverage(int atbats[], float avg[], int indexToCalculate);
void CalculateSluggingPercentage(int atbats[], float pct[], int indexToCalculate);
void PrintResult(float result[]);
void DoCalculations(int atbats1[], int atbats2[], int atbats3[], float battingavg[], float sluggingpct[]);

int main(void)
{
	int player1[] = {0,1,0,1,2,0,0,0,0,-1};
	int player2[] = {3,0,1,0,0,4,0,0,1,0,0,0,0,0,-1};
	int player3[] = {0,0,0,4,2,0,0,0,0,0,1,-1};
	float avg[3] = {0};
	float slug[3] = {0};
	DoCalculations(player1,player2,player3,avg,slug);
	printf("Player 1 at-bats: \n");
	PrintAtBats(player1);
	printf("Player 2 at-bats: \n");
	PrintAtBats(player2);
	printf("Player 3 at-bats: \n");
	PrintAtBats(player3);
	printf("Batting Averages: \n");
	PrintResult(avg);
	printf("Slugging Percentages: \n");
	PrintResult(slug);
}


/* Function Implementations */
void PrintAtBats(int atbats[]) {
	int counter = 0;
	while(atbats[counter] != -1) {
		printf("%d ",atbats[counter]);
		counter++;
	}
	printf("\n");
}

void CalculateBattingAverage(int atbats[], float avg[], int indexToCalculate) {
	int counter = 0;
	float average = 0.0;
	while(atbats[counter] != -1) {
		if(atbats[counter] != 0) {
			average += 1;
		}
		counter++;
	}
	average /= (counter);
	avg[indexToCalculate] = average;

}

void CalculateSluggingPercentage(int atbats[], float pct[], int indexToCalculate) {
	int counter = 0;
	float slug = 0.0;
	while(atbats[counter] != -1) {
		slug += atbats[counter];
		counter++;
	}
	slug /= (counter);
	pct[indexToCalculate] = slug;

}
void PrintResult(float result[]) {
	for(int i =1;i<=3;i++) {
		printf("Player %d:\n\t%.3f\n",i,result[i-1]);
	}
}

void DoCalculations(int atbats1[], int atbats2[], int atbats3[], float battingavg[], float sluggingpct[]) {
	for(int i = 0;i<3;i++) {
		if(i == 0) {
			CalculateBattingAverage(atbats1,battingavg,i);
			CalculateSluggingPercentage(atbats1,sluggingpct,i);
		}
		else if(i == 1) {
			CalculateBattingAverage(atbats2,battingavg,i);
			CalculateSluggingPercentage(atbats2,sluggingpct,i);
		}
		else {
			CalculateBattingAverage(atbats3,battingavg,i);
			CalculateSluggingPercentage(atbats3,sluggingpct,i);
		}
		}

}