/*****************************************************************************
Connor Easton
Class: CptS 121, Spring 2018, Lab Section 12
PA: #4
Date Created: Febuary 15, 2018
Date Last modified: Febuary 23, 2018
Description: This project plays the game of Craps.
******************************************************************************/

#include "Header.h"

int main(void) {
	srand(time(NULL)); // sets the seed for the random to something new every execution
	int choice = 0;
	bool Is_running = false;
	welcome_message();//prints welcome message
	system("pause");
	system("cls");
	choice = menu_options(); //gets choice from user

	if (choice == 2) { //starts the game
		Is_running = true;
		system("cls");
	}

	while (Is_running == true) {
		char play_again = '\0'; //sets variables
		double bank = 0.0, wager = 0.0, tmp = 0.0;
		int die1 = 0, die2 = 0, win_loss_point = 0, sum_roll = 0, menu_count = 1, roll_count = 0, starting = 1, point_val = 0,
			in_game = 0;

		//menu start
		do {
			do {
				if (menu_count > 1 && in_game == 0) { //testz for invalid input
					system("cls");
					puts("invalid wager amount. Please pick a value under the bank amount");
					wager = get_wager_amount();
				}
				if (menu_count <= 1) { //gets bank and wager values
					bank = get_bank_balance();
					wager = get_wager_amount();
					menu_count++;
				}
				//menu end


			} while (is_wager_valid(wager, bank) != true);
			in_game = 1;
			do {
				die1 = roll_die(); // rolling die 
				die2 = roll_die();
				roll_count++;

				print_die(die1, die2, roll_count);
				//printing die values

				sum_roll = calc_sum_die(die1, die2); //summing roll

				if (starting) {
					win_loss_point = is_win_loss_or_point(sum_roll);
					if (win_loss_point == 1) {//if craps
						char win_loss = '\0';
						puts("Craps! You win!");
						bank = adjust_bank_balance(bank, wager, 1);
						printf("your balance is %lf", bank);
						printf("Play again? (y/n): ");// play again
						scanf(" %c", &win_loss);
						starting = 1;
						if (win_loss == 'n') {
							system("cls");
							printf("Thanks for Playing!\n\n");
							return 0;
						}
						else {
							roll_count = 0; //sets roll count
						}
					}
					if (win_loss_point == 0) { //if house wins
						char win_loss = '\0';
						puts("Aw, House wins. You loose!");
						bank = adjust_bank_balance(bank, wager, 0);
						printf("your balance is %lf", bank);
						printf("Play again? (y/n): "); // play again
						scanf(" %c", &win_loss);
						starting = 1; //resets game start
						if (win_loss == 'n') {
							system("cls");
							printf("Thanks for Playing!\n\n");
							return 0;
						}
						else {
							roll_count = 0;
						}
					}
					else {
						point_val = sum_roll;// sets the point value to sum roll if no craps or house win on first roll
						starting = 0;
						printf("How much would you like to increase your bet by?: "); //wager changing
						scanf("%lf", &tmp);
						wager += tmp;
						printf("Your wager is now $%.2lf\n\n", wager);
						system("pause");
					}
				}
				else {
					win_loss_point = is_point_loss_or_neither(sum_roll, point_val);//win loss or point
					if (sum_roll == point_val) {
						printf("you win!\n");
						bank = adjust_bank_balance(bank, wager, 1);
						printf("your balance is %lf", bank);// adjusts bank balance
						printf("play again? (y/n): ");
						scanf(" %c", &play_again);
						if (play_again == 'n') {
							printf("thanks for playing!\n");
							return 0;
						}
						else {
							roll_count = 0;//resets game
							wager = 0;
						}
					}
					if (win_loss_point == -1) {
						printf("How much would you like to increase your bet by?: ");
						scanf("%lf", &tmp);
						wager += tmp;
						if (is_wager_valid(wager, bank) != true) {// tests for invalid wager
							do {
								wager -= tmp;
								printf("invalid wager amount, plase select a lower number to add: ");
								scanf("%lf", &tmp);
								wager += tmp;
							} while (is_wager_valid(wager, bank) != true);

						}
						printf("Your wager is now $%.2lf\n\n", wager); //wager adjustments
						system("pause");
					}
				}

				} while (is_point_loss_or_neither == -1);
				if (is_point_loss_or_neither == -1) {
					bank = adjust_bank_balance(bank, wager, 0);
					printf("you loose!\n");
					printf("your balance is %lf", bank); // bank adjustments
					printf("play again? (y/n): ");
					scanf(" %c", &play_again);
					starting = 1;
					if (play_again == 'n') {
						printf("thanks for playing!\n");
						return 0;
					}
					else {
						roll_count = 0;
				}
			}

		} while (bank > 0); //if runs out of money
}
	return 0;
}