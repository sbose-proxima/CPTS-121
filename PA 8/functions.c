#include "headers.h"



char* my_str_n_cat(char* destination, char* source, int n){
        while (*destination != '\0'){
            destination++;
        }


        for (int i = 0; i < n && *source != '\0'; i++){
            *destination = *source;
            destination++;
            source++;
        }

        *destination = '\0';

    return destination;   
}

int binary_search(int *sorted_list, int n, int target){
    int left = 1, right = n, flag = 0, target_num = -1;

    while (!flag && left <= right){
        int middle = (left+right)/2;

        if (sorted_list[middle] == target){
            flag = 1; target_num = middle;
        }

        else{
        if (target < sorted_list[middle]){
            right = middle - 1;
        }
        if (target < sorted_list[middle]){
            right = middle + 1;
        }
    }
    }

return target_num;

}





void bubble_sort(char *str[], int n){
    int u = n, counter = 0;

    do
    {
       for (int i = 1; i < u; i++){
            if (strcmp(str[i], str[i-1]) < 0) {
                char *temp = str[i];
                str[i] = str[i-1];
                str[i-1] = temp;
            }
       }
       u--;
    } while (u > 0);
    
}


int is_palindrome(char* str, int len){ //help taken from a friend to solve this one
    int palindrome = 0, strlen = 0;

    for (int i = 0; str[i] != '\0'; i++){
        len++;
    }

    int first_index = strlen;

    if (isspace(str[len-1] || isspace(str[first_index]))){
        palindrome = is_palindrome(str, len-1);
    } else if(*(str+first_index) != *(str+len-1)){
        palindrome = 0;
    } else{
        if (*(str+first_index+1)!= '\0'){
            palindrome = is_palindrome(str, len-1);
        }
    }
return palindrome;
}



int prime_finder(int num, int div){
    int prime = 1;

    if (num == div){
        return 1;
    } 
    
    else{
        if (num % div == 0){
            prime = 0;
    }
        else{
            prime = prime_finder(num, div + 1);
        }
}
return prime;
}


int sum_primes (int n){
    int sum = 0;

    if (n <= 2){
        sum = 2;
    }

    else{
        if (prime_finder(n,2)){
            sum = n + sum_primes(n-1);
        } else{
            sum = sum_primes(n-1);
        }
    }

    return sum;
}





void maximum_occurences(char *str, Occurences arr[], int* maximum_occurences, char* c){
    int i = 0, counter = 0, occur_index = 0;
    while (str[i] != '\0'){
        counter++;
        char curr_char = str[i];

        for (int j = i; str[j] != '\0'; j++){
            if(str[j] == curr_char){
                arr[occur_index].num_occurences++;
            }
        }

        arr[occur_index].frequency = arr[occur_index].num_occurences / counter;

        if (arr[occur_index].num_occurences > *maximum_occurences){
            *maximum_occurences = arr[occur_index].num_occurences;
            *c = curr_char;
        }

        occur_index++;
        i++;
    }
    
}














void maximum_consecutive_integers(int arr[][100], int rows, int cols, int *start_ptr, int *length_ptr){
    int max_len = 1;
    int *max_start = &arr[0][0];

    int current_len = 1;
    int *current_start = &arr[0][0];

    for (int i = 1; i < rows * cols; i++){
        int prev_row = (i-1)/cols;
        int prev_col = (i-1)%cols;

        int curr_row = i / cols;
        int curr_col = i % cols;

        if (arr[prev_row][prev_col] == arr[curr_row][curr_col]){
            current_len++;
        } else{
            if (current_len > max_len){
                max_len = current_len;
                max_start = &arr[(i - current_len)/cols][(i-current_len) % cols];
            }

            current_len = 1;
        }

    }

    if (current_len > max_len){
        max_len = current_len;
        max_start = &arr[(rows*cols-current_len)/cols][(rows*cols-current_len)%cols];
    }

    *start_ptr = *max_start;
    *length_ptr = max_len;
}
