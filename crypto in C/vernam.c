#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vernamEncrypt(char *plaintext, char *key, char *encryptedMessage) {
    if (strlen(plaintext) != strlen(key)) {
        fprintf(stderr, "Plaintext and key must be of the same length.\n");
        exit(EXIT_FAILURE);
    }

    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        encryptedMessage[i] = (((plaintext[i] - 'A') ^ (key[i] - 'A')) % 26) + 'A';
    }
    encryptedMessage[length] = '\0';
}

void vernamDecrypt(char *ciphertext, char *key, char *decryptedMessage) {
    if (strlen(ciphertext) != strlen(key)) {
        fprintf(stderr, "Ciphertext and key must be of the same length.\n");
        exit(EXIT_FAILURE);
    }

    int length = strlen(ciphertext);
    for (int i = 0; i < length; i++) {
        decryptedMessage[i] = (((ciphertext[i] - 'A') ^ (key[i] - 'A')) % 26) + 'A';
    }
    decryptedMessage[length] = '\0';
}

int main() {
    char plaintext[100], key[100], encryptedMessage[100], decryptedMessage[100];

    // Input plaintext
    printf("Enter the text to be encrypted:\n");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    for (int i = 0; plaintext[i]; i++) {
        plaintext[i] = toupper(plaintext[i]);
    }

    // Input key
    printf("Enter the keyword (same length as plaintext):\n");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    for (int i = 0; key[i]; i++) {
        key[i] = toupper(key[i]);
    }

    // Encryption
    vernamEncrypt(plaintext, key, encryptedMessage);
    printf("Encrypted: %s\n", encryptedMessage);

    // Decryption
    vernamDecrypt(encryptedMessage, key, decryptedMessage);
    printf("Decrypted: %s\n", decryptedMessage);

    return 0;
}
