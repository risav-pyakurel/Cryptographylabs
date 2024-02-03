#include <stdio.h>
#include <stdbool.h>
int power(int x, unsigned int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
bool isPrimitiveRoot(int n, int prime) {
    bool visited[prime];
    for (int i = 0; i < prime; i++) {
        visited[i] = false;
    }

    for (int i = 1; i < prime; i++) {
        int val = power(n, i, prime);
        if (visited[val])
            return false;
        visited[val] = true;
}
    return true;
}
int findPrimitiveRoot(int prime) {
    for (int i = 2; i < prime; i++) {
        if (isPrimitiveRoot(i, prime))
            return i;
    }
    return -1;
}
int main() {
    int p;
    printf("Enter a prime number: ");
    scanf("%d", &p);
    if (p <= 1) {
        printf("Invalid input: Enter a prime number greater than 1.\n");
        return 1;
    }
    int primitiveRoot = findPrimitiveRoot(p);
    if (primitiveRoot == -1) {
        printf("Primitive root does not exist for %d.\n", p);
    } else {
        printf("The primitive root of %d is: %d\n", p, primitiveRoot);
    }
    return 0;
}

