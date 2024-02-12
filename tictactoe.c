#include <stdio.h>

char board[3][3];

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int check_winner() {
    int i;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1; // Horizontal win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1; // Vertical win
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1; // Diagonal win
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1; // Diagonal win
    return 0;
}

int main() {
    int row, col, player = 1, total_moves = 0, status;

    initialize_board();

    do {
        // Display the board
        display_board();

        // Get player input
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter the row and column to place your symbol (e.g., 1 2): ", player);
        scanf("%d %d", &row, &col);

        // Adjusting row and column for array indexing
        row--;
        col--;

        // Checking if the cell is already occupied
        if (board[row][col] == ' ') {
            board[row][col] = (player == 1) ? 'X' : 'O';
            total_moves++;
            status = check_winner();
            player++;
        } else {
            printf("The cell is already occupied! Please try again.\n");
        }
    } while (status != 1 && total_moves != 9);

    // Display the final board
    display_board();

    // Declare the result
    if (status == 1) {
        printf("Player %d wins!\n", --player);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
