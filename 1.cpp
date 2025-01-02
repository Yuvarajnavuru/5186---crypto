#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarCipher(char *text, int key) {
    int i;
    char ch;
    for (i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        if (isupper(ch)) {
            text[i] = (ch - 'A' + key) % 26 + 'A';
        } else if (islower(ch)) {
            text[i] = (ch - 'a' + key) % 26 + 'a';
        }
    }
}

int main() {
    char text[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    if (key < 1 || key > 25) {
        printf("Key must be in the range 1-25.\n");
        return 1;
    }

    caesarCipher(text, key);
    printf("Encrypted message: %s\n", text);

    return 0;
}
