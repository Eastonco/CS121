/*****************************************************************************
Connor Easton
Class: CptS 121, Spring 2018, Lab Section 12
PA: #2
Date Created: January 26, 2018
Date Last modified: August 24, 2021
Description: This project calculates Newton's second law, the volume of a cylinder, encoded characters,
the force of gravity, voltage resistance, the distance between two points, and the answer
to an undefined equation BUT WITH FUNCTIONS
******************************************************************************/

#include "PA2.h"

int main(void) {

	// Part 1
	double mass, accl, f = 0.0;
	printf("Please enter the mass and acceleration <both floating-point values> for use in Newton's Second Law: "); 
	scanf("%lf%lf", &mass, &accl);
	f = calc_newtons_2nd_law(mass, accl);
	printf("Newton's Second Law: force = mass * acceleration = %lf * %lf = %lf\n\n", mass, accl, f); 

	// Part 2
	double ht, r, vol = 0.0;
	printf("Please enter the radius and height <both floating-point values> for use in a volume of a cylinder equation: "); 
	scanf("%lf %lf", &r, &ht);
	vol = calc_volume_cylinder(r, ht);
	printf("Volume of a cylinder: volume_cylinder = PI * radius^2 * height = 3.141592 * %lf^2 * %lf = %lf\n\n", r, ht, vol);
	

	// Part 3
	char chr = 'a', pt_chr, ecdd_chr = '\0';
	printf("Enter a plaintext character: ");
	scanf(" %c", &pt_chr);
	ecdd_chr = perform_character_encoding(pt_chr);
	printf("Encoded character: %c\n\n", ecdd_chr);
	
	// Part 4
	double m1, m2, dis, F = 0.0;
	printf("Please enter the mass of the first and second entities and then the distance between the two for use in the Force of Gravity Equation: ");
	scanf("%lf%lf%lf", &m1, &m2, &dis);
	F = (G * m1 * m2) / (dis * dis);
	printf("Force of gravity = G * mass1 * mass2 / distance^2 = %.13lf * %lf * %lf / %lf^2 = %.13lf\n\n", G, m1, m2, dis, F);
	
	// Part 5
	double r1, r2, vin, vout = 0.0;
	printf("Please enter the resistance of the first and second reistors and the voltage in: ");
	scanf("%lf%lf%lf", &r1, &r2, &vin);
	vout = calculate_resistive_divider(r1, r2, vin);
	printf("Equation: Vout = r2 / (r1 + r2) * Vin = %lf / (%lf + %lf) * %lf = %lf\n\n", r2, r1, r2, vin, vout);
	
	// Part 6
	double x1, x2, y1, y2 = 0.0;
	printf("Please enter the x1, x2 and y1, y2 coordinates to find the distance between the two: ");
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);
	dis = calculate_distance_between_2pts(x1, x2, y1, y2);
	printf("Distance between two points = sqrt((x1 - x2)^2 + (y1 - y2)^2) = sqrt((%lf - %lf)^2 + (%lf - %lf)^2) = %lf\n\n", x1, x2, y1, y2, dis);
	
	// Part 7
	int z, x, a = 0;
	double result = 0.0;
	printf("Please enter the z, x, and a variables to put into the 'general equation': ");
	scanf("%d%d%d", &z, &x, &a);
	result = calculate_general_equation(a, x, z);
	printf("Equation = %lf", result);

	return 0;
}


