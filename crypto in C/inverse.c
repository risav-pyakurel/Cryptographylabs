#include <stdio.h>
int extendedEuclidean(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extendedEuclidean(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
int modInverse(int a, int p) {
    int x, y;
    int gcd = extendedEuclidean(a, p, &x, &y);
    if (gcd != 1) {
        printf("Inverse doesn't exist\n");
        return -1; 
    } else {
        int result = (x % p + p) % p;
        return result;
    }
}
int main() {
    int a, p;
    printf("Enter a and p (a mod p): ");
    scanf("%d %d", &a, &p);
    int inverse = modInverse(a, p);
    if (inverse != -1) {
        printf("Multiplicative inverse of %d under modulo %d is: %d\n", a, p, inverse);
    }
    return 0;
}
