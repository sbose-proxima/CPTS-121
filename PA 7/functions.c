#include "headers.h"



void print_menu(){

        printf("The rules of 5-card poker are below:");
        printf("_____________________________________");
        printf("Both players will be dealt 5-cards");
        printf("Each player can choose to swap out 3 cards in their hand in hopes of getting a better hand\n");
        printf("The player with the stronger hand wins a point\n");
        printf("If both players have equally strong hands, the player with the higher card wins the point\n");
        printf("The player with the most points wins the game\n");
        printf("Press 2 to play the game and 3 to exit\n");

}



void shuffle (int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand () % 4;
			column = rand () % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}



void display_hand(Hand *h, const char *wFace[], const char *wSuit[]){
	for (int i = 0; i < 5; i++){
		printf("%d: %-5s of %-8s\n", i, wFace[h->cards[i].face_value], wSuit[h->cards[i].suit]);
	}
}



void replace_hand(Hand *h, const char *wFace[], const char *wSuit[]){
	int replace_index;
	int replace_count = 0;

	printf("You can replace up to three cards. Enter -1 to stop early.\n");

	while (replace_count < 3){
		printf("Enter index (0-4) of a card to replace it. Press -1 to stop\n ");
		if (scanf("%d", &replace_index) != 1){
			while(getchar()!='\n');
			printf("Invalid Input. Please enter a number");
			continue;
		}

		if (replace_index == -1){
			break;
		}
	


	if (replace_index >= 0 && replace_index < 5){
		h->cards[replace_index].face_value = rand() % 13;
		h->cards[replace_index].suit = rand() % 4;
		replace_count++;

		printf("Card(s) replaced.\n");
	} else{
		printf("Invalid Index.\n");
	}




	}

	printf("Your new hand:\n");
	display_hand(h, wFace, wSuit);

}


void start_game(int deck[4][13], const char *wFace[], const char *wSuit[]){
	int play = 1;

	while (play){
		Hand player = {0}, dealer = {0};

		shuffle(deck);

		deal(deck, &player, 1);
		deal(deck, &dealer, 6);

	printf("Your hand:\n");
	display_hand(&player, wFace, wSuit);
	print_available_combinations(&player);

	replace_hand(&player, wFace, wSuit);

	printf("Dealer is replacing cards...\n");
	int dealer_replace_count = rand()%4;
	for (int i = 0; i < dealer_replace_count; i++){
		int rand_index = rand()%5;
		dealer.cards[rand_index].face_value = rand()%13;
		dealer.cards[rand_index].suit = rand() % 4;
	}

	printf("\nDealers hand:\n");
	display_hand(&dealer,wFace,wSuit);

	printf("\n--- Dealer Hand Evaluation ---\n");
	int dealer_score = print_available_combinations(&dealer);

	printf("\n--- Player Hand Evaluation ---\n");
	int player_score = print_available_combinations(&player);


	if (player_score > dealer_score){
		printf("THE HUMAN PLAYER WON THE ROUND!\n");
	}

	if (player_score < dealer_score){
		printf("THE COMPUTER WON THIS ROUND!\n");
	}

	if (player_score == dealer_score){
		printf("PLAYER AND COMPUTER TIED!\n");
	}

	}


}

int play_again(){
	int play = 0;
	printf("\n Play Again: Type 1. Quit: Type 0");
	scanf("%d", &play);

	if (play == 1){
		return 1;
	} else{
		return 0;
	}


}


void deal(const int deck[4][13], Hand *h, int card_num){
	int card_count = 0;

	for (int card = card_num; card <= 52 && card_count < 5; card++){
		for (int row = 0; row < 4; row++){
			for (int col = 0; col < 13; col++){
				if (deck[row][col] == card){
					h->cards[card_count].face_value = col;
					h->cards[card_count].suit = row;
					card_count++;
					if (card_count == 5){
						return;
					}
				}
			}
		}
	}
}


int num_of_a_kind(Hand *h, int num){
	int counts[13] = {0};

	for (int i = 0; i < 5; i++){
		int val = h->cards[i].face_value;
		counts[val]++;
	}

	for (int i = 0; i < 13; i++){
		if (counts[i] == num)
			return 1;
	}
return 0;
}




int determine_flush(Hand *h){
	int flush_suit = h->cards[0].suit;

	for (int i = 1; i < 5; i++){
		if (h->cards[i].suit != flush_suit){
			return 0;
		}
	}
	return 1;
}


int determine_pair(Hand *h){
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if (h->cards[i].face_value == h->cards[j].face_value){
				return 1;
			}
		}
	}
	return 0;
}


int determine_twopair(Hand *h){
	int pair_count = 0;
	int matched[5]  = {0};

	for (int i = 0; i < 5; i++){
		if (matched[i])
			continue;
		for (int j = i+1; j < 5; j++){
			if (!matched[j] && h->cards[i].face_value == h->cards[j].face_value){
				pair_count++;
				matched[i] = 1;
				matched[j] = 1;
				break;
			}
			
		}
	}

	if (pair_count == 2){
		return 1;
	} else{
		return 0;
	}
}


void sort(int *arr, int size){
	for (int i = 0; i < size - 1; i++){
		for (int j = 0; j < size - i - 1; j++){
			if (arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int determine_straight(Hand *h){
	int values[5];
	for (int i = 0; i < 5; i++){
		values[i] = h->cards[i].face_value;
	}

	sort(values,5);

	for (int i = 0; i < 4; i++){
		if (values[i] == values[i+1]){
			return 0;
		}
	
		if (values[i] + 1 != values[i+1]){
			return 0;
		}
	}
return 1;
}





int determine_fullhouse(Hand *h){
	int counter[13] = {0};

	for (int i = 0; i < 5; i++){
		int val = h->cards[i].face_value;
		counter[val]++;
	}

	int has_three = 0;
	int has_two = 0;

	

	for (int i = 2; i <= 13; i++){
		if (counter[i] == 3){
			has_three = 1;
		} else if (counter[i] == 1){
			has_two = 1;
		}
	}

	if (has_two && has_three){
		return 1;
	}


	return 0;
}







int print_available_combinations(Hand *h){
	int score = 0;


	if (determine_pair(h)){
		printf("The deck has a pair!\n");
		score += 1;
	}

	if (determine_twopair(h)){
		printf("The deck has two pairs!\n");
		score += 2;
	}

	if (num_of_a_kind(h, 3)){
		printf("The deck contains 3 of a kind\n");
		score += 3;
	}


	if (num_of_a_kind(h, 4)){
		printf("The deck contains 4 of a kind\n");
		score += 4;
	}

	if (determine_fullhouse(h)){
		printf("The deck contains a full house\n");
		score += 5;
	}

	
	if (determine_flush(h)){
		printf("The deck has a flush\n");
		score += 6;
	}



	if (determine_straight(h)){
		printf("Your deck has a straight!\n");
		score += 7;
	}

	return score;
}
