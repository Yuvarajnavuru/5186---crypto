#include <stdio.h>
#include <string.h>

void cbc_mac(char *message, char *key, char *mac, int block_size) {
    char iv[16] = {0};  // Initialization vector set to 0
    for (int i = 0; i < strlen(message); i += block_size) {
        for (int j = 0; j < block_size; j++) {
            iv[j] ^= message[i + j];
            iv[j] ^= key[j % strlen(key)];
        }
    }
    strncpy(mac, iv, block_size);
}

int main() {
    char message[] = "HELLOBLOCK";
    char key[] = "12345678";
    char mac[16];
    cbc_mac(message, key, mac, 8);
    printf("CBC-MAC: ");
    for (int i = 0; i < 8; i++) {
        printf("%02X", (unsigned char)mac[i]);
    }
    printf("\n");
    return 0;
}
