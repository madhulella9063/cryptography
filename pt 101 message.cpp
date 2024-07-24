#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to find the row and column of a character in the Playfair matrix
void findPosition(char matrix[5][5], char ch, int* row, int* col) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to decode a Playfair digraph
void decodeDigraph(char matrix[5][5], char digraph[2]) {
    int row1, col1, row2, col2;
    findPosition(matrix, digraph[0], &row1, &col1);
    findPosition(matrix, digraph[1], &row2, &col2);

    if (row1 == row2) {
        // Same row: shift columns left
        printf("%c%c", matrix[row1][(col1 + 4) % 5], matrix[row2][(col2 + 4) % 5]);
    } else if (col1 == col2) {
        // Same column: shift rows up
        printf("%c%c", matrix[(row1 + 4) % 5][col1], matrix[(row2 + 4) % 5][col2]);
    } else {
        // Form a rectangle: swap columns
        printf("%c%c", matrix[row1][col2], matrix[row2][col1]);
    }
}

int main() {
    char matrix[5][5] = {
        {'K', 'X', 'J', 'E', 'Y'},
        {'U', 'R', 'E', 'B', 'Z'},
        {'W', 'T', 'H', 'F', 'S'},
        {'K', 'G', 'O', 'Y', 'I'},
        {'T', 'O', 'L', 'A', 'P'}
    };

    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";

    printf("Decoded plaintext:\n");
    for (int i = 0; i < strlen(ciphertext); i += 2) {
        decodeDigraph(matrix, &ciphertext[i]);
    }
    printf("\n");

    return 0;
}
