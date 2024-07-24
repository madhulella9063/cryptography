#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int textLength = strlen(plaintext);
    int keyLength = strlen(key);
    int i, j;

    j = 0; // Initialize j outside the loop
    for (i = 0; i < textLength; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            char keyBase = isupper(key[j % keyLength]) ? 'A' : 'a';

            // Encrypt the letter
            ciphertext[i] = (plaintext[i] - base + (toupper(key[j % keyLength]) - 'A')) % 26 + base;
            j++;
        } else {
            // Copy non-alphabetic characters directly
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[textLength] = '\0';  // Null-terminate the ciphertext
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int textLength = strlen(ciphertext);
    int keyLength = strlen(key);
    int i, j;

    j = 0; // Initialize j outside the loop
    for (i = 0; i < textLength; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            char keyBase = isupper(key[j % keyLength]) ? 'A' : 'a';

            // Decrypt the letter
            plaintext[i] = (ciphertext[i] - base - (toupper(key[j % keyLength]) - 'A') + 26) % 26 + base;
            j++;
        } else {
            // Copy non-alphabetic characters directly
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[textLength] = '\0';  // Null-terminate the plaintext
}

int main() {
    char plaintext[MAX_LENGTH];
    char key[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
    char decryptedtext[MAX_LENGTH];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    // Remove newline character from fgets input
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    // Remove newline character from fgets input
    key[strcspn(key, "\n")] = '\0';

    // Ensure the key is uppercase for consistency
    int i;
    for (i = 0; key[i]; i++) {
        key[i] = toupper(key[i]);
    }

    encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    decrypt(ciphertext, key, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}