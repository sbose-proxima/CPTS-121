#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct occurences{
    int num_occurences;
    double frequency;
} Occurences;




char* my_str_n_cat(char* destination, char* source, int n);
int binary_search(int *sorted_list, int n, int target);
void bubble_sort(char *str[], int n);
int is_palindrome(char* str, int len);
int prime_finder(int num, int div);
int sum_primes (int n);
void maximum_occurences(char *str, Occurences arr[], int* maximum_occurences, char* c);
void maximum_consecutive_integers(int arr[][100], int rows, int cols, int *start_ptr, int *length_ptr);

