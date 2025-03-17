/* Class: Cpt_S 121, Spring 2025 Instructor: Andy S. O'Fallon
Programmer: Svanik Bose, Lab Section: 08, TA: Rachel Jones

Description: This program allows the user to play the betting game of craps, 
wagering a certain amount and rolling die to either win or lose money. 
*/





#include "functions.h"

int main(void){

    printf("  /$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$ \n");
	printf(" /$$__  $$| $$__  $$ /$$__  $$| $$__  $$ /$$__  $$\n");
	printf("| $$  \\__/| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  \\__/\n");
	printf("| $$      | $$$$$$$/| $$$$$$$$| $$$$$$$/|  $$$$$$ \n");
	printf("| $$      | $$__  $$| $$__  $$| $$____/  \\____  $$\n");
	printf("| $$    $$| $$  \\ $$| $$  | $$| $$       /$$  \\ $$\n");
	printf("|  $$$$$$/| $$  | $$| $$  | $$| $$      |  $$$$$$/\n");
	printf(" \\______/ |__/  |__/|__/  |__/|__/       \\______/ \n\n\n");


    printf("Welcome to Craps!\n");
	print_rules();




	double bank_balance = 0.0, wager = 0.0;
	int wager_check = 0, die1 = 0, die2 = 0, sum_dice = 0, win_loss_checker = 0, point_value = 0;

while (bank_balance <= 0){
	bank_balance = get_bank_balance();
}
	

while (bank_balance > 0){
	wager = get_wager_amount();
	wager_check = check_wager_amount(wager, bank_balance);




if (wager_check == 1){
	chatter(win_loss_checker, bank_balance, wager);
	srand((unsigned int)time(NULL));

	sum_dice = rollDie();

	win_loss_checker = is_win_loss_or_point(sum_dice);

	if (win_loss_checker == -1){
		point_value = sum_dice;
		printf(" Your point value is:  %d  ", point_value);
	}

		while (win_loss_checker == -1){
			sum_dice = rollDie();

			win_loss_checker = is_point_loss_or_neither(sum_dice, point_value);
			
			
				

			}
	



	bank_balance = adjust_bank_balance(bank_balance, wager, win_loss_checker);
	printf("Your balance is: %lf ", bank_balance);

	if (bank_balance == 0)
		printf("Oh no! You have lost all your money! Restart the game to play more");

	



	
	





	}




}





}
