#include <stdio.h>
#include <string.h>
#include <ctype.h>
void encryptRailFence(char *plaintext, int key) {
    int len = strlen(plaintext);
    char rail[key][len];
    for (int i = 0; i < key; ++i)
        for (int j = 0; j < len; ++j)
            rail[i][j] = '\0';
    int row = 0, dir = 0;
    for (int i = 0; i < len; ++i) {
        if (row == 0 || row == key - 1)
            dir = !dir;
        rail[row][i] = plaintext[i];
        dir ? ++row : --row;
    }
    printf("Encrypted text: \n");
    for (int i = 0; i < key; ++i)
        for (int j = 0; j < len; ++j)
            if (rail[i][j] != '\0')
                printf("%c", rail[i][j]);
}
void decryptRailFence(char *ciphertext, int key) {
    int len = strlen(ciphertext);
    char rail[key][len];
    for (int i = 0; i < key; ++i)
        for (int j = 0; j < len; ++j)
            rail[i][j] = '\0';
    int row = 0, dir = 0;
    for (int i = 0; i < len; ++i) {
        if (row == 0)
            dir = 1;
        else if (row == key - 1)
            dir = 0;
        rail[row][i] = '*'; // Placeholder for encrypted characters
        dir ? ++row : --row;
    }
    int index = 0;
    for (int i = 0; i < key; ++i)
        for (int j = 0; j < len; ++j)
            if (rail[i][j] == '*' && index < len)
                rail[i][j] = ciphertext[index++];
    row = 0;
    dir = 0;
    printf("\nDecrypted text: \n");
    for (int i = 0; i < len; ++i) {
        if (row == 0 || row == key - 1)
            dir = !dir;
        printf("%c", rail[row][i]);
        dir ? ++row : --row;
    }
}
int main() {
    char text[100];
    int key;
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the key (number of rails): ");
    scanf("%d", &key);
    // Remove newline from fgets in text
  text[strcspn(text, "\n")] = '\0';
    encryptRailFence(text, key);
    decryptRailFence(text, key);
    return 0;
}
