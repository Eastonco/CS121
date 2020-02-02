#include "Header.h"

int main(void) {
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" }; //sets suits

	const char *face[13] = { "Ace", "Duce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" }; // sets faces 

	int deck[4][13] = { 0 };

	int card_num = 1;
	char change_cards = '\0';

	Card p1_hand[5] = { { 0, 0, 0 } };
	Card p2_hand[5] = { { 0, 0, 0 } };
	
	srand(time(NULL)); //seed random-number generator

	puts("*****WELCOME TO POKER*****");
	system("pause");
	system("cls"); //wlecome screen

	shuffle(deck);
	deal(deck, face, suit, p1_hand, 5, &card_num, -1); //deals hand for both players 
	deal(deck, face, suit, p2_hand, 5, &card_num, -1);
	sort_hand(p1_hand);// sorts hand for player 1
	print_hand(p1_hand, face, suit); //prints the hand
	int p1_combo = analyze_hand(contains_pair(p1_hand), contains_two_pair(p1_hand), three_of_a_kind(p1_hand), four_of_a_kind(p1_hand), is_flush(p1_hand), is_straight(p1_hand));
	printf("Your highest combonaiton is a %s\n", num_to_words(p1_combo));  //analyzes hand and tells player
	printf("would you like to switch out any cards (y/n): ");
	scanf("%c", &change_cards);
	if (change_cards == 'y') { //asks if user wants to swap out cards
		int card_choice = 0;
		int change_num = 0;
		do { //loops until player breaks out of loop with 10 or until 3 cards are drawn 
			change_num++;
			system("cls");
			sort_hand(p1_hand);
			print_hand(p1_hand, face, suit);
			p1_combo = analyze_hand(contains_pair(p1_hand), contains_two_pair(p1_hand), three_of_a_kind(p1_hand), four_of_a_kind(p1_hand), is_flush(p1_hand), is_straight(p1_hand));
			printf("Your highest combonaiton is a %s\n", num_to_words(p1_combo)); //reanalyzes hand after draw
			puts("if you want to continue with your cards, enter '10'");
			printf("Which card would you like to switch out (1-5): ");
			scanf("%d", &card_choice);
			if (card_choice == 10) //checks for break
				break;
			deal(deck, face, suit, p1_hand, 1, &card_num, (card_choice-1));
		} while (change_num < 3);
	}
	system("cls");
	print_hand(p1_hand, face, suit); //analyzes and prints fianl hand
	p1_combo = analyze_hand(contains_pair(p1_hand), contains_two_pair(p1_hand), three_of_a_kind(p1_hand), four_of_a_kind(p1_hand), is_flush(p1_hand), is_straight(p1_hand));
	printf("Your final combonaiton is a %s\n", num_to_words(p1_combo));
	system("pause"); //pause and clear screen
	system("Cls");
	printf("The computer's turn\n");
	sort_hand(p2_hand);
	int num_change = rand() % 4; //compuer is not smart and plays the game to the best of it's ability which is nothing
	printf("It chooses to switch out %d cards\n", num_change);
	for (int i = 0; i < num_change; i++) {
		deal(deck, face, suit, p2_hand, 1, &card_num, ((rand() % 5)));
	}
	int p2_combo = analyze_hand(contains_pair(p2_hand), contains_two_pair(p2_hand), three_of_a_kind(p2_hand), four_of_a_kind(p2_hand), is_flush(p2_hand), is_straight(p2_hand));
	printf("It's new highest combonation is a %s\n", num_to_words(p2_combo)); 
	system("pause");
	system("cls");
	int winner = decide_winner(p1_combo, p2_combo); //determiens winner and prints winner by comparing the best hand each person has
	if (winner == 1)
		printf("Player 1 wins!\n");
	if (winner == -1)
		printf("The computer wins!\n");
	if (winner == 0)
		printf("It's a tie!\n");
	
	


	return 0;
}