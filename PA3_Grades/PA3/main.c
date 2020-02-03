/*****************************************************************************
Connor Easton
Class: CptS 121, Spring 2018, Lab Section 12
PA: #3
Date Created: Febuary 5, 2018
Date Last modified: Febuary 7, 2018
Description: This project calculates the GPA with student IDs, and reading
	through files
******************************************************************************/


#include "Header.h"

int main(void) {

	// variable declaration
	double score = 0.0;
	char grade = '\0'; 
	int success = 0;
	FILE *infile = NULL, *outfile = NULL;

	//opening in and out files
	infile = open_file();
	success = validate_file(infile); //checks if file open is vaild
	outfile = fopen("Grade.txt", "w");
	if (success) { // if it is, the function executes
		// more variable declaration
		double student1[4], student2[4], student3[4], student4[4], student5[4];
		
		//reading in information for studnet 1,2,3,4, and 5 and puts information into an array
		student1[0] = read_integer(infile);
		student1[1] = read_double(infile);
		student1[2] = read_integer(infile);
		student1[3] = read_double(infile);

		student2[0] = read_integer(infile);
		student2[1] = read_double(infile);
		student2[2] = read_integer(infile);
		student2[3] = read_double(infile);

		student3[0] = read_integer(infile);
		student3[1] = read_double(infile);
		student3[2] = read_integer(infile);
		student3[3] = read_double(infile);

		student4[0] = read_integer(infile);
		student4[1] = read_double(infile);
		student4[2] = read_integer(infile);
		student4[3] = read_double(infile);

		student5[0] = read_integer(infile);
		student5[1] = read_double(infile);
		student5[2] = read_integer(infile);
		student5[3] = read_double(infile);

		double gpa_sum = 0.0, class_stand_sum = 0.0, age_sum = 0.0; // even more variable declaration and calcuation of sums

		gpa_sum = calculate_sum(student1[1], student2[1], student3[1], student4[1], student5[1]);
		class_stand_sum = calculate_sum(student1[2], student2[2], student3[2], student4[2], student5[2]);
		age_sum = calculate_sum(student1[3], student2[3], student3[3], student4[3], student5[3]);

		double gpa_mean = 0.0, class_stand_mean = 0.0, age_mean = 0.0; // variabe declaration

		gpa_mean = calculate_mean(gpa_sum, 5);//calculation of gpa, class standing, and age mean
		print_double(outfile, gpa_mean);//priting results to out file

		class_stand_mean = calculate_mean(class_stand_sum, 5);
		print_double(outfile, class_stand_mean);

		age_mean = calculate_mean(age_sum, 5);
		print_double(outfile, age_mean);

		double gpad1 = 0.0, gpad2 = 0.0, gpad3 = 0.0, gpad4 = 0.0, gpad5 = 0.0; //gpa deviation variables

		gpad1 = calculate_deviation(student1[1], gpa_mean);
		gpad2 = calculate_deviation(student2[1], gpa_mean);
		gpad3 = calculate_deviation(student3[1], gpa_mean); // calculations for gpa deviation
		gpad4 = calculate_deviation(student4[1], gpa_mean);
		gpad5 = calculate_deviation(student5[1], gpa_mean);

		double variance = 0.0, std_deviation = 0.0; // variance variable declaration

		variance = calculate_variance(gpad1, gpad2, gpad3, gpad4, gpad5, 5); // calculation of standard variance, and variance and prints std_deviaiton to outfile 
		std_deviation = calculate_standard_deviation(variance);
		print_double(outfile, std_deviation);

		double gpa_max = 0.0, gpa_min = 0.0; // variables for min and max gpa's

		gpa_min = find_min(student1[1], student2[1], student3[1], student4[1], student5[1]); // calculations for min and max gpa's and writes to outfile
		print_double(outfile, gpa_min);
		gpa_max = find_max(student1[1], student2[1], student3[1], student4[1], student5[1]);
		print_double(outfile, gpa_max);

		fclose(infile); // close in file

	}
	else {
		printf("Failed to open file");
		break
	}

fclose(outfile); //closes the outfile

return 0; // end of funciton
}