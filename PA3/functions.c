#include "functions.h"

/*
Function Name: read_double

Programmer: Svanik Bose

Date Created: 02/02/2025
Date Last Modified: 02/02/2025

Description: Reads floating points numbers within the file

Input Parameters: Inputs from the file

Preconditions: Item being read must be a floating point number
Postconditions: Returns floating point number that was found in the file


*/
double read_double(FILE *infile) {
    double number = 0.0;
    fscanf(infile, "%lf", &number);
    return number;
}

/*
Function Name: read_integer

Programmer: Svanik Bose

Date Created: 02/02/2025
Date Last Modified: 02/02/2025

Description: Reads integer numbers within the file

Input Parameters: Inputs from the file

Preconditions: Item being read must be an integer
Postconditions: Returns integer that was found in the file


*/

int read_integer(FILE *infile){
    int number  = 0; 
    fscanf(infile, "%d", &number);
    return number;

}


/*
Function Name: calculate_Sum

Programmer: Svanik Bose

Date Created: 02/02/2025
Date Last Modified: 02/02/2025

Description: Calculates the sum of values receieved

Input Parameters: any numbers given to the function

Preconditions: numbers have to be positive 
Postconditions: Returns sum of the numbers


*/

double calculate_Sum(double num1, double num2, double num3, double num4, double num5){

    double sum = num1+num2+num3+num4+num5;
    return sum;

}


/*
Function Name: calculate_mean

Programmer: Svanik Bose

Date Created: 02/02/2025
Date Last Modified: 02/02/2025

Description: calculates the mean of values given

Input Parameters: sum of numbers

Preconditions: sum input must be the sum of numbers
Postconditions: Returns the calculated mean


*/

double calculate_mean(double sum, int number){

    return sum/number;

}

/*
Function Name: calculate_deviation

Programmer: Svanik Bose

Date Created: 02/02/2025
Date Last Modified: 02/02/2025

Description: Calculates the deviation of a number from the rest of the set

Input Parameters: 

Preconditions: Needs the mean value calcualted by calculate_mean
Postconditions: Returns the deviation of a single number

*/


double calculate_deviation (double number, double mean){
    
    return number-mean;

}


/*
Function Name: calculate_variance

Programmer: Svanik Bose

Date Created: 02/02/2025
Date Last Modified: 02/02/2025

Description: Calculates the variance of the set using the deviation values

Input Parameters: Inputs calculated by calculate_deviation

Preconditions: Needs deviation values calculated by calculate_deviation
Postconditions: Returns the variance


*/

double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number){

    double variance = ((deviation1*deviation1) + (deviation2*deviation2) + (deviation3*deviation3) + (deviation4*deviation4) + ((deviation5*deviation5)))/number;
    return variance;

}

/*
Function Name: calculate_standard_deviation

Programmer: Svanik Bose

Date Created: 02/02/2025
Date Last Modified: 02/02/2025

Description: Calculates the standard deviation of the set

Input Parameters: Inputs from the file, and variance calculated from calulate_variance

Preconditions: Must have values from calculate_variance
Postconditions: Returns the standard deviation. 


*/

double calculate_standard_deviation(double variance){

    return sqrt(variance);

}

/*
Function Name: find_max

Programmer: Svanik Bose

Date Created: 02/02/2025
Date Last Modified: 02/02/2025

Description: Finds the maximum value in a dataset

Input Parameters: numbers given to the system. 

Preconditions: Must have numbers of whichever values being compared. 
Postconditions: Returns the maximum value in the dataset


*/

double find_max(double number1, double number2, double number3, double number4, double number5){

    double max_score = number1;

    if (number2 > max_score){
        max_score = number2;

    }

    if (number3 > max_score){
        max_score = number3;

    }

    if (number4 > max_score){
        max_score= number4;
    }

    if (number5 > max_score){
        max_score = number5;

    }

    return max_score;

}

/*
Function Name: find_min

Programmer: Svanik Bose

Date Created: 02/02/2025
Date Last Modified: 02/02/2025

Description: Finds the minimum value in the dataset. 

Input Parameters: Inputs from the file, and varaince calculated from calulate_variance

Preconditions: Must have numbers of whichever values being compared. 
Postconditions: Returns the minimum value in the dataset


*/
double find_min(double number1, double number2, double number3, double number4, double number5){

    double min_score = number1;

    if (number2 < min_score){
        min_score= number2;

    }

    if (number3 < min_score){
        min_score = number3;

    }

    if (number4 < min_score){
        min_score = number4;

    }

    if (number5 < min_score){
        min_score = number5;
    }

    return min_score;
}


void print_double (FILE *outfile, double number){

    fprintf(outfile, "%.2f\n", number);
}
