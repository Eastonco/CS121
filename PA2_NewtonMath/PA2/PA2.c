#include "PA2.h"


/***********************************************************
* Function purpose: to calculate newtons 2nd law           *
* Inputs: Mass and accelleration as doubles                *
* Output: The force created through mass * acceleration    *
***********************************************************/
double calc_newtons_2nd_law(double mass, double accl) {
	double f = 0.0;
	f = mass * accl; //calculation
	return f;
}

/***********************************************************
* Function purpose: to calculate the volume of a cylinder  *
* Inputs: The radius and height of the cyliner             *
* Output: The volume of the cylinder                       *
***********************************************************/
double calc_volume_cylinder(double radius, double height) {
	double vol = 0.0;
	vol = M_PI * (pow(radius, 2)) * height;
	return vol;
}

/***********************************************************
* Function purpose: to encode a plaintext character        *
* Input: the plaintext character to be encoded             *
* Output: The encoded character                            *
***********************************************************/
char perform_character_encoding(char plaintext_character) {
	char eccd_chr = '\0';
	eccd_chr = (plaintext_character - 'a') + 'A';
	return eccd_chr;
}

/***********************************************************
* Function purpose: to calculate the force of gravity      *
* Inputs: Two masses and the distance between the two      *
* Output: The force of gravity between the two objects     *
***********************************************************/
double calculate_gravity_force(double mass1, double mass2, double distance) {
	double f = 0.0;
	f = (G * mass1 * mass2) / (distance * distance);
	return f;
}

/***********************************************************
* Function purpose: to calculate the resistance divider    *
* Inputs: Two resistances and the voltage in               *
* Output: The voltage out                                  *
***********************************************************/
double calculate_resistive_divider(double resistance1, double resistance2, double vin) {
	double vout = 0.0;
	vout = resistance2 / (resistance1 + resistance2) * vin;
	return vout;
}

/*******************************************************************
* Function purpose: to calculate the distance between two points   *
* Inputs: the X and Y cordinates of the two points                 *
* Output: The distance between the two points as a double          *
*******************************************************************/
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2) {
	double distance = 0.0;
	distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return distance;
}

/********************************************************************
* Function purpose: To calculate the answer of a general equation   *
* Inputs: Three numbers as doubles                                  *
* Output: The result of the equation with the said inputs           *
********************************************************************/
double calculate_general_equation(int a, double x, double z) {
	double result = 0.0;
	result = ((float)89 / (float)27) - z * x + a / (a % (int)2);
	return result;
}