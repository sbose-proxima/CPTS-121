/*
Programmer: Svanik Bose
Class: CptS 121, Spring 2025, Andy S. O'Fallon
Lab Section: 08, TA: Rachel Jones
Date: 01/31/2025
Description: Using functions in equations.h and equations.c, 
this main.c file takes inputs from the users and calls the
respective functions to calculate values based off of
equations. 


*/


#include "equations.h"



int main(void)
{
    // Newton's Second Law
    float force = 0.0, mass = 0.0, acceleration = 0.0;
    printf("Please type the values for mass and acceleration <both floating point values>: "); // take user input for the values
    scanf("%f%f", &mass, &acceleration);
    force = newtons_second_law(mass, acceleration); //call function to calculate the force
    printf("Force = Mass * acceleration = %f * %f = %.2f\n\n", mass, acceleration, force); //display formula and value 

    printf("_______________________________________________________________________________\n");

    // Volume of a cylinder
    float radius = 0.0, height = 0.0, volume = 0.0;
    printf("Please type the values for the radius and height of your cylinder <both floating point values>: "); // take user input for the values
    scanf("%f%f", &radius, &height);
    volume = volume_of_cylinder(radius, height); //call function to calculate the volume
    printf("Volume = pi * radius * radius * height = 3.14159*%f*%f*%f = %.2f\n\n", radius, radius, height, volume); //display formula and value 

    printf("_______________________________________________________________________________\n");

    // Character encoding
    char plaintext_character = '\0', encoded_character = '\0';
    printf("Enter your plaintext character: "); //take user input for the plaintext character
    scanf(" %c", &plaintext_character);
    encoded_character = character_encoding(plaintext_character); //call function to find the encoded character
    printf("Your encoded character is: %c\n\n", encoded_character); //display formula and character 

    printf("_______________________________________________________________________________\n");

    // Phosphate atomic mass 
    float hydrogen_mass = 1.008, oxygen_mass = 16.00, phosphorus_mass = 30.97, phosphate_mass = 0.0;
    phosphate_mass = phosphate_atomic_mass(hydrogen_mass, oxygen_mass, phosphorus_mass); //call function to calculate phosphate's atomic mass
    printf("The atomic mass of phosphate in amu is 3*%f+4*%f+%f = %.2f\n\n", hydrogen_mass, oxygen_mass, phosphorus_mass, phosphate_mass); //display formula and value 

    printf("_______________________________________________________________________________\n");

    //Projectile motion
    float projectile_height = 0.0, initial_height = 0.0, initial_velocity = 0.0, time = 0.0;
    printf("Enter the initial height, initial velocity, and time <all floating point values>: "); // take user input for the values
    scanf("%f%f%f", &initial_height, &initial_velocity, &time);
    projectile_height = projectile_motion(initial_height, initial_velocity, time); //call function to calculate the projectile height
    printf("The height of your projectile in meters is: -16 * %f*%f + %f *%f + %f = %.2f\n\n", time, time, initial_velocity, time, initial_height, projectile_height);
    //^ display formula and value

    printf("_______________________________________________________________________________\n");

    //Current through a circuit
    float power = 0.0, resistance = 0.0, current = 0.0;
    printf("Enter the power and resistance in your circuit: "); // take user input for the values
    scanf("%f%f", &power, &resistance);
    current = circuit_current(power, resistance); // call function to calculate the current 
    printf("The current in your circuit is: sqrt(%f/%f) = %.2f\n\n", power, resistance, current); //display formula and value 

    printf("_______________________________________________________________________________\n");

    //General Equation
    float x = 0.0, z = 0.0, y = 0.0;
    int a = 0;
    printf("Enter values for x and z: ");
    scanf("%f%f", &x, &z);
    printf("Enter the values for a: ");
    scanf("%d", &a);
    y = general_equation(x, z, a);
    printf("The value of y is: (3.0)/(4.0) * %f-%f/(%d %% 2)+PI) = %.2f\n\n", x, z, a, y);






    




    return 0;
}
