#include "headers.h"

int main(void){
    //TASK 1
    printf("Task 1\n");
    printf("_______\n");

    char source[] = "table";
    char destination[] = "pool";
    my_str_n_cat(destination, source, 4);

    printf("%s\n", destination);

    printf("-----------------------------------------------------------------");


    //TASK 2
    printf("\nTask 2\n");
    printf("_______\n");
    int numbers[] = {1,3,5,6,7,9};
    int size = 6, target = 6;
    int found = binary_search(numbers, size, target);
    printf("%d will be found in index %d\n", target, found);


    printf("-----------------------------------------------------------------");




    //TASK 3
    printf("\nTask 3\n");
    printf("_______\n");

    char *str[] = {"cpts121", "is", "cool"};
    int n = sizeof(str)/sizeof(str[0]);

    bubble_sort(str, n);

    printf("\nBubble-Sorted array:\n");
    for (int i = 0; i < 3; i++){
        puts(str[i]);
    }
    printf("-----------------------------------------------------------------");



    //TASK 4
    printf("\nTask 4\n");
    printf("_______\n");

    char *firstword = "race car", *secondword = "computer";
    printf("%s: %d\n", firstword, is_palindrome(firstword, 8));
    printf("%s: %d\n", secondword, is_palindrome(secondword, 8));

    printf("-----------------------------------------------------------------");


    //TASK 5
    printf("\nTask 5\n");
    printf("_______\n");
    
    int number = 17;
    printf("The sum of all prime numbers from 2 to %d is %d.\n", number, sum_primes(number));
    printf("-----------------------------------------------------------------");



    //TASK 6
    printf("\nTask 6\n");
    printf("_______\n");

    Occurences occurs[100] = {0};
    char *string = "testing";
    int max_num = 0;
    int max_charac = '\0';

    maximum_occurences(string, occurs, &max_num, &max_charac);

    printf("The most common character is '%c' with %d occurrences.\n", max_charac, max_num);



    printf("-----------------------------------------------------------------");

    //TASK 7
    printf("\nTask 7\n");
    printf("_______\n");

    int matrix[3][100] = {
        {1,2,2,2},
        {2,2,3,4},
        {4,4,4,4}
    };

    int start_val;
    int length;

    maximum_consecutive_integers(matrix, 3, 4, &start_val, &length);

    printf("Max consevutive length: %d\n", length);
    printf("Consecutive value: %d\n", start_val);

    return 0;
    




}
