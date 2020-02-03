#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// #define

//function declaration/prototypes

FILE * open_file(void);
int validate_file(FILE * infile);
double read_double(FILE *infile);
int read_integer(FILE *infile);
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_sum(double number1, double number2, double number3, double number4, double number5);
double find_max(double number1, double number2, double number3, double number4, double number5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_standard_deviation(double variance);
void print_double(FILE *outfile, double number);
double find_min(double number1, double number2, double number3, double number4, double number5);







