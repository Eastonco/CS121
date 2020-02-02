/****************************************************************************
Connor Easton
Class: CptS 121, Spring 2018, Lab Section 12
PA: #6
Date Created: March 23, 2018
Date Last Modified: April 3, 2018
Description: This project plays the game of Battleship
***********************************************************************/

// areas marked with comment " ### " take from refrence https://github.com/gabrieledcjr/Battleship

#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <time.h>


typedef enum dir {
	HORIZONTAL = 0, VERTICAL = 1
} Dir;

typedef struct stats {
	int total_shots;
	int total_misses;
	int total_hits;
	double hit_miss_ratio;
}Stats;

typedef struct coordinate {
	int row;
	int col;

}Coordinate;

typedef struct ship { //###
	char *name;
	char symbol;
	int length;

} Ship;

#define HIT '*'
#define MISS 'm'
#define WATER '~'
#define CARRIER 'c'
#define BATTLESHIP 'b'
#define CRUISER 'r'
#define SUBMARINE 's'
#define DESTROYER 'd'
#define MAX_ROWS 10
#define MAX_COLS 10

void init_board(char board[][MAX_COLS], int num_rows, int num_cols);
void print_board(char board[][MAX_COLS], int num_rows, int num_cols, bool is_hidden);
int welcome_screen(void);
void Print_Game_Rules(void);
Dir gen_dir(void);
void gen_start_pt(Coordinate *start_pt_ptr, Dir direction, int length);
int placement_choice(void);
void Manual_Ship_Placement(char board[][MAX_COLS], int num_rows, int num_cols, Ship ship[]);
void Auto_Ship_Placement(char board[][MAX_COLS], int num_rows, int num_cols, Ship ship[]);
int is_valid(char board[][MAX_COLS], int num_rows, int num_cols, Coordinate start_pt, Dir direction, int length);
int start_first(void);
void Computer_shot(char board[][MAX_COLS], int num_rows, int num_cols, FILE *outfile, Stats stat, int shots[][MAX_COLS], int sunk_ships[]);
void Player_shot(char board[][MAX_COLS], int num_rows, int num_cols, FILE *outfile, Stats stat, int sunk_ships[]);
bool is_all_ships_sunk(int sunkships[]);
int shot_valid(int row_target, int col_target);
void output_stats(Stats p1_stats, Stats p2_stats, FILE *outfile);



#endif // !HEADER_H