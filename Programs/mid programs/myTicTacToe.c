#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//variables globales
char gameBoard[3][3];
char PLAYER;
char COMPUTER;

//declaro que usare a lo largo del programa, despues pienso como deberia de funcionar
void playerCharacter();
void resetBoard ();
void printBoard ();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main () {
    printf("tic tac toe");
    playerCharacter();
    char winner = ' ';
    char playAgain;

    do
    {
        winner = ' ';
        playAgain = ' ';
        
        resetBoard ();

            while (winner == ' ' && checkFreeSpaces() != 0) {
                printBoard();

                playerMove();

                winner = checkWinner();

                if (winner != ' ' || checkFreeSpaces() == 0) {
                    break;
                }

                computerMove();
                winner = checkWinner();

                if (winner != ' ' || checkFreeSpaces() == 0) {
                    break;
                }
            }

            printBoard();
            printWinner(winner);
            
            printf("Play again? y/n: ");
            scanf(" %c", &playAgain);  
            playAgain = tolower(playAgain);

    } while (playAgain == 'y');
    
    return 0;
}

void playerCharacter() {
    char input;
    printf("Choose your character: ");
    scanf(" %c", &input);
    PLAYER = input;
    
    do {
        printf("Choose character for computer (should be different from %c): ", PLAYER);
        scanf(" %c", &input);
    } while (input == PLAYER || input == ' ');

    COMPUTER = input;
}


void resetBoard () 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            gameBoard[i][j] = ' ';
         }
    }
}
void printBoard () 
{
    printf(" %c  | %c  | %c", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]); //row 0, column 0, y asi
    printf("\n----|----|---- \n");
    printf(" %c  | %c  | %c", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]); //row 0, column 0, y asi
    printf("\n----|----|---- \n");
    printf(" %c  | %c  | %c", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]); //row 0, column 0, y asi
    printf("\n");
}
int checkFreeSpaces() 
{
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if(gameBoard[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
void playerMove() 
{
    int y;
    int x;

    do {
        printf("Enter row #(1-2-3)", y, x);
        scanf("%d", &x);                    //cambiar de coso
        x--;
        printf("Enter column #(1-2-3)", y, x);
        scanf("%d", &y);                    //cambiar de coso
        y--;

        if(gameBoard[x][y] != ' ') {
            printf("Mov. Invalido");
        } else {
            gameBoard[x][y] = PLAYER;
            break;
        }
    }   while (gameBoard[x][y] != ' ');
}
void computerMove() 
{
    //Es mov random
    srand(time(0));
    int x;
    int y;

    if(checkFreeSpaces() > 0 ) 
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (gameBoard[x][y] != ' ');
        
        gameBoard[x][y] = COMPUTER;
    }   else {
        printWinner(' ');
    }
}
char checkWinner() 
{
    //vemos columnas

    for(int i = 0; i < 3; i++) {
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2] )   
        {
            return gameBoard[i][0];
        }   
    }
    //veo filas
    for(int i = 0; i < 3; i++) {
        if(gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i] )   
        {
            return gameBoard[0][i];
        }   
    }

    //ver diagonales (posibles wins)

    for(int i = 0; i < 3; i++) {
        if(gameBoard[0][i] == gameBoard[1][1] && gameBoard[0][i] == gameBoard[2][2] )   
        {
            return gameBoard[0][0];
        }   
    }

    for(int i = 0; i < 3; i++) {
        if(gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0] )   
        {
            return gameBoard[0][2];
        }   
    }

    return ' ';
}
void printWinner(char winner) 
{
    if(winner == PLAYER) {
        printf("Player wins \n");
    }   else if (winner == COMPUTER) {
        printf("Computer wins \n");
    }   else {
        printf(" Draw \n");
    }
}