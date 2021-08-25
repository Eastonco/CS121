#include <stdlib.h>
#include <stdio.h>
#include <math.h>


FILE * open_file(void);
int validate_file(FILE * infile);
double read_double(FILE *infile);
int read_integer(FILE *infile);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_standard_deviation(double variance);
void* find_min_max(double arr[][4], int count, double* min, double* max);
double calculate_variance_arr(double deviations[], int count);
void* calculate_sum_arr(double arr[5][4], double* gpa, double* class_stand, double* age);



