#include <stdio.h>


// Global variables
char board[3][3];
int playerXScore = 0;
int playerOScore = 0;

// Function prototypes
void initializeBoard();          
void displayBoard();            
void playerMove(char player);    
int checkWin();                  
int checkDraw();                 
void displayScores();           
void resetBoard();            

 //Initialize the game board
void initializeBoard() {
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + count;
            count++;
        }
    }
}

// Owais: Display the game board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

//  Handle player move
void playerMove(char player) {
    int choice, validMove = 0;
    while (!validMove) {
        printf("Player %c, enter a number (1-9): ", player);
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear invalid input
            printf("Invalid input! Please enter a number between 1 and 9.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
            validMove = 1;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}


//  Check for win
int checkWin() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;

    for (int j = 0; j < 3; j++)
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return 1;

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

//  Check for draw
int checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

 // Display scores
void displayScores() {
    printf("Scores:\n");
    printf("Player X: %d\n", playerXScore);
    printf("Player O: %d\n", playerOScore);
    printf("------------------------\n");
}

//  Reset board for new game
void resetBoard() {
    initializeBoard();
}

int main() {
    char currentPlayer;
    int gameOver;
    int roundsPlayed = 0;

    printf("Tic-Tac-Toe Game (Best of 3)\n");
    printf("Use numbers 1-9 to make your move.\n");

    while (playerXScore < 2 && playerOScore < 2 && roundsPlayed < 3) {
        resetBoard();
        gameOver = 0;
        currentPlayer = (roundsPlayed % 2 == 0) ? 'X' : 'O'; // Alternate starting player

        displayBoard();

        while (!gameOver) {
            playerMove(currentPlayer);
            displayBoard();

            if (checkWin()) {
                printf("Player %c wins this round!\n", currentPlayer);
                if (currentPlayer == 'X') playerXScore++;
                else playerOScore++;
                gameOver = 1;
            } else if (checkDraw()) {
                printf("This round is a draw!\n");
                gameOver = 1;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        roundsPlayed++;
        displayScores();
    }

    // Final result
    if (playerXScore > playerOScore)
        printf(" Player X wins the Best of 3 series!\n");
    else if (playerOScore > playerXScore)
        printf(" Player O wins the Best of 3 series!\n");
    else
        printf(" The series ends in a draw!\n");

    return 0;
}
