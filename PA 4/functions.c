#include "functions.h"

/*
Function Name: print_rules

Programmer: Svanik Bose

Date Created: 02/15/2025
Date Last Modified: 02/17/2025

Description: Prints the rules of craps game

Input Parameters: none, void

Preconditions: program must be running
Postconditions: prints the rules of the game


*/



void print_rules(void){
    printf("The rules of craps are listed below:\n");
    printf("1. A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.\n");
    printf("2. After the dice have come to rest, the sum of the spots on the two upward faces is calculate\n");
    printf("3. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (\"craps\"), the player loses.\n");
    printf("4. If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, the sum becomes the players \"point.\"\n");
	printf("5. To win, you must continue rolling the dice until you \"make your point.\" The player loses by rolling a 7 before making the point.\n\n");


}


/*
Function Name: get_bank_balance

Programmer: Svanik Bose

Date Created: 02/15/2025
Date Last Modified: 02/15/2025

Description: Gets the bank balance of the user

Input Parameters: none, void

Preconditions: Must be a floating point integer
Postconditions: returns the bank balance of the user


*/


double get_bank_balance(){
    double bank_balance = 0.0;
    printf("Enter your bank balance: ");
    scanf("%lf", &bank_balance);

    return bank_balance;

}

/*
Function Name: get_wager_amount

Programmer: Svanik Bose

Date Created: 02/15/2025
Date Last Modified: 02/15/2025

Description: gets the wager amount that the user wants to bet

Input Parameters: none, void

Preconditions: number must be a floating point number
Postconditions: returns the wager amount which the user wants to bet


*/



double get_wager_amount(){
    double wager = 0.0;
    printf("Enter the wager amount you want on this roll: ");
    scanf("%lf", &wager);

    return wager;

}

/*
Function Name: check_wager_amount

Programmer: Svanik Bose

Date Created: 02/15/2025
Date Last Modified: 02/16/2025

Description: checks if the wager amount the user wants to bet is valid in comparison to their bank balance

Input Parameters: wager, balance

Preconditions: wager and bank balance must be valid numbers
Postconditions: returns a checker integer which checks if the wager amount is valid


*/


int check_wager_amount(double wager, double balance){
    int checker = 1;

    if (wager > balance){
        printf("You cannot bet a wager higher than your bank balance!\n");
        checker = 0;
    }

    return checker;

    

}


/*
Function Name: rollDie

Programmer: Svanik Bose

Date Created: 02/16/2025
Date Last Modified: 02/19/2025

Description: rolls two dice by producing random integers

Input Parameters: none, void

Preconditions: srand() must be working, time conditions must be valid
Postconditions: returns the sum of the two random integers produced, simulating the sum of two rolled dice. 


*/


int rollDie(void){
    char roll_var = '\0';
    int value1 = 0, value2 = 0, sum_values = 0;
    printf("Type 'r' to roll the two dice, the sum will then be displayed: ");
    scanf(" %c", &roll_var);

    if (roll_var == 'r'){

        value1 = rand() % 6 + 1;
        value2 = rand() % 6 + 1;
        sum_values = value1+value2;
        printf("You rolled: %d ",sum_values);

        }

    return value1 + value2;
}


/*
Function Name: is_win_loss_or_point

Programmer: Svanik Bose

Date Created: 02/17/2025
Date Last Modified: 02/18/2025

Description: checks if the user has won, loss, or a stored point

Input Parameters: sum_dice

Preconditions: sum_dice must be valid, wager amount must be valid
Postconditions: returns an integer based on winning, losing, or storing a point


*/


int is_win_loss_or_point (int sum_dice){

    if (sum_dice == 7 || sum_dice == 11){
        printf(" Great job! You won!");
        return 1;
    }

    
    else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12){
        printf(" Oops! You lost your wager amount :( ");
        return 0;
    }

    else   
        return -1;


}

/*
Function Name: is_point_loss_or_neither

Programmer: Svanik Bose

Date Created: 02/17/2025
Date Last Modified: 02/19/2025

Description: checks if after the user has a point value, if the next dice rolls are the same, or if the user has lost. 

Input Parameters: sum_dice, point_value

Preconditions: the user must have not won or lost
Postconditions: returns an integer to check if the person has rolled the dice after point value, or simply lost


*/



int is_point_loss_or_neither (int sum_dice, int point_value){

    if(sum_dice == point_value)
        return 1;
    if (sum_dice == 7){
        printf(" Oh no! You lost your wager amount!  ");
        return 0;
    }
    else
        return -1;

}

/*
Function Name: adjust_bank_balance

Programmer: Svanik Bose

Date Created: 02/18/2025
Date Last Modified: 02/19/2025

Description: adjusts the total bank balance depending on the result of the game

Input Parameters: bank_balance, wager_amount, add_or_subtract

Preconditions: user must have played a part of the game
Postconditions: returns the new bank balance after the player has lsot or won. 


*/



double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract){

    if (add_or_subtract == 1)
        bank_balance += wager_amount;
    
    else if (add_or_subtract == 0)
        bank_balance -= wager_amount;

    return bank_balance;


}


/*
Function Name: chatter

Programmer: Svanik Bose

Date Created: 02/19/2025
Date Last Modified: 02/19/2025

Description: displays random chatter messages depending on the game condition

Input Parameters: none

Preconditions: varying preconditions depending on the game
Postconditions: displays random chatter messages based on what has happened in the game. 


*/



void chatter (int win_loss_check, double bank_balance, double wager_amount){

    int chatter_on = 0;
    
    if (chatter_on == 1) 
        return;


    if (wager_amount == bank_balance)
        printf("Are you sure you want to gamble your life savings away?\n");

    else if (wager_amount < (0.5)*bank_balance)
        printf("You have so much money! Bet more next time!\n");
    
    else if (wager_amount > (0.8)*bank_balance)
        printf("You dont have unlimited money! Bet less next time! \n");

    chatter_on = 1;

        }
    


