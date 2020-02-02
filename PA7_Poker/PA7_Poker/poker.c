#include "Header.h"

void shuffle(int wDeck[][13]) //shuffles the deck
{
	int row = 0;
	int column = 0;
	int card = 0;

	for (card = 1; card <= 52; card++) {
		do {
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);
		wDeck[row][column] = card;
	}
}

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], int num_draw, int *card_num, int specify)
{
	int row = 0; //row number
	int column = 0; //column numer
	int card = 0; //card counter
	int count = 0;
	if (specify != -1)
		count = specify;
	

	for (card = *card_num; card <= num_draw + *card_num -1; card++) {  //deals each of the 52 cards
		for (row = 0; row <= 3; row++) { // loop through rows of wDeck
			for (column = 0; column <= 12; column++) {
				if (wDeck[row][column] == card) {

					hand[count].suit = row;
					hand[count].face = column;
					hand[count].card_num = card;
					++count;
					//ternary operator ? :
					//printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
				}	
			}
		}
	}
	*card_num += num_draw;
}

void sort_hand(Card hand[]) { //sorts the hand
	int i, j;
	int tmp;

	for (i = 0; i < 4; i++) {
		for (j = i+1; j < 5; j++) {
			if (hand[i].face > hand[j].face) {
				tmp = hand[i].face;
				hand[i].face = hand[j].face;
				hand[j].face = tmp;
			}
		}
	}
}


bool contains_pair(Card hand[]) { //tests for pair

	int count = 0;
	bool is_true = false;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (hand[i].face == hand[j].face)
				count++;
		}
	}
	if (count >= 1)
		is_true = true;
	return is_true;
}

bool contains_two_pair(Card hand[]) { //tests for two pair

	int count = 0;
	bool is_true = false;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (hand[i].face == hand[j].face)
				count++;
		}
	}
	if (count >= 2)
		is_true = true;
	return is_true;
}

bool three_of_a_kind(Card hand[]) { //tests for three of a kind
	bool is_true = false;
	if (hand[0].face == hand[1].face && hand[1].face == hand[2].face)
		is_true = true;
	if (hand[1].face == hand[2].face && hand[2].face == hand[3].face)
		is_true = true;
	if (hand[2].face == hand[3].face && hand[3].face == hand[4].face)
		is_true = true;
	return is_true;
}

bool four_of_a_kind(Card hand[]) { //tests for four of a kind
	bool is_true = false;
	if (hand[0].face == hand[1].face && hand[1].face == hand[2].face &&
		hand[2].face == hand[3].face)
		is_true = true;
	if (hand[1].face == hand[2].face && hand[2].face == hand[3].face &&
		hand[3].face == hand[4].face)
		is_true = true;
	return is_true;
}

bool is_flush(Card hand[]) { //tests for a flush
	int i = 0;
	bool is_true = true;
	for (i = 0; i < 4; i++) {
		if (hand[i].suit != hand[i + 1].suit)
			is_true = false;
	}
	return is_true;
}

bool is_straight(Card hand[]) { //tests for a straight
	bool is_true = true ;
	for (int i = 4; i > 0; i--) {
		if (hand[i-1].face != hand[i].face -1)
			is_true = false;
	}
	return is_true;
}


int analyze_hand(bool pair, bool two_pair, bool three, bool four, bool flush, bool straight){ //analyzes hand with sub catagories
	if (flush && straight)
		return 1;
	else if (straight)
		return 2;
	else if (four)
		return 3;
	else if (three)
		return 4;
	else if (two_pair)
		return 5;
	else if (pair)
		return 6;
	else
		return 7;
}

char *num_to_words(int hand_value) { //convers the hand valuse to a string 
	switch (hand_value)
	{
	case 1:
		return "Straight Flush";
	case 2:
		return "Straight";
	case 3:
		return "Four of a kind";
	case 4:
		return "Three of a kind";
	case 5:
		return "Two Pair";
	case 6:
		return "Pair";
	case 7:
		return "High Card";
	}
}


int decide_winner(int p1_combo, int computer_combo) { //decides the winner
	if (p1_combo < computer_combo)
		return 1;
	if (computer_combo < p1_combo)
		return -1;
	if (p1_combo == computer_combo)
		return 0;
}



void print_hand(Card hand[], const char *wFace[], const char *wSuit[]) {
	int i;
	for (i = 0; i < 5; i++) {
		printf("%d %s of %s\n",(i+1), wFace[hand[i].face], wSuit[hand[i].suit]);
	}
	printf("\n\n");
}