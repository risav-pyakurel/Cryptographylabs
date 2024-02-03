#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mod_pow(int base, int exponent, int mod) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

int main() {
    // Step 1
    int p = 3;
    int q = 7;

    // Step 2
    int n = p * q;
    printf("n = %d\n", n);

    // Step 3
    int phi = (p - 1) * (q - 1);

    // Step 4
    int e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        } else {
            e++;
        }
    }
    printf("e = %d\n", e);

    // Step 5
    int k = 2;
    int d = 0;
    while (((k * phi) + 1) % e != 0) {
        k++;
    }
    d = ((k * phi) + 1) / e;
    printf("d = %d\n", d);
    printf("Public key: {%d, %d}\n", e, n);
    printf("Private key: {%d, %d}\n", d, n);

    // Plain text
    int msg = 11;
    printf("Original message: %d\n", msg);

    // Encryption
    int C = mod_pow(msg, e, n);
    printf("Encrypted message: %d\n", C);

    // Decryption
    int M = mod_pow(C, d, n);
    printf("Decrypted message: %d\n", M);

    return 0;
}