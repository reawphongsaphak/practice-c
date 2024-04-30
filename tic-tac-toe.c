#include <stdio.h>

#define max(a,b) (((a)>(b)) ? (a):(b))
#define min(a,b) (((a)>(b)) ? (b):(a))

int game = 1;

//! board[y][x]
char board[3][3] = { {'-','-','-'}
                    ,{'-','-','-'}
                    ,{'-','-','-'}};


void show(char ls[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%c\t",ls[i][j]);
        }
        printf("\n");
    }
}

//* check win condition
int check_win(int board[3][3]){

    //* check all win condition
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] != '-' || board[0][2] == board[1][1] && board[0][2] == board[3][0] && board[1][1] != '-' || board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != '-' || board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != '-' || board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != '-' || board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != '-' || board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != '-' || board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != '-'){
        game = 0;
    }

}

int minimax(){

}

int gameplay(){

}


void rules(){
    printf("Welcome to tic-tac-toe\n\n");
    printf("Tic-Tac-Toe Rules:\n");
    printf("1. The game is played on a grid that's 3 squares by 3 squares.\n");
    printf("2. You are X , your friend (or the computer in this case) is O . Players take turns putting their marks in empty squares.\n");
    printf("3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n");
    printf("4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n\n");
    printf("--= Game start =--\n");
}

int main(){
    rules();
    show(board);
    return 0;
}
