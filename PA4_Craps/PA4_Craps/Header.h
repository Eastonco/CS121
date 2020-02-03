//including libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //bool statements
#include<conio.h> //colored text
#include <Windows.h> //timed pauses


//function declarations
void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
bool is_wager_valid(double wager, double balance);
int roll_die(void);
int calc_sum_die(int die1_val, int die2_val);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);
void welcome_message(void);
int menu_options(void);
void print_die(int die1, int die2, int roll_count);

