#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void welcome_screen();
void initialize_game_board();
void change_player(int *current_player);
int select_who_starts_first();
void log_stats();
void update_stats(int hit, int current_player);
void check_hit (int x, int y, int current_player);
void startgame();
int all_ships_sunk (char board[10][10]);
void automatically_place_ships2(int *current_player);
void automatically_place_ships3(int *current_player);
void manually_place_ships2(int *current_player);
void player_turn();
void computer_turn();


typedef struct {
    int total_hits;
    int total_misses;
    int total_shots;
    float hit_miss_ratio;
} Stats;
