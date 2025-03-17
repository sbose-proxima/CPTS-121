#include "headers.h"

int main(void){
    srand(time(NULL));
    


    int game_menu = 0;

    printf("Welcome to Yahtzee!\n");
    printf("1. Display Rules\n");
    printf("2. Play the game\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &game_menu);


    if (game_menu == 1){
        print_rules();
        int y_n = 0;
        printf("\nIf you would like to start the game, please press 1 for yes and 2 for no\n");
        scanf("%d", &y_n);
        if(y_n == 1){
            printf("Press enter to continue...");
            while (getchar() != '\n');
            getchar();
            start_game();
        }
        else{
            printf("Exiting!");
        }

        //system("pause");
    }

    else if (game_menu == 2){
        start_game();
        printf("Press enter to continue...");
        while (getchar() != '\n');
        getchar();
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
