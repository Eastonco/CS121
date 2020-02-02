#include "Header.h"

//NOTE:
//		when refrencing the board refrence board[row][collum]


int main(void) {
	srand(time(NULL)); //makes random things random

	char p1_board[MAX_ROWS][MAX_COLS] = { '\0' }, // creates p1 and computer board variables
		 p2_board[MAX_ROWS][MAX_COLS] = { '\0' };
	bool is_playing = false;
	Ship ship[5] = {{ "Carrier", 'c', 5 }, //sets the ship class to the ship name, symbol, and length
					{"Battleship", 'b', 4}, 
					{"Cruiser", 'r', 3},
					{"Submarine", 's', 3},
					{"Destroyer", 'd', 2}};
	Stats p1_stats = { 0,0,0,0.0 };
	Stats p2_stats = { 0,0,0,0.0 };

	int c_shots[MAX_ROWS][MAX_COLS] = { 0 };
	int p1_sunkships[5] = { 5,4,3,3,2 }, p2_sunkships[5] = { 5,4,3,3,2 };
	
	init_board(p1_board, MAX_COLS, MAX_COLS); //initializes player 1 board
	init_board(p2_board, MAX_COLS, MAX_COLS); //initializes computer board
	print_board(p1_board, MAX_COLS, MAX_COLS, false);
	
	int choice = welcome_screen(); // welcome menu including the rules

	if (choice == 3) { //user chose to exit game
		printf("> Thanks for playing!\n> \n> ");
		return 0;
	}
	if (choice = 2) // user chose to play game
		is_playing = true;
	
	while (is_playing = true) {
		FILE *outfile = NULL;
		outfile = fopen("Battleship.log", "w");
		int p_choice = placement_choice();
		if (p_choice == 1) //auto placement
			Auto_Ship_Placement(p1_board, MAX_ROWS, MAX_COLS, ship);
		if (p_choice == 2) //manual placment
			Manual_Ship_Placement(p1_board, MAX_ROWS, MAX_COLS, ship);
		Auto_Ship_Placement(p2_board, MAX_ROWS, MAX_COLS, ship); //autoship placement for the computer board
		int start_player = start_first();
		fprintf(outfile, "The game has begun\n");
		if (start_player == 1) {    //computer starts
			system("cls");
			printf("> The computer goes first\n");
			fprintf(outfile, "The computer starts");
			Computer_shot(p1_board, MAX_ROWS, MAX_ROWS, outfile, p2_stats, c_shots, p1_sunkships);
		}
		else if (start_player == 0){// p1 starts
			system("cls");
			printf("> Player 1 goes first\n");
			fprintf(outfile, "Player 1 goes first\n");
		}
		do { //loops play
			Player_shot(p2_board, MAX_ROWS, MAX_COLS, outfile, p1_stats, p2_sunkships); // player shoots
			Computer_shot(p1_board, MAX_ROWS, MAX_ROWS, outfile, p2_stats, c_shots, p1_sunkships); //computer shoots
		} while (!is_all_ships_sunk(p1_sunkships) || !is_all_ships_sunk(p2_sunkships)); 

		system("cls");

		if (is_all_ships_sunk(p1_sunkships)) { // if computer wins
			printf("The computer wins!");
			fprintf(outfile, "\nThe computer wins!");
		}
		if (is_all_ships_sunk(p2_sunkships)) { //if player wins
			printf("Player 1 wins!");
			fprintf(outfile, "\nPlayer 1 wins!");
		}
		system("pause");
		output_stats(p1_stats, p2_stats, outfile); // prints stats to outfile and screen
		
		
		fclose(outfile); //closes the file 
		is_playing = false; //exits the game
	}
	
	return 0;
}