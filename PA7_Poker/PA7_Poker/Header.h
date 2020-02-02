/****************************************************************************
Connor Easton
Class: CptS 121, Spring 2018, Lab Section 12
PA: #7
Date Created: April 3, 2018
Date Last Modified: April 16, 2018
Description: This project plays the game of poker, 5 card draw
***********************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct card {
	//tracking positions of cards in deck
	int suit; // suit
	int face; // face
	int card_num;

}Card;

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], int num_draw, int card_num, int specify);
void sort_hand(Card hand[]);
bool contains_pair(Card hand[]);
bool contains_two_pair(Card hand[]);
bool four_of_a_kind(Card hand[]);
bool three_of_a_kind(Card hand[]);
bool is_flush(Card hand[]);
bool is_straight(Card hand[]);
int analyze_hand(bool pair, bool two_pair, bool three, bool four, bool flush, bool straight);
char *num_to_words(int hand_value);
int decide_winner(int p1_combo, int computer_combo);

void print_hand(Card hand[], const char *wFace[], const char *wSuit[]);
