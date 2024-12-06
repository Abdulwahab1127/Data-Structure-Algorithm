#include <stdio.h>

#define SIZE 4

void displayChessboard(int chessboard[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++)
            printf("%c ", chessboard[row][col] ? 'Q' : '.');
        printf("\n");
    }
    printf("\n");
}

int isQueenSafe(int chessboard[SIZE][SIZE], int row, int col) {
    for (int i = 0; i < col; i++){
        if (chessboard[row][i] || chessboard[row - i][col - i] || chessboard[row + i][col - i])
                    return 0;
    }
    return 1;
}

int solveNQueensProblem(int chessboard[SIZE][SIZE], int col) {
    if (col == SIZE) {
        displayChessboard(chessboard);
        return 1;
    }

    int solutionsCount = 0;
    for (int row = 0; row < SIZE; row++) {
        if (isQueenSafe(chessboard, row, col)) {
            chessboard[row][col] = 1;
            solutionsCount += solveNQueensProblem(chessboard, col + 1);
            chessboard[row][col] = 0;
        }
    }

    return solutionsCount;
}

int main() {
    int chessboard[SIZE][SIZE] = {0};

    int totalSolutions = solveNQueensProblem(chessboard, 0);

    if (totalSolutions == 0) {
        printf("No solutions \n");
    } else {
        printf("Solutions: %d\n", totalSolutions);
    }

    return 0;
}
