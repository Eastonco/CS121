#include "Header.h"

int main(void) {
	srand(time(NULL));
	int player = 1, roll_num = 1, p1_list[13] = { 0 }, p2_list[13] = { 0 }, p1_points = 0, p2_points = 0;
	int num_dice = 5;
	int choice = printMenu();//prints menu
	if (choice == 3) { // tests for quiting command
		puts("Thanks for playing!");
		printf("Goodbye\n\n");
		return 0;
	}
	else {
		int roll[5], i, saved[5] = { 0,0,0,0,0 }, input = 0, round = 1; //variable declaration
		char continueGame = '\0';
		system("pause");
		system("cls");
		do { //do while loop for rounds
			do { //do while loop for rolling per round
				printf("Player: %d\n", player); //prints play # and roll number
				printf("Roll: %d\n", roll_num);
				printf("You rolled: ");
				roll_num++;
				for (i = 0; i < num_dice; i++) { //rolls all 5 dice
					roll[i] = rollDie();
					printf("\n%d. %d ", i + 1, roll[i]);
				}
				printf("\n\nEnter the dice key number you would like to keep separated by an enter\n");
				printf("once finsihed selecting, enter the number 0 or input 10 to select all numbers. \n");
				int attempt = 0;
				//system("pause");
				do {
					attempt++;
					//system("cls");
					if (attempt > 1) { //tests for invalid user input 
						system("cls");
						printf("Invalid user input, please submit a valid choice\n\n");
						attempt--;
					}
					//puts("Your last roll:");
					//for (i = 0; i < 5; i++) { //prints the last roll
					//	printf("%d. %d\n", i + 1, roll[i]);
					//}

					printf("\nNum: ");
					scanf("%d", &input);
					if (isValidNum(input) == true) { //tests for invalid user input
						attempt--;
						if (saved[5] == 0)
							saved[5] = roll[input - 1]; //adds selected dice to saved array 
						else if (saved[4] == 0)
							saved[4] = roll[input - 1];
						else if (saved[3] == 0)
							saved[3] = roll[input - 1];
						else if (saved[2] == 0)
							saved[2] = roll[input - 1];
						else if (saved[1] == 0)
							saved[1] = roll[input - 1];
						else if (saved[0] == 0)
							saved[0] = roll[input - 1];
						num_dice--;
						printf("saved dice: ");
						for (i = 0; i < 5; i++) { //prints saved dice
							if (saved[i] != 0) {
								printf("%d, ", saved[i]);
							}
						}
						Sleep(3000); //pauses to display saved dice

					}
					if (input == 10) { //if input = 10, it adds all dice to the selection
						for (i = 0; i < 5; i++) {
							saved[i] = roll[i];
						}
					}



				} while (input != 0 && input != 10); //tests for breaking for slecting dice
				printf("saved dice: ");
				for (i = 0; i < 5; i++) { //prints saved dice
					if (saved[i] != 0) {
						printf("%d, ", saved[i]);
					}
				}

				if (roll_num <= 3) {
					printf("\nwould you like to use these saved values for a combination? (y/n): "); //asks for use in combination
					scanf(" %c", &continueGame);
					if (continueGame == 'y') {
						break; //breaks out of loop
					}
				}
				system("cls");
			} while (roll_num <= 3); //tests for no more than 3 rolls 

			/*for (i = 0; i < 5; i++) { //adds remaining unused dice to the saved
				if (saved[i] == 0)
					saved[i] = roll[i];
				}
			}*/
			system("cls");
			for (i = 0; i < 5; i++) { //fills any unsaved values from the last one
				if (saved[i] == 0)
					saved[i] = roll[i];
			}
			printf("saved dice: ");
			for (i = 0; i < 5; i++) {
				if (saved[i] != 0) {
					printf("%d, ", saved[i]);
				}
			}
			printf("\nWhich combination would you like to use for this round?\n");
			ComboChoicePrint();
			printf("choice: ");
			int comboChoice = 0;
			scanf("%d", &comboChoice);
			int points = 0;
			if (player == 1) {
				points = ComboChoice(comboChoice, &p1_list, saved);
				p1_points += points;
				printf("Player 1, you have %d points!\n", p1_points);
				Sleep(3000); //pauses to display points;
				player = 2;
			}
			else if (player == 2) {
				points = ComboChoice(comboChoice, &p2_list, saved);
				p2_points += points;
				printf("Player 2, you have %d points!\n", p2_points);
				Sleep(3000); //pauses to display points;
				player = 1;
			}
			system("pause");
			system("cls");
			//resting the roll number and the amount of dice to be rolled
			round++;
			roll_num = 1;
			num_dice = 5;
			for (i = 0; i < 5; i++) { //resets the saved dice
				saved[i] = 0;
			}
		} while (round < 28);
		if (p1_points >= 63) // adds bonus points if points is over 63
			p1_points += 35;
		if (p2_points >= 63)
			p2_points += 35;
		if (p1_points > p2_points)
			printf("Player 1 wins!\n");
		if (p2_points > p1_points)
			printf("Player 2 wins!\n");
		puts("\n Points:\n");
		printf("Player 1: %d\n", p1_points);
		printf("Player 2: %d\n", p2_points);
		printf("\n Thanks for playing!");
	}
	return 0;
}