#include "headers.h"

int main (void)
{
	/* initialize suit array */
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	/* initialize face array */
	const char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King"};

	/* initalize deck array */
	int deck[4][13] = {0};

	srand ((unsigned) time (NULL)); /* seed random-number generator */



	int choice = 0;
	printf("Press 1 to view rules, 2 to start game, and 3 to exit\n");
	scanf("%d", &choice);
do
{
	if (choice == 1){
		print_menu();
	}
	if (choice == 2){
		start_game(deck, face, suit);
	}

	if (choice == 3){
		break;
	}
} while (choice > 3 || choice < 1);


	int again = play_again();

while (1){
	if (again){
		start_game(deck,face,suit);
	} else{
		break;
	}
 
}

	return 0;
}
