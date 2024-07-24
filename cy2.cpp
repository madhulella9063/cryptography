#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to create a substitution map based on user input
void createSubstitutionMap(char *ciphertextAlphabet, char *plaintextAlphabet) {
    char used[26] = {0};  // Array to keep track of used letters in the ciphertext alphabet
    int i, j;

    printf("Enter the ciphertext alphabet (26 unique letters):\n");
    fgets(ciphertextAlphabet, 27, stdin);

    // Remove newline character if it exists
    size_t len = strlen(ciphertextAlphabet);
    if (len > 0 && ciphertextAlphabet[len - 1] == '\n') {
        ciphertextAlphabet[len - 1] = '\0';
    }

    // Validate the ciphertext alphabet
    for (i = 0; i < 26; i++) {
        if (!isalpha(ciphertextAlphabet[i]) || used[toupper(ciphertextAlphabet[i]) - 'A']) {
            printf("Invalid ciphertext alphabet. Ensure it has 26 unique letters.\n");
            return;
        }
        used[toupper(ciphertextAlphabet[i]) - 'A'] = 1;
    }

    // Define the plaintext alphabet
    for (i = 0; i < 26; i++) {
        plaintextAlphabet[i] = 'A' + i;
    }
    plaintextAlphabet[26] = '\0';
}

// Function to encrypt the plaintext using the substitution map
void encrypt(char *plaintext, char *ciphertextAlphabet, char *plaintextAlphabet) {
    char ch;
    while ((ch = *plaintext) != '\0') {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = ciphertextAlphabet[ch - 'A'];
            } else {
                ch = tolower(ciphertextAlphabet[ch - 'a']) - 'a' + 'a';
            }
        }
        *plaintext = ch;
        plaintext++;
    }
}

int main() {
    char ciphertextAlphabet[27];
    char plaintextAlphabet[27];
    char plaintext[100];

    // Create substitution map
    createSubstitutionMap(ciphertextAlphabet, plaintextAlphabet);

    // Get the input plaintext from the user
    printf("Enter the plaintext to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove newline character if it exists
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    // Encrypt the plaintext
    encrypt(plaintext, ciphertextAlphabet, plaintextAlphabet);

    // Output the encrypted text
    printf("Encrypted text: %s\n", plaintext);

    return 0;
}