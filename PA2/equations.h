

/*
Programmer: Svanik Bose
Class: CptS_121, Andy S. O'Fallon
Lab Section:08, TA: Rachel Jones
Date: 1/31/2025
Description: This file contains all function headers used in equations.c to 
calculate values based on equations
*/

//start of guard code
#ifndef EQUATIONS_H
#define EQUATIONS_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define PI 3.14159
#endif
//end of guard code

//declar all functions and their respective varaibles

double newtons_second_law(double mass, double acceleration);
double volume_of_cylinder(double radius, double height);
char character_encoding(char plaintext_character);
double phosphate_atomic_mass(double hydrogen_mass, double oxygen_mass, double phosphorus_mass);
double projectile_motion(double initial_height, double initial_velocity, double time);
double circuit_current(double power, double resistance);
double general_equation(double x, double z, int a);
