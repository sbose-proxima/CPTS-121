/*
Programmer: Svanik Bose
Class: CptS_121, Andy S. O'Fallon
Lab Section:08, TA: Rachel Jones
Date: 1/31/2025
Description: This file contains all the functions and return
values which are called in the main.c file
*/


#include "equations.h"

/*
Function name: newtons_second_law
Programmer: Svanik Bose

Date Created: 01/26/2025
Date Last Modified: 01/26/2025

Description: This function calculates the force on an object
given the values for mass and acceleration. It uses newton's
second law for this operation

Input Parameters: mass, acceleration

Preconditions: mass and acceleration must be provided, mass should not be negative
Postconditions: The force (mass*acceleration) is returned


*/

double newtons_second_law(double mass, double acceleration) {
    return mass*acceleration;
}



/*
Function name: volume_of_cylinder
Programmer: Svanik Bose

Date Created: 01/26/2025
Date Last Modified: 01/26/2025

Description: This function calculates the volume of a cylinder
based off of the equation. Using the user inputs, it calculates
the volume and retuns that value. 

Input Parameters: radius, height

Preconditions: radius, height, are positive
Postconditions: The volume of the cylinder is returned


*/


double volume_of_cylinder(double radius, double height) {
    return PI*radius*radius*height;

}


/*
Function name: character_encoding
Programmer: Svanik Bose

Date Created: 01/26/2025
Date Last Modified: 01/26/2025

Description: This function, converts a plaintext 
character inputted by the user into an encoded
character. 

Input Parameters: plaintext_character

Preconditions: character has ASCII value which wont return a blank when put through this function
Postconditions: returns some random character corresponding to the ASCII value calculated through the function


*/



char character_encoding(char plaintext_character) {
    return (plaintext_character - '7') + 'A';

}



/*
Function name: phosphate_atomic_mass
Programmer: Svanik Bose

Date Created: 01/26/2025
Date Last Modified: 01/26/2025

Description: Using the different atomic masses for hydrogen, oxygen, 
and phosphorus, this function uses a special formula to calculate
the atomic mass of the molecule phosphate

Input Parameters: No user input

Preconditions: all element masses are preset
Postconditions: returns a set atomic mass of phosphate calculated using formula


*/

double phosphate_atomic_mass(double hydrogen_mass, double oxygen_mass, double phosphorus_mass) { 
    return 3*hydrogen_mass+4*oxygen_mass+phosphorus_mass;

}


/*
Function name: projectile_motion
Programmer: Svanik Bose

Date Created: 01/26/2025
Date Last Modified: 01/26/2025

Description: Using the formula for the height of a projectile 
this formula takes the user inputted values and plugs them
into the formula to calculate the height of a projectile
in meters. 

Input Parameters: time, initial_velocity, initial_height

Preconditions: time value must be positive
Postconditions: returns height in meters, calculated with formula


*/


double projectile_motion(double initial_height, double initial_velocity, double time) {
    return -16 * time*time + initial_velocity *time + initial_height;

}

/*
Function name: circuit_current
Programmer: Svanik Bose

Date Created: 01/26/2025
Date Last Modified: 01/26/2025

Description: Using the formula for the current flowing through
a circuit, this formula takes user inputted values
for power and resistance, and calculates the current
flowing through a circuit with those values for power
and resistance. 

Input Parameters: power, resistane

Preconditions: values inputted must be positive, otherwise square root cannot be taken
Postconditions: returns the current flowing through the circuit, in amps. 


*/


double circuit_current(double power, double resistance) {
    return sqrt(power/resistance);

}





/*
Function name: general_equation
Programmer: Svanik Bose

Date Created: 01/26/2025
Date Last Modified: 01/26/2025

Description: Using the general equation provided to us
for this PA, this function takes the values inputted by
the user for x,z, and a, puts them into the general equation
and returns the value. 

Input Parameters: x, z, a

Preconditions: a must be an integer value
Postconditions: returns final value with specific numbers put through general equation. 


*/
double general_equation(double x, double z, int a) {
    return ((double) 3/ (double) 4) * x - z/((a%2) + PI);
}
