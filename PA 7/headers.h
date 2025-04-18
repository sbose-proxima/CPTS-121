#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct card {
    int face_value;
    int suit;
} Card;

typedef struct hand {
    Card cards[5];
} Hand;

void print_menu();
void shuffle (int wDeck[][13]);
void display_hand(Hand *h, const char *wFace[], const char *wSuit[]);
void replace_hand(Hand *h, const char *wFace[], const char *wSuit[]);
void start_game(int deck[4][13], const char *wFace[], const char *wSuit[]);
int play_again();
void deal(const int deck[4][13], Hand *h, int *card_num);
int num_of_a_kind(Hand *h, int num);
int determine_flush(Hand *h);
int determine_pair(Hand *h);
int determine_twopair(Hand *h);
void sort(int *arr, int size);
int determine_straight(Hand *h);
int determine_fullhouse(Hand *h);
int print_available_combinations(Hand *h);


