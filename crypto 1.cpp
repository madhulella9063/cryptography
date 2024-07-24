#include <stdio.h>
#include <ctype.h>
void caesarCipher(char *text, int shift) {
    char ch;
    while (*text) {
        ch = *text;
        if (isupper(ch)) {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        else if (islower(ch)) {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        
        *text = ch;
        text++;
    }
}

int main() {
    char text[100];
    int shift;
    do {
        printf("Enter shift value (1-25): ");
        scanf("%d", &shift);
        if (shift < 1 || shift > 25) {
            printf("Invalid shift value. Please enter a value between 1 and 25.\n");
        }
    } while (shift < 1 || shift > 25);
    while (getchar() != '\n');
    printf("Enter the text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    caesarCipher(text, shift);
    printf("Encrypted text: %s", text);

    return 0;
}