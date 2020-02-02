#include "Header.h"

void init_board(char board[][MAX_COLS], int num_rows, int num_cols) { //initializes a game board with all water tokens
	
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < num_rows; ++row_index ){
		for (col_index = 0; col_index < num_cols; ++col_index) {
			board[row_index][col_index] = '~';
		}
	}
}

void print_board(char board[][MAX_COLS], int num_rows, int num_cols, bool is_hidden) { //prints the board with markers for positions

	int row_index = 0, col_index = 0;

	printf("  ");
	for (col_index = 0; col_index < num_cols; ++col_index) { // prints the 0-9 header
		printf("%d ", col_index);
	}

	puts(""); //idk adds some space i guess

	for (row_index = 0; row_index < num_rows; ++row_index) { //prints the board
		printf("%d ", row_index);
		for (col_index = 0; col_index < num_cols; ++col_index) {
			if (!is_hidden)
				printf("%c ", board[row_index][col_index]);
			else if(is_hidden)
				switch (board[row_index][col_index]){
				case HIT: printf("%c ", HIT); break;
				case MISS: printf("%c ", MISS); break;
				default: printf("%c ", WATER); break;
				}
		}
		printf("\n");
	}
}

int welcome_screen(void){
	int choice = '\0', attempt = 0;
	do {
		++attempt;
		system("cls");
		if (attempt > 1)
			puts("> Invalid user input, please try again");
		puts("> ***** Welcome to Battleship! *****\n>");
		puts("> [1] Rules");
		puts("> [2] Play");
		puts("> [3] Exit");
		printf("> Choice: ");
		scanf("%d", &choice);
		system("cls");
		if (choice == 1) {
			attempt--;
			Print_Game_Rules();
			system("pause");
		}

	} while (choice != 2 && choice != 3);
	system("cls");
	return choice;
}

void Print_Game_Rules(void){
	printf("> \tTHE RULES OF THE GAME\n");
	puts("> 1. This is a one player game.");
	puts("> 2. Player 1 is the user and Player 2 is the computer.");
	puts("> 3. Player 1 will choose if they want to manually place");
	puts(">    their ships or have the computer randomly generate the game board");
	puts("> 4. There are five types of ships to be placed: the Carrier [c] has 5");
	puts(">    cells, the Battleship [b] has 4 cells, the Cruiser [r] has 4 cells,");
	puts(">    the Submarine [s] has 3 cells, the Destroyer [d] has 2 cells");
	puts("> 5. The computer randomly selects which player will go first");
	puts("> 6. The goal of the game is to try to guess the location of the opposing");
	puts(">    team's ship and sink all of their ships.");
	puts("> 7. The game is over when all of one players ships have been sunken.");
	printf(">\n> ");
}

void Manual_Ship_Placement(char board[][MAX_COLS], int num_rows, int num_cols, Ship ship[]) {
	int valid = 0, attempt = 0;
	Coordinate start_pt = { -1,-1 };
	char aim = '\0';
	Dir direction = HORIZONTAL;

	
	system("cls");
	puts("> Welcome to manual ship placement.");
	puts("> To get started, first pick your starting coordnates and then direciton (right or down) to place ships");
	for (int i = 0; i < 5; i++) {
		attempt = 0;
		int attempt1 = 0;
		do {
			if (attempt > 0) {
				system("cls");
				printf("> invalid placement, please try again\n");
			}
			++attempt;
			print_board(board, num_cols, num_cols, false);
			printf("> For the %s, (length %d), where would you like the start point to be?\n", ship[i].name, ship[i].length);
			printf("\n> Row: ");
			scanf("%d", &start_pt.row);
			printf("> Column: ");
			scanf("%d", &start_pt.col);
			
			do {
				if (attempt1 > 0) {
					printf("> invalid direction, please try again\n"); 
				}
				attempt1++;
				printf("\n> Direction (right 'r', down 'd'): ");
				scanf(" %c", &aim);
			} while (aim != 'r' && aim != 'd');
			if (aim == 'r')
				direction = HORIZONTAL;
			if (aim == 'd')
				direction = VERTICAL;
			valid = is_valid(board, num_rows, num_cols, start_pt, direction, ship[i].length);
		} while (!valid);
		for (int j = 0; j < ship[i].length; j++) {
			if (direction == HORIZONTAL)
				board[start_pt.row][start_pt.col + j] = ship[i].symbol;
			if (direction == VERTICAL)
				board[start_pt.row + j][start_pt.col] = ship[i].symbol;
			system("cls");
		}
	}
}

void Auto_Ship_Placement(char board[][MAX_COLS], int num_rows, int num_cols, Ship ship[]){
	Coordinate start_pt = { -1,-1 };
	Dir direction = HORIZONTAL;
	int num_ships = 0, valid = 0;

	while (num_ships < 5) {
		do {
			direction = gen_dir();
			gen_start_pt(&start_pt, direction, ship[num_ships].length);
			valid = is_valid(board, num_rows, num_cols, start_pt, direction, ship[num_ships].length);
		} while (!valid);
		for (int i = 0; i < ship[num_ships].length; i++){
			if (direction == HORIZONTAL)
				board[start_pt.row][start_pt.col + i] = ship[num_ships].symbol;
			if (direction == VERTICAL)
				board[start_pt.row + i][start_pt.col] = ship[num_ships].symbol;
			}
		++num_ships;
	}
}

int is_valid(char board[][MAX_COLS], int num_rows, int num_cols, Coordinate start_pt, Dir direction, int length)
{
	for (int i = 0; i < length; i++) {
		if (direction == HORIZONTAL)
			if (board[start_pt.row][start_pt.col + i] != WATER)
				return 0;
		if (direction == VERTICAL)
			if (board[start_pt.row + i][start_pt.col] != WATER)
				return 0;
	}
	return 1;
}

int start_first(void)
{
	int first = 0;
	first = rand() % 2;
	return first;
}

bool is_all_ships_sunk(int sunkships[]) //add tings to me --- swich to the sunk ships array
{
	int i;
	for (i = 0; i < 5; i++) {
		if (sunkships[i] != -1)
			return false;
	}
	return true;
}

int shot_valid(int row_target, int col_target)
{
	if (row_target <= 9 && row_target >= 0) {
		if (col_target <= 9 && col_target >= 0)
			return 1;
	}
	return 0;
}

void output_stats(Stats p1_stats, Stats p2_stats, FILE * outfile)
{
	p1_stats.total_hits = p1_stats.total_hits + p1_stats.total_misses;
	p1_stats.hit_miss_ratio = p1_stats.total_hits / p1_stats.total_misses;

	p2_stats.total_hits = p2_stats.total_hits + p2_stats.total_misses;
	p2_stats.hit_miss_ratio = p1_stats.total_hits / p2_stats.total_misses;

	system("cls");
	printf("***************************************************\n");
	printf("*         Stats                                   *\n");
	printf("*                      Player 1         Player 2  *\n");
	printf("* Total Shots:           %d                %d     *\n", p1_stats.total_shots, p2_stats.total_shots);
	printf("* Total Hits:            %d                %d     *\n", p1_stats.total_hits, p2_stats.total_hits);
	printf("* Total Misses:          %d                %d     *\n", p1_stats.total_misses, p2_stats.total_misses);
	printf("* Hit/Miss Ratio:        %lf               %lf    *\n", p1_stats.hit_miss_ratio, p2_stats.hit_miss_ratio);
	printf("***************************************************\n\n");

	fprintf(outfile, "\n\n");
	fprintf(outfile, "***************************************************\n");
	fprintf(outfile, "*         Stats                                   *\n");
	fprintf(outfile, "*                      Player 1         Player 2  *\n");
	fprintf(outfile, "* Total Shots:           %d                %d     *\n", p1_stats.total_shots, p2_stats.total_shots);
	fprintf(outfile, "* Total Hits:            %d                %d     *\n", p1_stats.total_hits, p2_stats.total_hits);
	fprintf(outfile, "* Total Misses:          %d                %d     *\n", p1_stats.total_misses, p2_stats.total_misses);
	fprintf(outfile, "* Hit/Miss Ratio:        %lf               %lf    *\n", p1_stats.hit_miss_ratio, p2_stats.hit_miss_ratio);
	fprintf(outfile, "***************************************************\n\n");
}

void Computer_shot(char board[][MAX_COLS], int num_rows, int num_cols, FILE *outfile, Stats stat, int shots[][MAX_COLS], int sunk_ships[])
{
	int row_shot = 0;
	int col_shot = 0;

	do {
		do {
			row_shot = rand() % num_rows;
			col_shot = rand() % num_cols;
		} while (shots[row_shot][col_shot] != 0);
		shots[row_shot][col_shot]++;
	} while (board[row_shot][col_shot] == HIT || board[row_shot][col_shot] == MISS);


	if (board[row_shot][col_shot] != WATER){
		fprintf(outfile, "\nComputer: %d, %d is a hit!", row_shot, col_shot);
		printf("> %d, %d is a hit!\n", row_shot, col_shot);
		stat.total_hits++;
		switch (board[row_shot][col_shot]){
		case CARRIER: sunk_ships[0]--; break;
		case BATTLESHIP: sunk_ships[1]--; break;
		case CRUISER: sunk_ships[2]--; break;
		case SUBMARINE: sunk_ships[3]--; break;
		case DESTROYER: sunk_ships[4]--; break;
		}
		if (sunk_ships[0] == 0) {
			printf("The computer sunk your Carrier!\n\n");
			fprintf(outfile, " Sunk the Carrier.");
			sunk_ships[0]--;
		}
		if (sunk_ships[1] == 0) {
			printf("The computer sunk your Battleship!\n\n");
			fprintf(outfile, " Sunk the Battleship.");
			sunk_ships[1]--;
		}
		if (sunk_ships[2] == 0) {
			printf("The computer sunk your Cruiser!\n\n");
			fprintf(outfile, " Sunk the Cruiser.");
			sunk_ships[2]--;
		}
		if (sunk_ships[3] == 0) {
			printf("The computer sunk your Submarine!\n\n");
			fprintf(outfile, " Sunk the Submarine.");
			sunk_ships[3]--;
		}
		if (sunk_ships[4] == 0) {
			printf("The computer sunk your Destroyer!\n\n");
			fprintf(outfile, " Sunk the Destroyer.");
			sunk_ships[4]--;
		}
		board[row_shot][col_shot] = HIT;
		print_board(board, num_rows, num_cols, false);
		system("pause");
		system("cls");
	}
	else if (board[row_shot][col_shot] == WATER) {
		fprintf(outfile, "\nComputer: %d, %d is a miss.", row_shot, col_shot);
		stat.total_misses++;
		board[row_shot][col_shot] = MISS;
		print_board(board, num_rows, num_cols, false);
		printf("> %d, %d is a miss.\n", row_shot, col_shot);
		system("pause");
		system("cls");
	}
}

void Player_shot(char board[][MAX_COLS], int num_rows, int num_cols, FILE *outfile, Stats stat, int sunk_ships[])
{
	int row_shot = 0, col_shot = 0, attempt = 0;
	print_board(board, num_rows, num_cols, true);
	do {
		do {
			if (attempt > 0) {
				printf("\ninvalid shot choice. Please try again.\n");
				attempt--;
			}
			attempt++;
			printf("\nWhere would you like to shoot?");
			printf("\nRow: ");
			scanf("%d", &row_shot);
			printf("Column: ");
			scanf("%d", &col_shot);
		} while (!shot_valid(row_shot, col_shot));
	} while (board[row_shot][col_shot] == MISS && board[row_shot][col_shot] == HIT);
	
	if (board[row_shot][col_shot] != WATER) {
		printf("\n%d, %d is a hit!\n", row_shot, col_shot);
		fprintf(outfile, "\nPlayer 1: %d, %d is a hit!", row_shot, col_shot);
		switch (board[row_shot][col_shot]) {
		case CARRIER: sunk_ships[0]--; break;
		case BATTLESHIP: sunk_ships[1]--; break;
		case CRUISER: sunk_ships[2]--; break;
		case SUBMARINE: sunk_ships[3]--; break;
		case DESTROYER: sunk_ships[4]--; break;
		}
		if (sunk_ships[0] == 0) {
			printf("You sunk the Carrier!\n\n");
			fprintf(outfile, " Sunk the Carrier.");
			sunk_ships[0]--;
		}
		if (sunk_ships[1] == 0) {
			printf("You sunk the Battleship!\n\n");
			fprintf(outfile, " Sunk the Battleship.");
			sunk_ships[1]--;
		}
		if (sunk_ships[2] == 0) {
			printf("You sunk the Cruiser!\n\n");
			fprintf(outfile, " Sunk the Cruiser.");
			sunk_ships[2]--;
		}
		if (sunk_ships[3] == 0) {
			printf("You sunk the Submarine!\n\n");
			fprintf(outfile, " Sunk the Submarine.");
			sunk_ships[3]--;
		}
		if (sunk_ships[4] == 0) {
			printf("You sunk the Destroyer!\n\n");
			fprintf(outfile, " Sunk the Destroyer.");
			sunk_ships[4]--;
		}
		fprintf(outfile, "\nPlayer 1: %d, %d is a hit!", row_shot, col_shot);
		stat.total_hits++;
		board[row_shot][col_shot] = HIT;
		system("pause");
		system("cls");
	}
	else if (board[row_shot][col_shot] == WATER) {
		printf("\n%d, %d is a miss.\n", row_shot, col_shot);
		fprintf(outfile, "\nPlayer 1: %d, %d is a miss.", row_shot, col_shot);
		stat.total_misses++;
		board[row_shot][col_shot] = MISS;
		system("pause");
		system("cls");
	}
	
	
}


Dir gen_dir(void){
	Dir direction = HORIZONTAL;

	direction = (Dir) rand() % 2;

	return direction;
}

void gen_start_pt(Coordinate *start_pt_ptr, Dir direction, int length)
{
	if (direction == HORIZONTAL) {
		start_pt_ptr->row = rand() % MAX_ROWS;
		start_pt_ptr->col = rand() % (MAX_COLS - length + 1);
	}
	else if (direction == VERTICAL){
		start_pt_ptr->row = rand() % (MAX_ROWS - length + 1);
		start_pt_ptr->col = rand() % MAX_COLS;
	}
}

int placement_choice(void){
	int p_choice = 0, attempt = 1;
	do {
		system("cls");
		if (attempt > 1)
			printf("> Invalid input, please try again\n>\n");
		++attempt;
		puts("> How would you like to place your ships?");
		puts("> [1] Auto Placement");
		puts("> [2] Manual Placement");
		printf("> Choice: ");
		scanf("%d", &p_choice);
	} while (p_choice != 1 && p_choice != 2);
	
	return p_choice;
}

