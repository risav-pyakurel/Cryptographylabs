#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

// Function to calculate (a^b) % c
unsigned long long modulo(unsigned long long a, unsigned long long b, unsigned long long c) {
    unsigned long long result = 1;
    a = a % c;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    return result;
}

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find a primitive root modulo p
int findPrimitiveRoot(int p) {
    int phi = p - 1;
    for (int i = 2; i < p; i++) {
        if (gcd(i, p) == 1) {
            bool found = true;
            for (int j = 1; j <= phi; j++) {
                if (modulo(i, j, p) == 1 && j < phi) {
                    found = false;
                    break;
                }
            }
            if (found)
                return i;
        }
    }
    return -1;
}

// Function to generate keys for ElGamal cryptosystem
void generateKeys(int p, int *g, int *x, int *y) {
    *g = findPrimitiveRoot(p);
    *x = rand() % (p - 1) + 1;
    *y = modulo(*g, *x, p);
}

// Function to encrypt a message using ElGamal
void encrypt(int p, int g, int y, int msg, int *a, int *b) {
    int k = rand() % (p - 2) + 1;
    *a = modulo(g, k, p);
    *b = (modulo(y, k, p) * msg) % p;
}

// Function to decrypt a message using ElGamal
int decrypt(int p, int x, int a, int b) {
    int numerator = b % p;
    int denominator = modulo(a, x, p);
    int inv = 1;
    while ((denominator * inv) % p != 1) {
        inv++;
    }
    return (numerator * inv) % p;
}

int main() {
    int p, g, x, y, msg, encryptedMsgA, encryptedMsgB, decryptedMsg;

    printf("Enter a prime number (p): ");
    scanf("%d", &p);

    if (!isPrime(p)) {
        printf("Not a prime number. Exiting...\n");
        return 1;
    }

    g = findPrimitiveRoot(p);

    generateKeys(p, &g, &x, &y);

    printf("Public Key (p, g, y): (%d, %d, %d)\n", p, g, y);
    printf("Private Key (x): %d\n", x);

    printf("Enter the message to be encrypted (an integer): ");
    scanf("%d", &msg);

    encrypt(p, g, y, msg, &encryptedMsgA, &encryptedMsgB);
    printf("Encrypted Message (a, b): (%d, %d)\n", encryptedMsgA, encryptedMsgB);

    decryptedMsg = decrypt(p, x, encryptedMsgA, encryptedMsgB);
    printf("Decrypted Message: %d\n", decryptedMsg);

    return 0;
}
