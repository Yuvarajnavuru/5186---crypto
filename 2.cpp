#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int isValidKey(char key[]) {
    int letters[ALPHABET_SIZE] = {0};
    for (int i = 0; key[i] && i < ALPHABET_SIZE; i++) {
        if (!isalpha(key[i]) || letters[toupper(key[i]) - 'A']++) return 0;
    }
    return strlen(key) == ALPHABET_SIZE;
}

void monoalphabeticCipher(char text[], char key[]) {
    for (int i = 0; text[i]; i++) {
        char ch = text[i];
        if (isalpha(ch)) text[i] = isupper(ch) ? key[ch - 'A'] : tolower(key[ch - 'a']);
    }
}

int main() {
    char text[1000], key[ALPHABET_SIZE + 1];
    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the substitution key: ");
    scanf("%26s", key);

    if (!isValidKey(key)) {
        printf("Invalid key. Must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    monoalphabeticCipher(text, key);
    printf("Encrypted text: %s\n", text);
    return 0;
}
