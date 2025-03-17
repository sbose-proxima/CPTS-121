#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void print_rules();
void start_game();
int roll_dice ();
int sum_dice(int dice[]);
int sum_of_num(int dice[], int *score, int num_to_sum, int player_combinations[13]);
int three_of_a_kind(int dice[], int *score, int player_combinations[13]);
int four_of_a_kind(int dice[], int *score, int player_combinations[13]);
int switch_player();
int choose_combinations(int player_combinations[13]);
int full_house(int dice[], int *score, int player_combinations[13]);
int small_straight(int dice[], int *score, int player_combinations[13]);
int large_straight (int dice[], int *score, int player_combinations[13]);
int yahtzee(int dice[], int *score, int player_combinations[13]);
int chance(int dice[], int *score, int player_combinations[13]);
