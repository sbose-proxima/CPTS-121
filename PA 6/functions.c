#include "headers.h"


#define BOARD_SIZE 10


int carrierCells1[5][2]; //change guessed cells to -1, so if all are hits, then ship is sunk
int carrierCells2[5][2];

char player1board[BOARD_SIZE][BOARD_SIZE];
char player2board [BOARD_SIZE][BOARD_SIZE];

Stats player1_stats = {0, 0, 0, 0.0};
Stats player2_stats = {0, 0, 0, 0.0};
int current_player = 0;

void welcome_screen(){
    printf("Welcome to Battleship!\n");
    printf("Below are the rules of battleship\n");
    printf("__________________________________\n");
    printf("The players will palce 5 ships on their board. They can choose to do it manually, or have the computer do it for them\n");
    printf("Each player will guess a coordinate on the opposing players board with the sole purpose of sinking their ships\n");
    printf("The program will notify you whether it is a hit, miss, or if a ship has fully sunk\n");
    printf("The objective of the game is to sink all 5 of your opponent's ships. The first to do this wins the game\n");
    printf("\n");
    

}


void initialize_game_board(){
        for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j< BOARD_SIZE; j++){
            player1board[i][j] = '-';
            player2board[i][j] = '-';
        }
    }
} 

void display_board(char board[BOARD_SIZE][BOARD_SIZE]){
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++){
            printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++){
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++){
            printf(" %c", board[i][j]);
        }
    printf("\n");
    }
  }







void change_player(int *current_player){
    
    if (*current_player == 1)
        *current_player = 2;
    else
        *current_player = 1;
}


int select_who_starts_first(){
    return rand() %2 + 1;

}

void log_stats(){
    FILE *infile = fopen("./Battleship.log", "a");
    fprintf(infile, "Player 1 stats: \nHits: %d\nMisses: %d\nTotal Shots:%d\nHit/Miss Ratio: %.2f\nTotal Sunk: %d\n\n",
    player1_stats.total_hits, player1_stats.total_misses, player1_stats.total_shots, player1_stats.hit_miss_ratio, player1_stats.sunk);

    fprintf(infile, "Player 2 stats:\nHits: %d\nMisses: %d\nTotal Shots:%d\nHit/Miss Ratio: %.2f\nTotal Sunk: %d\n ", 
    player2_stats.total_hits, player2_stats.total_misses, player2_stats.total_shots, player2_stats.hit_miss_ratio, player2_stats.sunk);

    
    fclose(infile);
}

void update_stats(int hit, int sunk, int miss, int current_player){
    Stats *stats;

    if (current_player == 1){
        stats = &player1_stats;
    }

    else if (current_player == 2){
        stats = &player2_stats;
    }

    if (hit){
        stats->total_hits++;
    } 

    if (miss){
        stats->total_misses++;
    }

    if(sunk){
        stats->sunk++;
    }



    stats-> total_shots = stats->total_hits+stats->total_misses;

    if (stats->total_shots > 0){
        stats->hit_miss_ratio = (float)stats->total_hits/stats->total_misses;
    } else{
        stats->hit_miss_ratio = (float)stats->total_hits;
    }

}

int is_ship_sunk(char board[BOARD_SIZE][BOARD_SIZE], char ship_symbol){
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if (board[i][j] == ship_symbol){
                return 0;
            }
        }
    }
    return 1;
}

void check_hit (int x, int y, int current_player){
    char (*opponent_board)[10];
    int hit = 0;
    int sunk = 0;
    int miss = 0;

    if (current_player == 1){
        opponent_board = player2board;
    }
    else{
        opponent_board = player1board;
    }


    if (opponent_board[y][x] != '-' && opponent_board[y][x] != '*'){
        printf("Hit! Coordinates: (%d, %d)!\n", x,y);
        char ship_sym = opponent_board[y][x];
        if (current_player == 1){
        player1board[y][x] = '*';
        opponent_board[y][x] = '*';
        }
        hit = 1;

        if (is_ship_sunk(opponent_board, ship_sym)){
            printf("Ship %c has sunk!\n", ship_sym);
            sunk = 1;
        }

}

else {
    printf("Miss! Coordinates: (%d %d)!\n", x, y);
    miss = 1;
    if (current_player == 1){
        player1board[y][x] = 'm';
    }
}
update_stats(hit, sunk, miss, current_player);
}


void player_turn(){
    int x,y;
    int valid_guess = 0;

    while(!valid_guess){
        printf("Player 1, enter two numbers as your coordinates to guess, separated by spaces ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE){
            printf("Invalid Coordinates! Please try again. \n");
            continue;
        }

        if (player2board[y][x] == 'm' || player2board[y][x] == '*'){
            printf("You already guess this spot! Try again!");
        } else{
           check_hit(x,y,1);
           valid_guess = 1;
        }
  }
    
}


void computer_turn(){
    int x, y;
    x = rand() % BOARD_SIZE;
    y = rand() % BOARD_SIZE;

    while (player1board[y][x] == 'm' || player1board[y][x] == '*'){
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;
    }

    printf("Computer is guessing coordinates (%d, %d)...", x, y);
    check_hit(x,y,2);


    if (player1board[y][x] == '*'){
        printf("Computer hit a ship!\n");
    } else{
        printf("Computer missed!\n");
    }
}




void startgame(){
    initialize_game_board();
    current_player = select_who_starts_first();
    printf("Player %d goes first", current_player);

    int choice = 0;


    printf("Player 1, please type 1 if you would like to manually place your ships, and type 2 if you would like to automatically place your ships! ");
        scanf("%d", &choice);

    if (choice == 1){
            manually_place_ships2(&current_player);
        } else{
            automatically_place_ships3(&current_player);
        }

    change_player(&current_player);
    automatically_place_ships3(&current_player);

    while (!all_ships_sunk(player1board) && !all_ships_sunk(player2board)){
       
        system("pause"); // only works on windows

        printf("Player 1's Board:\n");
        display_board(player1board);
    

    if (current_player == 1){
        player_turn();
        if (all_ships_sunk(player2board)){
            printf("Player 1 wins!");
            break;
        }
    } else{
        computer_turn();
        if (all_ships_sunk(player1board)){
            printf("Computer wins!\n");
            break;
        }
    }
    change_player(&current_player); 
}
log_stats();
}



int all_ships_sunk (char board[BOARD_SIZE][BOARD_SIZE]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (board[i][j] != '-' && board[i][j] != '*' && board[i][j] != '0'){
                return 0;
            }
        }
    }
    return 1;
}

void automatically_place_ships3(int *current_player){
    int ship_sizes[5] = {5, 4, 3, 3, 2};
    char ship_symbols[5] = {'c', 'b', 'r', 's', 'd'};
    char (*playerboard)[BOARD_SIZE];

    if (*current_player == 1){
        playerboard = player1board;
    } else{
        playerboard = player2board;
    }

    for (int ship = 0; ship < 5; ship++){
        int size = ship_sizes[ship];
        char symbol = ship_symbols[ship];
        int placed = 0;

        while (!placed){
            int direction = rand() % 2;
            int x = rand() % BOARD_SIZE;
            int y = rand() % BOARD_SIZE;
            int can_place = 1;


            if (direction == 0) {// horizontal
                if (x + size <= BOARD_SIZE){
                    for (int i = 0; i < size; i++){
                        if (playerboard[y][x+i] != '-'){
                            can_place = 0;
                            break;
                        }
                    }

                    if (can_place){
                        for (int i = 0; i < size; i++){
                            playerboard[y][x+i] = symbol;
                        }
                        placed = 1;
                    }
                }
            } else {
                if (y + size <= BOARD_SIZE){
                    for (int i = 0; i < size; i++){
                        if (playerboard[y+i][x] != '-'){
                            can_place = 0;
                            break;
                        }
                    }

                    if (can_place){
                        for (int i = 0; i < size; i++){
                            playerboard[y+i][x] = symbol;
                        }
                        placed = 1;
                    }
                }
            }
        }
    }
}






void manually_place_ships2(int *current_player){
    char hor_ver;
    int coords_x, coords_y;


    int ship_sizes[5] = {5, 4, 3, 3, 2,};
    char ship_symbols[5] = {'c', 'b', 'r', 's', 'd'};
    char *ship_names[5] = {"carrier", "battleship", "cruiser", "submarine", "destroyer"};

    for (int shipnum = 0; shipnum < 5; shipnum++){
        int valid = 0;
        display_board(player1board);
        
        while (!valid){
            printf("Do you want to place your %s horizontally or vertically? Type H for horizontally and V for vertically", ship_names[shipnum]);
            scanf(" %c", &hor_ver);

            printf("Enter the leftmost x and topmost y coordinate, separated by spaces: ");
            scanf("%d %d", &coords_x, &coords_y);

            if ((hor_ver == 'H' || hor_ver == 'h') && coords_x + ship_sizes[shipnum] > BOARD_SIZE){
                printf("Ship goes out of bound horizontally. Try again");
                continue;
            }

            if ((hor_ver == 'V' || hor_ver == 'v') && coords_y + ship_sizes[shipnum] > BOARD_SIZE){
                printf("Ship goes out of bound vertically. Try again");
                continue;
            }
            

            int overlap = 0;
            for (int i = 0; i < ship_sizes[shipnum]; i++){
                int x, y;


                if (hor_ver == 'H' || hor_ver == 'h'){
                    x = coords_x + i;
                    y = coords_y;
                } else{
                    x = coords_x;
                    y = coords_y + i;
                }

                if (*current_player == 1){
                    if(player1board[y][x] != '-'){
                        overlap = 1;
                        break;
                    }
              }  else{
                if (player2board[y][x] != '-'){
                    overlap = 1;
                    break;
                }
        }
     }

    if (overlap){
        printf("There is already a ship in that location. Try again\n");
        continue;
    }

    for (int i = 0; i < ship_sizes[shipnum]; i++){
        int x, y;

        if (hor_ver == 'H' || hor_ver == 'h'){
                    x = coords_x + i;
                    y = coords_y;
         } else{
             x = coords_x;
             y = coords_y + i;
        }

    if (*current_player == 1){
        player1board[y][x] = ship_symbols[shipnum];
    } else{
        player2board[y][x] = ship_symbols[shipnum];
    }
        
    }

    valid = 1;
    
 }



    }
    
 }
