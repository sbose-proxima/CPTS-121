/*
Programmer: Svanik Bose
ID: 011912554
Class: Cpt_S 121, Spring 2025, Andy S. O'Fallon
Lab Section: 08, TA: Rachel Jones
Programming Assignment #1
Date: 01/23/2025
Description: Using inputs from the user to solve for the output based off an equation. 
*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define PI 3.14159265



int main(void) 
{
    double force=0.0, mass=0.0, acceleration=0.0;

    //1. Newton's Second Law
    // Prompt the user to input values for the mass and acceleration 
    printf("Please enter the mass and acceleration <both floating point values>  of the object: ");
    scanf("%lf%lf", &mass, &acceleration);  
    //The equation for newton's second law:
    force = mass * acceleration;
    printf("Newton's Second Law : force = mass*acceleration =  %lf*%lf = %lf\n", mass, acceleration, force); 


    //2.Volume of a Cylinder
    double volume = 0.0, radius = 0.0, height = 0.0;
    // Prompt the user to input values for the radius and height of the cylinder
    printf("Please enter the radius and height <both floating point values> of your cylinder: ");
    scanf("%lf%lf", &radius, &height);
    //The equation for the volume of a cylinder:
    volume = PI * radius*radius * height;
    printf("Volume of a cylinder = pi * r^2 * h =  PI* (%lf*%lf)*%lf = %lf\n", radius, radius, height, volume);


    //3.Character encoding
    char encoded_character = '\0', plaintext_character = '\0';
    //Prompt the user to enter a character for plaintext_character
    printf("Enter a plaintext character: ");
    scanf(" %c", &plaintext_character);
    //Changing the plaintext character into an encoded character
    encoded_character = plaintext_character - '7' + 'A';
    printf("The plaintext character after the encoding process is: (%c-7)+A = %c\n", plaintext_character, encoded_character);


    //4. Atomic mass of phosphate
    double phosphate_mass = 0.0, hydrogen_mass = 1.008, oxygen_mass = 16.0, phosphorus_mass = 30.97;
    // Calculate the mass of phosphate using the atomic masses of indivudal elements 
    phosphate_mass = (3*hydrogen_mass)+(4*oxygen_mass)+(phosphorus_mass);
    printf("The mass of phoshpate in amu is: 3*%lf+4*%lf+%lf = %lf\n", hydrogen_mass, oxygen_mass, phosphorus_mass, phosphate_mass);



    //5. Height of a projectile in meters
    double height_projectile = 0.0, time = 0.0, initial_velocity = 0.0, initial_height = 0.0;
    //Prompt the user for the time, initial velocity, and initial height values
    printf("Please enter the values for the time, initial velocity, initial height <all are floating point values>: ");
    scanf("%lf%lf%lf", &time, &initial_velocity, &initial_height);
    // Calculate the height of the projectile in meters
    height_projectile = -16*time*time+initial_velocity*time+initial_height;
    printf("The height of your projectile in meters is: -16*(%lf*%lf)+%lf*%lf+%lf = %lf\n", time, time, initial_velocity, time, initial_height, height_projectile);



    //6. Current through circuit in Amperes
    double current = 0.0, power = 0.0, resistance = 0.0;
    //Prompt the user to enter the values for power and resistance:
    printf("Please enter the values for the power and resistance <both floating point values> in the circuit: ");
    scanf("%lf%lf", &power, &resistance);
    //Calculate the current through the circuit in amperes
    current = sqrt(power/resistance);
    printf("The current through the circuit in amperes is sqrt(%lf/%lf) = %lf\n", power, resistance, current);


    //7. General Equation
    int a = 0; 
    double y = 0.0, x = 0.0, z = 0.0;
    //Prompt the user for values of x,z (floating point) that we will use in the general equation
    printf("Please enter the values for x, and z <both floating point values>: ");
    scanf("%lf%lf", &x, &z);
    //Prompt the user for the value of a that we will use in the general equation
    printf("Please enter the values for a <an integer value> : ");
    scanf("%d", &a);
    //Calculate the value of y (integer) using the general equation
    y = ((double) 3/ (double) 4) * x - z/((a%2) + PI);
    printf("The value of y is: (3.0)/(4.0) * %lf-%lf/(%d %% 2)+PI) = %lf\n", x, z, a, y);


    return 0;
}
