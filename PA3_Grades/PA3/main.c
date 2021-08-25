/*****************************************************************************
Connor Easton
Class: CptS 121, Spring 2018, Lab Section 12
PA: #3
Date Created: Febuary 5, 2018
Date Last modified: August 24, 2021
Description: This project calculates the GPA with student IDs, and reading
	through files
******************************************************************************/


#include "Header.h"

int main(void) {

	double score = 0.0;
	char grade = '\0'; 
	FILE *infile = NULL, *outfile = NULL;

	infile = open_file();
	outfile = fopen("Grades.txt", "w");

	if (validate_file(infile)) { 

		double students[5][4];

		for (int student = 0; student < 5; student++) {
			for (int grade = 0; grade < 4; grade++) {
				if (grade % 2 == 0)
					students[student][grade] = read_integer(infile);
				else
					students[student][grade] = read_double(infile);
			}
		}

		double gpa, class_stand, age;
		calculate_sum_arr(students, &gpa, &class_stand, &age);

		double gpa_mean = calculate_mean(gpa, 5);
		fprintf(outfile, "GPA Mean: %.2lf\n", gpa_mean);

		double class_stand_mean = calculate_mean(class_stand, 5);
		fprintf(outfile, "Class Standing Mean: %.2lf\n", class_stand_mean);

		double age_mean = calculate_mean(age, 5);
		fprintf(outfile, "Age Mean: %.2lf\n", age_mean);

		double gpaDeviation[5]; 

		for (int i = 0; i < 5; i++) {
			gpaDeviation[i] = calculate_deviation(students[i][1], gpa_mean);
		}

		double variance = calculate_variance_arr(gpaDeviation, 5);
		double std_deviation = calculate_standard_deviation(variance);
		fprintf(outfile, "Standard Deviation: %.2lf\n", std_deviation);

		double gpa_max, gpa_min; 
		find_min_max(students, 5, &gpa_min, &gpa_max);
		fprintf(outfile, "GPA Min: %.2lf\nGPA Max: %.2lf", gpa_min, gpa_max);

		fclose(infile); 
	}
	else 
		printf("Failed to open file");

	fclose(outfile); 

	return 0; 
}