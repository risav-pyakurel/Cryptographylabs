#include <stdio.h>
#include <string.h>
void encrypt(char *plaintext, int key)
{
    int i;
    char ch;
    for (i = 0; plaintext[i] != '\0'; ++i)
    {
        ch = plaintext[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = 'a' + (ch - 'a' + key) % 26;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = 'A' + (ch - 'A' + key) % 26;
        }
        plaintext[i] = ch;
    }
}
// Function to decrypt the ciphertext using Caesar cipher
void decrypt(char *ciphertext, int key)
{
    int i;
    char ch;

    for (i = 0; ciphertext[i] != '\0'; ++i)
    {
        ch = ciphertext[i];

        if (ch >= 'a' && ch <= 'z')
        {
            ch = 'a' + (ch - 'a' - key + 26) % 26;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = 'A' + (ch - 'A' - key + 26) % 26;
        }

        ciphertext[i] = ch;
    }
}
int main()
{
    char plaintext[100];
    int key;
    printf("Enter plaintext: \n");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the key (a number between 0 and 25): \n");
    scanf("%d", &key);
    encrypt(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);
    decrypt(plaintext, key);
    printf("Decrypted text: %s\n", plaintext);
    return 0;
}
