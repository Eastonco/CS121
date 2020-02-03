/*****************************************************************************
Connor Easton
Class: CptS 121, Spring 2018, Lab Section 12
PA: #5
Date Created: Febuary 15, 2018
Date Last modified: Febuary 23, 2018
Description: This project plays the game of Yahtzee.
******************************************************************************/



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include <Windows.h>

int printMenu(void);
void printRules(void);
int rollDie(void);
bool isValidNum(int num);
int S1_point(int round[]);
int S2_point(int round[]);
int S3_point(int round[]);
int S4_point(int round[]);
int S5_point(int round[]);
int S6_point(int round[]);
int threeOfAKind(int round[]);
int fourOfAKind(int round[]);
void ComboChoicePrint(void);
int Fullhouse(int *saved[]);
int smallStraight(int *saved[]);
int LargeStraight(int *saved[]);
int Yahtzee(int saved[]);
int Chance(int saved[]);


int ComboChoice(int comboChoice, int *list[], int *saved);
bool choicevalid(int num, int *list[]);

