// OLD HARDCODED FUNCTION FOR RECORD KEEPING (DO NOT USE)
void manually_place_ships(int *current_player){
    // int placed = 0;
    int shipnum = 1;
    char hor_ver;

if(shipnum == 1){
    printf("Do you want to place your battleship horizontally or vertically? V for vertical, H for horizontal");
    scanf(" %c", &hor_ver);
    if (hor_ver == 'H'){
        int coords_x;
        int coords_y;
        printf("Enter x left-most x coordinate \n");
        scanf("%d %d", &coords_x, &coords_y);

        for (int i = coords_x; i < coords_x + 4; i++){ // check coords_x + 3 on PA doc
            if (*current_player == 1){
                player1board[coords_y][i] = 'b';
            }

            if (*current_player == 2){
                player2board[coords_y][i] = 'b';
            }
        }
    }

    if (hor_ver == 'V'){
        int coords_x;
        int coords_y;
        printf("Enter x left-most x coordinate \n");
        scanf("%d %d", &coords_x, &coords_y);

        for (int i = coords_y; i < coords_y + 4; i++){
            if (*current_player == 1){
                player1board[i][coords_x] = 'b';
            }

            if (*current_player == 2){
                player2board[i][coords_x] = 'b';
            }
        }
    }


    shipnum++;
}

if (shipnum == 2){
    printf("Do you want to place your carrier horizontally or vertically? V for vertical, H for horizontal");
    scanf(" %c", &hor_ver);
    if (hor_ver == 'H'){
        int coords_x;
        int coords_y;
        printf("Enter x left-most x coordinate \n");
        scanf("%d %d", &coords_x, &coords_y);
        for (int i = coords_x; i < coords_x + 5; i++){
            if (*current_player == 1){
                player1board[coords_y][i] = 'c';
            }

            if (*current_player == 2){
                player2board[coords_y][i] = 'c';
            }

        }
    }

    if (hor_ver == 'V'){
        int coords_x;
        int coords_y;
        printf("Enter x left-most x coordinate \n");
        scanf("%d %d", &coords_x, &coords_y);
        for (int i = coords_y; i < coords_y + 5; i++){
            if (*current_player == 1){
                player1board[i][coords_x] = "c";
            }

            if (*current_player == 2){
                player2board[i][coords_x] = "c";
            }
        }

    }
    shipnum++;
}

if (shipnum == 3){
    
    printf("Do you want to place your submarine horizontally or vertically? V for vertical, H for horizontal");
    scanf(" %c", &hor_ver);
    if (hor_ver == 'H'){
        int coords_x;
        int coords_y;
        printf("Enter x left-most x coordinate \n");
        scanf("%d %d", &coords_x, &coords_y);
        for (int i = coords_x; i < coords_x + 3; i++){
            if (*current_player == 1){
                player1board[coords_y][i] = 's';
            }

            if (*current_player == 2){
                player2board[coords_y][i] = 's';
            }

        }
    }

    if (hor_ver == 'V'){
        int coords_x;
        int coords_y;
        printf("Enter x left-most x coordinate \n");
        scanf("%d %d", &coords_x, &coords_y);
        for (int i = coords_y; i < coords_y + 3; i++){
            if (*current_player == 1){
                player1board[i][coords_x] = 's';
            }

            if (*current_player == 2){
                player2board[i][coords_x] = 's';
            }
        }

    }
    shipnum++;
}

if (shipnum == 4){
    printf("Do you want to place your destroyer horizontally or vertically? V for vertical, H for horizontal");
    scanf(" %c", &hor_ver);
    if (hor_ver == 'H'){
        int coords_x;
        int coords_y;
        printf("Enter x left-most x coordinate \n");
        scanf("%d %d", &coords_x, &coords_y);
        for (int i = coords_x; i < coords_x + 2; i++){
            if (*current_player == 1){
                player1board[coords_y][i] = 'd';
            }

            if (*current_player == 2){
                player2board[coords_y][i] = 'd';
            }

        }
    }

    if (hor_ver == 'V'){
        int coords_x;
        int coords_y;
        printf("Enter x left-most x coordinate \n");
        scanf("%d %d", &coords_x, &coords_y);
        for (int i = coords_y; i < coords_y + 2; i++){
            if (*current_player == 1){
                player1board[i][coords_x] = 'd';
            }

            if (*current_player == 2){
                player2board[i][coords_x] = 'd';
            }
        }

    }
    shipnum++;
}

if(shipnum == 5){
    printf("Do you want to place your cruiser horizontally or vertically? V for vertical, H for horizontal");
    scanf(" %c", &hor_ver);
    if (hor_ver == 'H'){
        int coords_x;
        int coords_y;
        printf("Enter x left-most x coordinate \n");
        scanf("%d %d", &coords_x, &coords_y);
        for (int i = coords_x; i < coords_x + 3; i++){
            if (*current_player == 1){
                player1board[coords_y][i] = 'r';
            }

            if (*current_player == 2){
                player2board[coords_y][i] = 'r';
            }

        }
    }

    if (hor_ver == 'V'){
        int coords_x;
        int coords_y;
        printf("Enter x left-most x coordinate \n");
        scanf("%d %d", &coords_x, &coords_y);
        for (int i = coords_y; i < coords_y + 3; i++){
            if (*current_player == 1){
                player1board[i][coords_x] = 'r';
            }

            if (*current_player == 2){
                player2board[i][coords_x] = 'r';
            }
        }

    }
    int placed = 1;
}

}
