#include "Header.h"


/***********************************************************
* Function purpose: readiong in a double from a file       *
* Inputs: The file name                                    *
* Output: The read double                                  *
***********************************************************/
double read_double(FILE *infile) {
	double num = 0.0;
	fscanf(infile, "%lf", &num);

	return num;
}

/***********************************************************
* Function purpose: readiong in a integer from a file      *
* Inputs: The file name                                    *
* Output: The read integer                                 *
***********************************************************/
int read_integer(FILE *infile) {
	int num = 0;
	fscanf(infile, "%d", &num);

	return num;
}

void * calculate_sum_arr(double arr[5][4], double *gpa, double *class_stand, double *age) {
	*gpa = arr[0][1] + arr[1][1] + arr[2][1] + arr[3][1] + arr[4][1];
	*class_stand = arr[0][2] + arr[1][2] + arr[2][2] + arr[3][2] + arr[4][2];
	*age = arr[0][3] + arr[1][3] + arr[2][3] + arr[3][3] + arr[4][3];
}
/***********************************************************
* Function purpose: calculating the mean of a set of nums  *
* Inputs: a sum and number of inputs                       *
* Output: The mean of the numbers                          *
***********************************************************/
double calculate_mean(double sum, int number) { 

	double mean = sum / number;
	return mean;
}

/*****************************************************************************
* Function purpose: calculating the deviation between a number and the mean  *
* Inputs: a number and the mean                                              *
* Output: The deviation between the two numbers                              *
*****************************************************************************/
double calculate_deviation(double number, double mean) {
	return number - mean;
}

/***********************************************************
* Function purpose: check if a file is valid               *
* Inputs: The name of the file                             *
* Output: a success variable, 1 for true and 0 for false   *
***********************************************************/
int validate_file(FILE * infile) {
	if (infile != NULL) {
		return 1;// file was opened successfully!
	}
	return 0;
}

/***********************************************************
* Function purpose: to open the scores.txt file            *
* Inputs: n/a                                              *
* Output: n/a                                              *
***********************************************************/
FILE * open_file(void) {
	FILE *input = NULL;
	input = fopen("scores.txt", "r");
}

/**************************************************************
* Function purpose: calculates the variance between 5 numbers *
* Inputs: 5 double numbers, and the number                    *
* Output: The variance                                        *
**************************************************************/
double calculate_variance_arr(double deviations[], int count) {
	double variance = 0.0;

	for (int i = 0; i < count; i++) {
		variance += pow(deviations[i], 2);
	}

	return variance / count;
}

/***********************************************************
* Function purpose: calculates the standard deviaiton      *
* Inputs: The variance                                     *
* Output: The standard deviation                           *
***********************************************************/
double calculate_standard_deviation(double variance) {
	return sqrt(variance);
}


void* find_min_max(double arr[][4], int count, double* min, double* max) {
	if (count > 0) {
		*max, *min = arr[0][1];
		for (int i = 0; i < count; i++) {
			if (arr[i][1] > *max)
				*max = arr[i][1];
			if (arr[i][1] < *min)
				*min = arr[i][1];
		}
	}
	
}

