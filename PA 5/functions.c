#include "headers.h"

void print_rules(){
    printf("The rules of the game are printed below:\n");
    printf("____________________________________________\n");
    printf("1. Each player will roll 5 dice at once \n");
    printf("1a. They can either choose to keep the combination of the sum of the dice, or they or they can choose to re-roll specific dice to attain a more desirable combination\n");
    printf("2. There are a total of 13 unique combinations of dice sums from which a player can choose\n");
    printf("2a. Once a combination has been chosen by player, it cannot be re-chosen for the remainder of the game\n");
    printf("2b. The combination of these sums consist of an upper section of sums 1-6 and a lower section of 'chance'\n");
    printf("3. These rounds will occur a total of 13 times for both players, after which the game of Yahtzee ends\n");
    printf("4. Once the sums have been totalled, if any player has obtained at least 63 points, they will be awarded a bonus of 35 points\n");
    printf("5. The player who has obtained the most amount of points wins the game!\n");
    printf("____________________________________________\n");
    printf("Below are the numbers you will type for each game combination\n");
    printf("UPPER SECTION:");
    printf("____________________________________________\n");
    printf("1. Sum of all 1's\n");
    printf("2. Sum of all 2's\n");
    printf("3. Sum of all 3's\n");
    printf("4. Sum of all 4's\n");
    printf("5. Sum of all 5's\n");
    printf("6. Sum of all 6's\n");
    printf("LOWER SECTION\n");
    printf("____________________________________________\n");
    printf("7. Three of a Kind\n");
    printf("8. 4 of a kind\n");
    printf("9. Full House\n");
    printf("10. Small Straight\n");
    printf("11. Large Straight");
    printf("Yahtzee!");
    printf("Chance!");


    }



int roll_dice(){
    int rand_num = rand() % 6 + 1;
    return rand_num;
}

int sum_dice(int dice[]){
    int sum = 0;
    for (int i=0; i <5; i++)
     sum += dice[i];
     return sum;

}

void change_player(int *current_player){
    if (*current_player == 1)
        *current_player = 2;
    else
        *current_player = 1;
}

void start_game(){
    printf("Welcome to Yahtzee!\n");

    int player1_combinations[] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
    int player2_combinations[] = {1,1,1,1,1,1,1,1,1,1,1,1,1};

    int *score = 0;
    int current_player = 1;

    int dice[5];
    int dice_to_reroll[5];
    char y_n_reroll;
    int num_rolls = 0;
    int max_rolls = 3;
    int input_count = 0;

    for(int round = 0; round < 13; round++){
        printf("Player %d's turn\n", current_player);
    }

    char dice_roll_input;
    printf("Please type 'r' to roll all 5 dice at once\n");
    scanf(" %c", &dice_roll_input);
    
    if (dice_roll_input == 'r'){

    for (int i = 0; i <5; i++){
        dice[i] = roll_dice();
    }
    printf("Your roll produced: ");
    for (int i=0; i<5; i++){
        printf("%d", dice[i]);
    }

    }

    while (num_rolls < max_rolls){


        printf("Do you want to re-roll any dice? Type 'y' if yes or 'n' if no.\n");
        scanf(" %c", y_n_reroll);

        if (y_n_reroll == 'y'){
            num_rolls++;
            while (input_count < 5){
                printf("Type the numbers of the dice you want to re-roll, separated by spaces.\n");
                scanf("%d", &dice_to_reroll[input_count]);
                input_count++;
            }

            for (int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                if(dice[i] == dice_to_reroll[j])
                    dice[i] = roll_dice();
                }
            }



            printf("Here are your new dice values\n");
            for(int i=0; i<5; i++){
                printf("%d", dice[i]);
            }
            printf("The sum of your dice is: %d\n", sum_dice(dice));
            
            }


            
        if (y_n_reroll == 'n' || num_rolls == max_rolls){
            break;
        }




        }


       int *player_combinations;
       if (current_player == 0)
            player_combinations = player1_combinations;
       else 
            player_combinations = player2_combinations;

        printf("Please choose which game combination you would like to score in, refer to rules to what integer to type for each combination:\n");
        choose_combinations(player_combinations);
        

        int comb_chosen = choose_combinations(player_combinations);

        switch (comb_chosen){
            case 1: case 2: case 3: case 4: case 5: case 6:
            sum_of_num(dice, &score, comb_chosen);
            break;

            case 7:
            three_of_a_kind(dice, &score, comb_chosen);

            case 8:
            four_of_a_kind(dice, &score, comb_chosen);

            case 9:
            full_house(dice, &score, comb_chosen);

            case 10:
            small_straight(dice, &score, comb_chosen);

            case 11:
            large_straight(dice, &score, player_combinations);

            case 12:
            yahtzee(dice, &score, comb_chosen);

            case 13:
            chance(dice, &score, comb_chosen);

        }

        printf("Player 1 Scores: %d%d\n", current_player, *score);
        change_player(&current_player);
    }



int choose_combinations(int player_combinations[13]){
    int comb_chosen = 0;
    printf("Available game combinations are below");
    for (int i=0; i <13; i++){
        if (player_combinations[i] == 1)
            printf("%d. Combination %d\n", i+1, i+1);
    }

    do {
        printf("Enter the number scoring combination you would like:\n ");
        scanf("%d", &comb_chosen);
    } while (comb_chosen < 1 || comb_chosen > 13 || player_combinations[comb_chosen - 1] ==0);

    player_combinations[comb_chosen - 1] = 0;
    return comb_chosen;

}




int of_a_kind_checker(int dice[], int num_dice){
    int counter[7] = {0};
    for (int i = 0; i<5; i++){
        counter[dice[i]]++;
    }
    for (int i = 1; i<= 6; i++){
        int checked_number = -1;
        if (counter[i] >= num_dice){
            checked_number = i;
            return 1;
        }
    }
        
    return 0;
}


int three_of_a_kind(int dice[], int *score, int player_combinations[13]){
    if (player_combinations[6] == 1){
        int checker = of_a_kind_checker(dice, 3);
        if (checker == 1)
            *score += sum_dice(dice);
        }
    return *score;
}


int four_of_a_kind(int dice[], int *score, int player_combinations[13]){
    if (player_combinations[7] == 1){
    int checker = of_a_kind_checker(dice, 4);
    if (checker == 1)
        *score += sum_dice(dice);
    }
    return *score;
}


int sum_of_num(int dice[], int *score, int num_to_sum){
    int sum = 0;
    for (int i = 0; i < 5; i++){
        if (dice[i] == num_to_sum){
            sum += dice[i];
        }
    }
    *score += sum;
    return *score;
}


int full_house(int dice[], int *score, int player_combinations[13]){
    int counter[7] = {0};
    int check_3 = 0; int check_2 = 0;

    for(int i = 0; i < 5; i++){
        counter[dice[i]]++;

    }

    for (int i = 1; i<= 6; i++){
        if (counter[i] == 3){
            check_3 = 1;
        }
        else if (counter[i] == 2){
            check_2 = 1;
        }
    }

    if (check_3 == 1 && check_2 == 1){
        *score += 25;
    }

    player_combinations[8] = 0;
    return *score;


    }



int small_straight(int dice[], int *score, int player_combinations[13]){
    int counter[7] = {0};
    int consec_nums = 0;

    for (int i = 0; i < 5; i++){
        if (counter[i]){
            consec_nums++;
            if (consec_nums >= 4){
                *score += 30;
                break;
            }
        }
        else {
            consec_nums = 0;
        }
    }

    player_combinations[9] = 0;
    return *score;
}




int large_straight (int dice[], int *score, int player_combinations[13]){
    int counter[7] = {0};
    
    for (int i = 0; i < 5; i++){
        counter[dice[i]] = 1;
    }
    if (counter[1] == 1 && counter[2] == 1 && counter[3] == 1 && counter[4] == 1 && counter[5] == 1 ||
     counter[2] == 1 && counter[3] == 1 && counter[4] == 1 && counter[5] == 1 && counter[6] == 1){
        *score += 40;
    }


    player_combinations[10] = 0;
    return *score;





}



int yahtzee(int dice[], int *score, int player_combinations[13]){
    int counter[7] = {0};
    for (int i = 0; i < 5; i++){
        counter[dice[i++]];
    }
    for (int i = 0; i < 6; i++){
        if (counter[i] == 5){
            *score += 50;
            break;

        }
    }
    }



int chance (int dice[], int *score, int player_combinations[13]){
    *score += sum_dice(dice);
    player_combinations[12] = 0;
    return *score;
}
