#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//define

#define M_PI 3.14159265358979323846 //defining PI
#define G (6.67 * pow(10, -11))//defining the gravity constant

// function declaration/prototypes 
double calc_newtons_2nd_law(double mass, double accl);
double calc_volume_cylinder(double radius, double height);
char perform_character_encoding(char plaintext_character);
double calculate_gravity_force(double mass1, double mass2, double distance);
double calculate_resistive_divider(double resistance1, double resistance2, double vin);
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2);
double calculate_general_equation(int a, double x, double z);