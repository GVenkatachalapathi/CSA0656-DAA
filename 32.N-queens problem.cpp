#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX][MAX];
int n;

void printSolution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int row, int col) {
    int i, j;
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    return 1;
}

int solveNQUtil(int col) {
    if (col >= n) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(col + 1)) {
                return 1;
            }

            board[i][col] = 0;
        }
    }

    return 0;
}

void solveNQ() {
    if (solveNQUtil(0) == 0) {
        printf("Solution does not exist\n");
        return;
    }

    printSolution();
}

int main() {
    printf("Name :G Venkata Chalapathi\nReg no :192211150");
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Enter a valid number of queens (1-%d)\n", MAX);
        return 1;
    }

    solveNQ();
    return 0;
}