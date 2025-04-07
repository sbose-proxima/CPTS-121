#include "headers.h"


#define BOARD_SIZE 10




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
    FILE *infile = fopen("./Battleship.log", "r");
    fprintf(infile, "Player 1 stats: \nHits: %d\nMisses: %d\nTotal Shots:%d\nHit/Miss Ratio: %.2f\n\n",
    player1_stats.total_hits, player1_stats.total_misses, player1_stats.total_shots, player1_stats.hit_miss_ratio);

    fprintf(infile, "Player 2 stats:\nHits: %d\nMisses: %d\nTotal Shots:%d\nHit/Miss Ratio: %.2f\n\n ", 
    player2_stats.total_hits, player2_stats.total_misses, player2_stats.total_shots, player2_stats.hit_miss_ratio);

    fclose(infile);
}

void update_stats(int hit, int current_player){
    Stats *stats;

    if (current_player == 1){
        stats = &player1_stats;
    }

    if (current_player == 2){
        stats = &player2_stats;
    }

    if (hit){
        stats->total_hits++;
    } else{
        stats->total_misses++;
    }

    stats-> total_shots = stats->total_hits+stats->total_misses;

    if (stats->total_shots > 0){
        stats->hit_miss_ratio = (float)stats->total_hits/stats->total_misses;
    } else{
        stats->hit_miss_ratio = 0.0;
    }

}



void check_hit (int x, int y, int current_player){
    char (*opponent_board)[10];
    int hit = 0;

    if (current_player == 1){
        opponent_board = player2board;
    }
    else{
        opponent_board = player1board;
    }


    if (opponent_board[y][x] != '-' && opponent_board[y][x] != '*'){
        printf("Hit! Coordinates: (%d, %d)!\n", x,y);
        char ship_sym = opponent_board[y][x];
        opponent_board[y][x] = '*';
        hit = 1;

        int sunk = 1;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (opponent_board[i][j] == ship_sym){
                    sunk = 0;
                }
            }

        }
        if (sunk){
            printf("Ship %c has sunk!", ship_sym);
                    }
    }
    else {
        printf("Miss! Coordinates: (%d, %d)!\n", x,y);
        opponent_board[y][x] = 'm';
    }
}



void startgame(){

    initialize_game_board();
    current_player = select_who_starts_first();

    for (int i = 0; i < 2; i++){
        int choice = 0;
        printf("Player %d, press 1 to manually place your ships, press 2 to automatically place your ships ", current_player);
        while (choice != 1 && choice != 2){
            scanf("%d", &choice);
        }

        if (choice == 1){
            manually_place_ships2(&current_player);
        }

        if (choice == 2){
            automatically_place_ships3(&current_player);
        }

        change_player(&current_player);
        system("clear"); // change to 'cls' for windows
        }

while (!all_ships_sunk(player1board) && !all_ships_sunk(player2board)){

    if (current_player == 1){
        int reveal = 0;
        printf("Type 1 to reveal player 1's board!");
        scanf("%d", &reveal);
        if (reveal == 1){
        display_board(player1board);
        }

    }
    if (current_player == 2){
        int reveal2 = 0;
        printf("Type 1 to reveal player 2's board!");
        scanf("%d", &reveal2);
        if (reveal2 == 1){
        display_board(player2board);
        }
    }

    int x, y;

    printf("Player %d, enter coordinates to guess, seperated by spaces: ", current_player);
    scanf("%d %d", &x, &y);

    check_hit(x,y, current_player);

    if (current_player == 1 && all_ships_sunk(player2board)){
        printf("Player 1 wins!");
    }

    if (current_player == 2 && all_ships_sunk(player1board)){
        printf("Player 2 wins!");
    }
    change_player(&current_player);
}
    log_stats();

    }




int all_ships_sunk (char board[BOARD_SIZE][BOARD_SIZE]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (board[i][j] != '-' && board[i][j] != 'X' && board[i][j] != '0'){
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




void automatically_place_ships2(int *current_player){
    int ship_sizes[5] = {5, 4, 3, 3, 2};
    char ship_symbols[5] = {'c', 'b', 'r', 's', 'd'};

    for (int ship = 0; ship < 5; ship++){
        int size = ship_sizes[ship];
        char symbol = ship_symbols[ship];
        int placed = 0;

        while (!placed){
            int hor_ver = rand() % 2;
            int coords_x = rand() % 10;
            int coords_y = rand() % 10;
            int space_clear = 1;

            if (hor_ver == 0 && coords_x + size <= 10){ // horizontal
                for (int i = 0; i < size; i++){
                    if ((*current_player == 1 && player1board[coords_y][coords_x + i] != '-') ||
                    (*current_player == 2 && player2board[coords_y][coords_x + i] != '-')){
                        space_clear = 0;
                        break;
                    } 
                }

            if (space_clear){
                for (int i = 0; i < size; i++){
                    if (*current_player == 1)
                        player1board[coords_y][coords_x + i] = symbol;

                    else 
                        player2board[coords_y][coords_x + i] = symbol;
                }
            placed = 1;

            }
            }  else if (hor_ver == 1 && coords_y + size <= 10){ // vertical
                for (int i = 0; i < size; i++){
                    if ((*current_player == 1 && player1board[coords_y+i][coords_x] != '-') ||
                    (*current_player == 2 && player2board[coords_y+i][coords_x] != '-')){
                        space_clear = 0;
                        break;
                    }
                }
            }


        if (space_clear){
                for (int i = 0; i < size; i++){
                    if (*current_player == 1){
                        player1board[coords_y + i][coords_x] = symbol;
                    }

                    else
                        player2board[coords_y + i][coords_x] = symbol;
    
                }
            placed = 1;





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
