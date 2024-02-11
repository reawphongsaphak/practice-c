#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// board[y][x]
int turn = 1;
int x;
int y;
int f1_x = 1;
int f1_y = 1;
int array[2];
int board[5][5];
int game = 1;
int f1_bonus;
int f2_val = 1;

char piece = 'X';
char dir;
char P_move[3];
char check_piece;
char U = 'u';
char D = 'd';
char R = 'r';
char L = 'l';
char sp = ' ';
char f1_char = '+';


void setBoard() 
{
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            // set row 1
            if (i == 0 && (j%2 == 0)  || i == 4 && (j%2 == 1)) 
            {
                board[i][j] = 'O';
            }

            // set row 5
            else if (i == 0 && (j%2 == 1)  || i == 4 && (j%2 == 0))
            {
                board[i][j] = 'X';
            }

            // set row 3
            else if (i == 2 && j == 0)
            {
                board[i][j] = 'X';
            }
            else if (i == 2 && j == 4)
            {
                board[i][j] = 'O';
            }

            else{
                board[i][j] = ' ';
            }
        }
    }
    // if want to random
    // f1_x = (rand() % 3)+1;
    // f1_y = (rand() % 3)+1;
    board[f1_y][f1_x] = '+';
    board[3][3] = '+';
    
}


void show() {
    printf("  1   2   3   4   5  \n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("| %c | %c | %c | %c | %c |   %d\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], i + 1);
        printf("---------------------\n");
    }
}


void split(char input[])
{
    int i=0;
    // Returns first token 
    char *token = strtok(input, " ");
   
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        // printf("%s\n", token);
        array[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }
    // printf("\n");
    // for (int i = 0; i < 2; i++){
        // printf("%d\n", array[i]);
    // }
}

int main()
{
    setBoard();
    show();
    goto p1;

// player 1 turn
p1:
    printf("P1 please enter what piece you  want to move :");
    scanf(" %[^\n]*c\n",P_move);  
    // printf("%s\n",P_move);
    split(P_move);

    printf("P1 please enter what direction you  want to move(u, d ,r ,l) :");
    scanf(" %c",&dir);

    goto check_move;

//  player 2 turn
p2:
    printf("P2 please enter what piece you want to move :");
    scanf(" %[^\n]*c\n",P_move);  
    // printf("%s\n",P_move);
    split(P_move);

    printf("P2 please enter what direction you  want to move(u, d ,r ,l) :");
    scanf(" %c",&dir);   

// check if its can move
check_move:
    x = array[0]-1;
    y = array[1]-1;

    if (turn%2==1){
        check_piece = 'X';
    }
    else if (turn %2 == 0){
        check_piece = 'O';
    }


    if (check_piece == board[y][x]){
        if (U == dir){
            goto up;
        }
        if (D == dir){
            goto down;
        }
        if (L == dir){
            goto left;
        }
        if (R == dir){
            goto right;
        }
    }


    else{
        printf("\nplese select another piece or direction !!!\n\n");
        if (turn%2==1){
            goto p1;
        }
        else if (turn %2 == 0){
            goto p2;
        }
    }

// move to up direction
up:
    x = array[0]-1;
    y = array[1]-1;

    if (y-1 >= 0 && board[y-1][x] == f1_char){
        goto f1;
    }
    if (turn%2==1 && y-1 >= 0 && board[y-1][x] == sp){
        board[y][x] = ' ';
        board[y-1][x] = 'X';
        if (f2_val == 0){
            board[y][x] = 'X';
            board[y-1][x] = ' ';
            goto else_move;
        }
        show();
        goto check_row;
    }
    else if (turn%2==0 && y-1 >= 0 && board[y-1][x] == sp){
        board[y][x] = ' ';
        board[y-1][x] = 'O';
        if (f2_val == 0){
            board[y][x] = 'X';
            board[y-1][x] = ' ';
            goto else_move;
        }
        show();
        goto check_row;
    }
    else{
        goto else_move;
    }

// move to down direction
down:
    x = array[0]-1;
    y = array[1]-1;

    if (y+1 < 5 && board[y+1][x] == f1_char){
        goto f1;
    }
    if (turn%2==1 && y+1 < 5 && board[y+1][x] == sp){
        board[y][x] = ' ';
        board[y+1][x] = 'X';
        if (f2_val == 0){
            board[y][x] = 'X';
            board[y+1][x] = ' ';
            goto else_move;
        }
        show();
        goto check_row;
    }
    else if (turn%2==0 && y+1 < 5 && board[y+1][x] == sp){
        board[y][x] = ' ';
        board[y+1][x] = 'O';
        if (f2_val == 0){
            board[y][x] = 'O';
            board[y+1][x] = ' ';
            goto else_move;
        }
        show();
        goto check_row;
    }
    else{
        goto else_move; 
    }


// move to right 
right:
    x = array[0]-1;
    y = array[1]-1;

    if (x+1 < 5 && board[y][x+1] == f1_char){
        goto f1;
    }
    if (turn%2==1 && x+1 < 5 && board[y][x+1] == sp){
        board[y][x] = ' ';
        board[y][x+1] = 'X';
        if (f2_val == 0){
            board[y][x] = 'X';
            board[y][x+1] = ' ';
            goto else_move;
        }
        show();
        goto check_row;
    }
    else if (turn%2==0 && x+1 < 5 && board[y][x+1] == sp){
        board[y][x] = ' ';
        board[y][x+1] = 'O';
        if (f2_val == 0){
            board[y][x] = 'O';
            board[y][x+1] = ' ';
            goto else_move;
        }
        show();
        goto check_row;
    }
    else{
        goto else_move;
    }


// move to left
left:
    x = array[0]-1;
    y = array[1]-1;

    if (x-1 >= 0 && board[y][x-1] == f1_char){
        goto f1;
    }
    if (turn%2==1 && x-1 >= 0 && board[y][x-1] == sp){
        board[y][x] = ' ';
        board[y][x-1] = 'X';
        if (f2_val == 0){
            board[y][x] = 'X';
            board[y][x-1] = ' ';  
            goto else_move;
        }
        show();
        goto check_row;
    }
    else if (turn%2==0 && x-1 >= 0 && board[y][x-1] == sp){
        board[y][x] = ' ';
        board[y][x-1] = 'O';
        if (f2_val == 0){
            board[y][x] = 'O';
            board[y][x-1] = ' ';  
            goto else_move;
        }
        show();
        goto check_row;
    }
    else{
        goto else_move;
    }



else_move:
    printf("\nplese select another piece or direction !!!\n\n");
    if (turn%2==1){
        goto p1;
    }
    else if (turn %2 == 0){
        goto p2;
    }


check_row:
    // check in same rows
    // printf("check row\n");
    for (int i=0; i<5; i++)
    {
       if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] || board[i][1] == board[i][2] && board[i][1] == board[i][3] && board[i][1] == board[i][4]){
            goto win;
        }
        else{
            goto check_col;
        }
    }


check_col:
    // printf("check col\n");
    for (int i=0; i<5; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] &&board[0][i] == board[3][i] && board[0][i] != sp || board[1][i] == board[2][i] && board[1][i] == board[3][i] && board[1][i] == board[4][i] && board[1][i] != sp ){
            goto win;
        }
        else{
            goto check_dia_r;
        }
    }
check_dia_r:
    // printf("check dia_r\n");
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && board[0][0] != sp) || (board[1][1] == board[2][2] && board[1][1] == board[3][3] && board[1][1] == board[4][4] && board[1][1] != sp) || (board[1][0] == board[2][1] && board[1][0] == board[3][2] && board[1][0] == board[4][3] && board[1][0] != sp) || (board[0][1] == board[1][2] && board[0][1] == board[2][3] && board[0][1] == board[3][4] && board[0][1] != sp)){
        goto win;
    }
    else{
        goto check_dia_l;
    }

check_dia_l:
    // printf("check dia_l\n");
    if (board[0][4] == board[1][3] && board[0][4] == board[2][2] && board[0][4] == board[3][1] && board[0][4] != sp || board[1][3] == board[2][2] && board[1][3] == board[3][1] && board[1][3] == board[4][0] && board[1][3] != sp || board[0][3] == board[1][2] && board[0][3] == board[2][1] && board[0][3] == board[3][0] && board[0][3] != sp || board[1][4] == board[2][3] && board[1][4] == board[3][2] && board[1][4] == board[4][1] && board[1][4] != sp){
        goto win;
    }

    goto f2;


f1:
    x = array[0]-1;
    y = array[1]-1;

    if (U == dir){
        if (turn%2==1 && y-1 >= 0){
            board[y][x] = ' ';
            board[y-1][x] = 'X';
            y -= 1;
            show();
        }
        else if (turn%2==0 && y-1 >= 0){
            board[y][x] = ' ';
            board[y-1][x] = 'O';
            y -= 1;
            show();
        }
    }
    else if (D == dir){
        if (turn%2==1 && y+1 < 5){
            board[y][x] = ' ';
            board[y+1][x] = 'X';
            y += 1;
            show();
        }
        else if (turn%2==0 && y+1 < 5){
            board[y][x] = ' ';
            board[y+1][x] = 'O';
            y += 1;
            show();
        }
    }
    else if (L == dir){
        if (turn%2==1 && x-1 >= 0){
            board[y][x] = ' ';
            board[y][x-1] = 'X';
            x -= 1;
            show();
        }
        else if (turn%2==0 && x-1 >= 0){
            board[y][x] = ' ';
            board[y][x-1] = 'O';
            x -= 1;
            show();
        }
    }
    else if (R == dir){
        if (turn%2==1 && x+1 < 5){
            board[y][x] = ' ';
            board[y][x+1] = 'X';
            x += 1;
            show();
        }
        else if (turn%2==0 && x+1 < 5){
            board[y][x] = ' ';
            board[y][x+1] = 'O';
            x += 1;
            show();
        }
    }

    printf("\nyou get a bonus !!!\n\n");
    printf("select column you want to move in the same row :");
    scanf("%d",&f1_bonus);
    board[y][x] = ' ';
    board[y][f1_bonus-1] = 'X';
    show();
    goto check_row;

f2:

    for (int i = 1; i<4; i++){
        for (int j = 1; j<4; j++){
            if (board[i][j] == board[i][j+1] && board[i][j] == board[i][j-1] && board[i][j] == board[i-1][j] && board[i][j] == board[i+1][j] && board[i][j] != sp){
                turn++;
                goto win;
            }
        }
    }
    {
        turn++;
        if (turn%2==1){
            goto p1;
        }
        else if (turn %2 == 0){
            goto p2;
        }
    }

win:
    if (turn%2==1){
        printf("＼(＾O＾)／  -- Winner is P1 --   ＼(＾O＾)／\n");
    }
    else if (turn %2 == 0){
        printf("＼(＾O＾)／ -- Winner is P2 -- ＼(＾O＾)／\n");
    }
    return 0;
}
