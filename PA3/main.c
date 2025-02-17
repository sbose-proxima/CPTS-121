/*
Programmer: Svanik Bose
Class: CptS 121, Spring 2025, Andy S. O'Fallon
Lab Section: 08, TA: Rachel Jones
Date: 02/05/2025
Description: A file contains different student ID's and their respective GPA's, class standings, and ages.
Using those values in a file, this program calculates the GPA mean, the class standing mean, the age mean, 
the GPA standard deviation, the GPA max, and GPA min. The program takes these values in the order that they 
were listed and prints them out into a separate file. 
*/

#include "functions.h"

int main(void){

    FILE *infile = NULL;
    FILE *outfile = NULL;

    // define all needed values
    int studentid1 = 0, studentid2 = 0, studentid3 = 0, studentid4 = 0, studentid5 = 0;
    double gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0;
    int class_stand1 = 0, class_stand2 = 0, class_stand3 = 0, class_stand4 = 0, class_stand5 = 0;
    double age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0;
    

    int sum_class = 0;
    double sum_gpa = 0.0, sum_age = 0.0;
    double mean_gpa = 0.0, mean_age = 0.0, class_stand_mean = 0.0;
    double gpa1_dev = 0.0, gpa2_dev = 0.0, gpa3_dev = 0.0, gpa4_dev = 0.0, gpa5_dev = 0.0;
    double gpa_variance = 0.0;
    double gpa_standard_dev = 0.0;
    double gpa_min = 0.0, gpa_max = 0.0;

    
    infile = fopen("./input.dat", "r");
    outfile = fopen("./output.dat", "a");


    studentid1 = read_integer(infile);
    gpa1 = read_double(infile);
    class_stand1 = read_integer(infile);
    age1 = read_double(infile);


    studentid2 = read_integer(infile);
    gpa2 = read_double(infile);
    class_stand2 = read_integer(infile);
    age2 = read_double(infile);


    studentid3 = read_integer(infile);
    gpa3 = read_double(infile);
    class_stand3 = read_integer(infile);
    age3 = read_double(infile);

    studentid4 = read_integer(infile);
    gpa4 = read_double(infile);
    class_stand4 = read_integer(infile);
    age4 = read_double(infile);

    studentid5 = read_integer(infile);
    gpa5 = read_double(infile);
    class_stand5 = read_integer(infile);
    age5 = read_double(infile);

    fclose(infile);

    //calculate the relevant sums by calling the calculate_Sum function and providing the necessary values
    sum_gpa = calculate_Sum(gpa1, gpa2, gpa3, gpa4, gpa5);
    sum_class = calculate_Sum(class_stand1, class_stand2, class_stand3, class_stand4, class_stand5);
    sum_age = calculate_Sum(age1, age2, age3,age4, age5);

    //calculate the relevant means by calling the calculate_mean function and providing the necessary values
    mean_gpa = calculate_mean(sum_gpa, 5);
    class_stand_mean = calculate_mean(sum_class, 5);
    mean_age = calculate_mean(sum_age, 5);

    //calculate the deviation for each gpa. 
    gpa1_dev = calculate_deviation(gpa1, mean_gpa);
    gpa2_dev = calculate_deviation(gpa2, mean_gpa);
    gpa3_dev = calculate_deviation(gpa3, mean_gpa);
    gpa4_dev = calculate_deviation(gpa4, mean_gpa);
    gpa5_dev = calculate_deviation(gpa5, mean_gpa);

    //find the variance of the gpa's
    gpa_variance = calculate_variance(gpa1_dev, gpa2_dev, gpa3_dev, gpa4_dev, gpa5_dev, 5);

    // calculate the standard deviation of the GPA's form the dataset
    gpa_standard_dev = calculate_standard_deviation(gpa_variance);

    //find the max gpa by calling the correct function
    gpa_max = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);

    //find the min gpa by calling the correct function
    gpa_min  = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);

    //print out all relevant information, in order, to the output file. 
    print_double(outfile, mean_gpa);
    print_double(outfile, class_stand_mean);
    print_double(outfile, mean_age);
    print_double(outfile, gpa_standard_dev);
    print_double(outfile, gpa_min);
    print_double(outfile, gpa_max);


    return 0; //indicates if program has run succesfully. 
}
