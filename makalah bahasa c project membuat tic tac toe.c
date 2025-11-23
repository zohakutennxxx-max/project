#include <stdio.h>
#include <string.h>

char board[3][3];

void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n    1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d   ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) printf(" | ");
        }
        printf("\n");
        if (i < 2) printf("   ---+---+---\n");
    }
    printf("\n");
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;

        // Vertical
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }


    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    return 0;
}

int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

int main() {
    char player1[30], player2[30];
    int row, col, currentPlayer = 1;
    char mark;

    printf("=== PERMAINAN TIC-TAC-TOE (X-O) ===\n");

    printf("Masukkan nama Pemain 1 (X): ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = '\0';  // hapus newline

    printf("Masukkan nama Pemain 2 (O): ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = '\0';

    resetBoard();

    while (1) {
        printBoard();

        if (currentPlayer == 1) {
            printf("Giliran %s (X)\n", player1);
            mark = 'X';
        } else {
            printf("Giliran %s (O)\n", player2);
            mark = 'O';
        }


        printf("Masukkan baris (1-3): ");
        scanf("%d", &row);
        printf("Masukkan kolom (1-3): ");
        scanf("%d", &col);


        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Input tidak valid! Coba lagi.\n");
            continue;
        }

        if (board[row - 1][col - 1] != ' ') {
            printf("Kotak sudah terisi! Pilih yang lain.\n");
            continue;
        }


        board[row - 1][col - 1] = mark;


        if (checkWin()) {
            printBoard();
            if (currentPlayer == 1)
                printf("SELAMAT! %s (X) MENANG!\n", player1);
            else
                printf("SELAMAT! %s (O) MENANG!\n", player2);
            break;
        }


        if (isDraw()) {
            printBoard();
            printf("PERTANDINGAN SERI!\n");
            break;
        }


        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
