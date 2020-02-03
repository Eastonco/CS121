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

/***********************************************************
* Function purpose: calculating the sum of 5 numbers       *
* Inputs: The 5 numbers as doubles                         *
* Output: The sum of the numbers                           *
***********************************************************/
double calculate_sum(double number1, double number2,
	double number3, double number4, double number5) {

	double sum = number1 + number2 + number3 + number4 + number5;
	return sum;
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
	double deviation = 0.0;

	deviation = number - mean;

	return deviation;

}

/***********************************************************
* Function purpose: check if a file is valid               *
* Inputs: The name of the file                             *
* Output: a success variable, 1 for true and 0 for false   *
***********************************************************/
int validate_file(FILE * infile) {

	int success = 0;

	if (infile != NULL) {
		// file was opened successfully!
		success = 1;
		//return 1
	}

	return success;
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
double calculate_variance(double deviation1, double deviation2,
	double deviation3, double deviation4, double deviation5, int number) {
	double variance = 0.0;

	variance = (pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2)
		+ pow(deviation5, 2)) / number;

	return variance;

}

/***********************************************************
* Function purpose: calculates the standard deviaiton      *
* Inputs: The variance                                     *
* Output: The standard deviation                           *
***********************************************************/
double calculate_standard_deviation(double variance) {
	double std_dv = 0.0;

	std_dv = sqrt(variance);

	return std_dv;
}

/***********************************************************
* Function purpose: Finds the max number                   *
* Inputs: 5 double numbers                                 *
* Output: the highest number as a double                   *
***********************************************************/
double find_max(double number1, double number2,
	double number3, double number4, double number5) {
	double max = 0.0;

	if (number1 > max) {
		max = number1;
	}
	if (number2 > max) {
		max = number2;
	}
	if (number3 > max) {
		max = number3;
	}
	if (number4 > max) {
		max = number4;
	}
	if (number5 > max) {
		max = number5;
	}

	return max;
}

/***********************************************************
* Function purpose: Finds the minimum number               *
* Inputs: 5 double numbers                                 *
* Output: the lowest number as a double                    *
***********************************************************/
double find_min(double number1, double number2,
	double number3, double number4, double number5) {
	double min = number1;

	if (number2 < min) {
		min = number2;
	}
	if (number3 < min) {
		min = number3;
	}
	if (number4 < min) {
		min = number4;
	}
	if (number5 < min) {
		min = number5;
	}

	return min;
}

/***********************************************************
* Function purpose: printing out to a file                 *
* Inputs: the name of the outfile and the double number    *
* Output: n/a (prints out to the file)                     *
***********************************************************/
void print_double(FILE *outfile, double number) {

	fprintf(outfile, "%.2lf\n", number);

}

