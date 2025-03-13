#include "headers.h"

int main(void){
    srand(time(NULL));
    


    int game_menu = 0;

    printf("Welcome to Yahtzee!");
    printf("1. Display Rules\n");
    printf("2. PLay the game\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &game_menu);


    if (game_menu == 1){
        print_rules();
        system("pause");
    }

    else if (game_menu == 2){
        start_game();
        system("pause");
    }

    else if(game_menu == 3){
        printf("Exiting!");
        return 0;
    }

    else{
        printf("Not a choice! Please restart");
    }


    return 0;
    }
