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
    printf("WARNING! IF YOU CHOOSE A COMBINATION WHICH THE DICE DO NOT QUALIFY FOR, A 0 WILL BE ADDED TO THAT SCORE AND YOU CANNOT REUSE THAT COMBINATION");
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
    printf("8. Four of a kind\n");
    printf("9. Full House (Two of one kind, three of another\n");
    printf("10. Small Straight (4 numbers are in sequence)\n");
    printf("11. Large Straight (5 numbers are in sequence)\n");
    printf("12. Yahtzee! (All 5 numbers are the same)\n");
    printf("13. Chance (add up all numbers on dice) \n");


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

    int player1_score = 0, player2_score = 0;
    int player1_upperscore = 0, player2_upperscore = 0;
    int current_player = 1;
    int *player_combinations, *score, *upper_score;

    int dice[5] = {1,2,3,4,5};
    // int dice_to_reroll[5];
    char y_n_reroll;
    int num_rolls = 0;
    int max_rolls = 3;
    int input_count = 0;



    for(int round = 0; round < 13; round++){
        system("clear"); // must be changed to 'cls' for windows
        num_rolls = 0;
        input_count = 0;
        printf("\n----- Round %d -----\n", round + 1);
        printf("Player %d's turn\n", current_player);
    


    char dice_roll_input;
    printf("Please type 'r' to roll all 5 dice at once\n");
    scanf(" %c", &dice_roll_input);
    
    if (dice_roll_input == 'r'){

    for (int i = 0; i <5; i++){
        dice[i] = roll_dice();
    }
    printf("Your roll produced: ");
    for (int i=0; i<5; i++){
        printf("%d ", dice[i]);
    }
    printf("\n");
    }

    while (num_rolls < max_rolls){
        printf("Do you want to re-roll any dice? Type 'y' if yes or 'n' if no.\n");
        getchar(); // this line was obtained with the help of a friend 
        scanf(" %c", &y_n_reroll);
        // while (getchar() != '\n');
       
        

        if (y_n_reroll == 'y'){
            printf("Type the dice number you want to re-roll, followed by a space, a -1, and another space, then click enter. If you want to re-roll all 5 dice, do not click the -1 at the end, only click enter\n");
            input_count = 0;

            while (input_count < 5){
                int index = 0;
                if (scanf("%d", &index) == 1){
                    if (index == -1){
                        
                        break;
                    }
                    if (index >= 1 && index <= 5){
                        dice[index - 1] = roll_dice();
                        input_count++;
                    
                    }  

                }
               else {
                    printf("Invalid Input.");
                    while (getchar() != '\n');
                }
            }
            
        



            printf("Here are your new dice values\n");
            for(int i=0; i<5; i++){
                printf("%d ", dice[i]);
            }
            printf("\n");
        
            num_rolls++;
            }


            else {
                printf("You chose not to re-roll\n");
                break;
            }
        }

 //printf("The sum of your dice is: %d\n", sum_dice(dice));



       
       if (current_player == 1){
            player_combinations = player1_combinations;
            score = &player1_score;
            upper_score = &player1_upperscore;
       }
       else {
            player_combinations = player2_combinations;
            score = &player2_score;
            upper_score = &player2_upperscore;
       }

    

        
        printf("Please choose which game combination you would like to score in\n");
      
        
        while (getchar() != '\n');
        int comb_chosen = choose_combinations(player_combinations);

        int sums = 0;
        switch (comb_chosen){
            
            case 1: case 2: case 3: case 4: case 5: case 6:
            sums = sum_of_num(dice, score, comb_chosen, player_combinations);
            *upper_score += sums;
            break;

            case 7:
            three_of_a_kind(dice, score, player_combinations);
            break;

            case 8:
            four_of_a_kind(dice, score, player_combinations);
            break;

            case 9:
            full_house(dice, score, player_combinations);
            break;

            case 10:
            small_straight(dice, score, player_combinations);
            break;

            case 11:
            large_straight(dice, score, player_combinations);
            break;

            case 12:
            yahtzee(dice, score, player_combinations);
            break;

            case 13:
            chance(dice, score, player_combinations);
            break;

        }

if (*upper_score >= 63){
            *score += 35;
            printf("You got a 35 point bonus for having 63 or more points in your upper section!");
        }

        printf("Player 1 Total: %d player 1 upper: %d\n", player1_score, player1_upperscore);
        printf("Player 2 Total: %d, player 2 upper: %d\n", player2_score, player2_upperscore);

        printf("Press enter to continue...");
        while (getchar() != '\n');
        getchar();
        change_player(&current_player);
    }




if (player1_score > player2_score){
    printf("Player 1 wins!");
}

if (player1_score < player2_score){
    printf("Player 2 wins!");
}

if (player1_score == player2_score){
    printf("Its a tie!");
}
    }

   

    



int choose_combinations(int player_combinations[13]){
    int comb_chosen = 0;

    char *combs[13] = {
        "Sum of all 1s",
        "Sum of all 2s",
        "Sum of all 3s",
        "Sum of all 4s",
        "Sum of all 5s",
        "Sum of all 6's (End up Upper Section)",
        "Three of a Kind (Start of Lower Section)",
        "Four of a kind",
        "Full House",
        "Small straight",
        "Large straight",
        "Yahtzee!",
        "Chance"
    };

    printf("Available game combinations are below");
    for (int i=0; i <13; i++){
        if (player_combinations[i] == 1)
            printf("\n%d. %s\n", i+1, combs[i]);
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
        if (counter[i] >= num_dice){
            return i;
        }
    }
        
    return 0;
}


int three_of_a_kind(int dice[], int *score, int player_combinations[13]){
    if (player_combinations[6] == 1){
        int checker = of_a_kind_checker(dice, 3);
        if (checker != 0)
            *score += sum_dice(dice);
            player_combinations[6] = 0;
        }
    return *score;
}


int four_of_a_kind(int dice[], int *score, int player_combinations[13]){
    if (player_combinations[7] == 1){
    int checker = of_a_kind_checker(dice, 4);
    if (checker == 1)
        *score += sum_dice(dice);
        player_combinations[7] = 0;
    }
    return *score;
}


int sum_of_num(int dice[], int *score, int num_to_sum, int player_combinations[13]){
    int sum = 0;
    for (int i = 0; i < 5; i++){
        if (dice[i] == num_to_sum){
            sum += dice[i];
        }
    }
    *score += sum;
    player_combinations[num_to_sum - 1] = 0;
    return sum; //change to score if doesnt work
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

for(int i = 0; i<5; i++){
    counter[dice[i]]++;
}

for (int i = 1; i<= 3; i++){
    if (counter[i] > 0 && counter[i+1] > 0 && counter [i+2]> 0 && counter [i+3] > 0){
        *score += 30;
        break;
    }
}
player_combinations[9] = 0;
return *score;
}


int large_straight (int dice[], int *score, int player_combinations[13]){
    int counter[7] = {0};
    
    for (int i = 0; i < 5; i++){
        counter[dice[i]]++;
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
        counter[dice[i]]++;
    }
    for (int i = 0; i <= 6; i++){
        if (counter[i] == 5){
            *score += 50;
            break;

        }

    }
    player_combinations[11] = 0;
    return *score;
    }



int chance (int dice[], int *score, int player_combinations[13]){
    *score += sum_dice(dice);
    player_combinations[12] = 0;
    return *score;
}



