#include "Header.h"

void print_game_rules(void) { // Prints the game rules 
	puts("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.");
	puts("After the dice have come to rest, the sum of the spots on the two upward faces is calculated.");
	puts("If the sum is 7 or 11 on the first throw, the player wins.");
	puts("If the sum is 2, 3, or 12 on the first throw (called \"craps\"), the player loses (i.e. the \"house\" wins).");
	puts("If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's \"point\".");
	puts("To win, you must continue rolling the dice until you \"make your point.\" The player loses by rolling a 7 before making the point.");
	system("pause");
	system("cls");
}

//prompts user for initial bank balance and returns balance
double get_bank_balance(void) { 
	double balance = 0.0;
	printf("Please enter the initial bank balance for wagering: ");
	scanf("%lf", &balance);
	if (balance < 0) {
		puts("invalid bank amount. Please pick a value under the bank amount");
		balance = get_bank_balance();
	}

	return balance;
}

//prompts user for wager amount and returns wager
double get_wager_amount(void) { 
	double wager = 0.0;
	printf("Please enter the amount you would like to wager for this round: ");
	scanf("%lf", &wager);
	if (wager < 0) {
		puts("invalid wager amount. Please pick a value under the bank amount");
		wager = get_wager_amount();
	}

	return wager;
}

//checks if the player has sufficinet funds for wager, returns True for valid, returns False for invalid
bool is_wager_valid(double wager, double balance) { 
	bool is_valid = false;
	if (wager <= balance) {
		is_valid = true;
		return is_valid;
	}
	else {
		return is_valid;
	}

}

//randomly generates a value between 1 and 6 and returns the value
int roll_die(void) { 
	int num = 0;
	num = rand() % 6 + 1;

	return num;
}

//Calculates the sum of two die rolls
int calc_sum_die(int die1_val, int die2_val) { 
	int sum_die = 0;
	sum_die = die1_val + die2_val;

	return sum_die;
}

//tests for rules of craps; returns 1 for craps; returns 0 for "house win"; returns -1 for regular play
int is_win_loss_or_point(int sum_dice) { 
	if (sum_dice == 7 || sum_dice == 11) 
		return 1;
	if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
		return 0;
	else
		return -1;
}

//tests if sum_dice = point_value, returns 1; if sum_dice = 7, returns 0, else -1
int is_point_loss_or_neither(int sum_dice, int point_value) { 
	int point_loss_neither = 0;
	if (sum_dice == point_value) {
		point_loss_neither = 1; //win
	}
	if (sum_dice == 7) {
		point_loss_neither = 0;//loss
	}
	else {
		point_loss_neither = -1;//neither
	}
	return point_loss_neither;
}

// if add_or_subtranct = 1, adds wager to bank balance; if = 0, subtracts from balance; else, returns bank balance
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {
	if (add_or_subtract == 1) {
		bank_balance += wager_amount;
	}
	if (add_or_subtract == 0) {
		bank_balance -= wager_amount;
	}
	return bank_balance;
}

// honeslty idk, says stuff i guess
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance,
	double current_bank_balance) {
	
}

void welcome_message(void) {
	//welcome message
	puts("Hello! and welcome to the game of");
	puts("                ___ _ __ __ _ _ __  ___ ");
	puts("               / __| '__/ _` | '_ \\/ __|");
	puts("              | (__| | | (_| | |_) \\__ \\");
	puts("               \\___|_|  \\__,_| .__/|___/");
	puts("                             | |        ");
	puts("                             |_|        ");
	puts("                                       _______.");
	puts("                            ______    | .   . |\\");
	puts("                           /     /\\   |   .   |.\\");
	puts("                          /  '  /  \\  | .   . |.'|");
	puts("                         /_____/. . \\ |_______|.'|");
	puts("                         \\ . . \\    /  \\ ' .   \\'|");
	puts("                          \\ . . \\  /    \\____'__\\|");
	puts("                           \\_____\\/");
	printf("\n\n");
}

int menu_options(void) { //printing menu and options
	int choice = 0, usr_attempt = 0;
	do {
		usr_attempt++;
		if (usr_attempt > 1) {
			system("cls");
			printf("Invalid user input, please submit a valid choice\n\n"); //prompts user input is invalid if 2 try 
		}
		printf("Welcome to the menu! \n\n");
		puts("(1) Rules");			//options
		puts("(2) Play the game");
		printf("\nChoice: ");
		scanf("%d", &choice);
		if (choice == 1) {
			usr_attempt--;
			system("cls");
			print_game_rules();
		}

	} while (choice != 2); //tests user input to play game
	
	return choice; // 1 = rules, 2 = play game
}

void print_die(int die1, int die2, int roll_count) { //rolling die anamation 
	system("cls");
	printf("Roll #%d\n", roll_count);
	printf("And here's the roll");
	for (int n = 0; n <= 3; n++) {
		Sleep(250); //waits between periods
		printf(". ");
	}
	//add a time wait for delay
	printf("\nDie 1: %d\n", die1);
	printf("Die 2: %d\n", die2);
	printf("Total: %d\n", calc_sum_die(die1, die2));

}

