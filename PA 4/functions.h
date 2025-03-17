#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
int rollDie(void);
int is_win_loss_or_point (int sum_dice);
int is_point_loss_or_neither (int sum_dice, int point_value);
double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract);
void chatter (int win_loss_check, double bank_balance, double wager_amount);
