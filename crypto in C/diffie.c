#include <math.h>
#include <stdio.h>
long long int power(long long int a, long long int b,
                    long long int P)
{
    if (b == 1)
        return a;

    else
        return (((long long int)pow(a, b)) % P);
}
int main()
{
    long long int P, G, x, a, y, b, ka, kb;
    printf("Enter the value of p and g:");
    scanf("%lld %lld",&P,&G);
printf("The value of P : %lld\n", P);
    printf("The value of G : %lld\n\n", G);
    printf("Enter the private key for alice:");
    scanf("%lld",&a);
    printf("The private key a for Alice : %lld\n", a);
    x = power(G, a, P); // gets the generated key
    printf("Enter the private key for Bob:");
    scanf("%lld",&b);
    printf("The private key b for Bob : %lld\n\n", b);
    y = power(G, b, P); // gets the generated key
    ka = power(y, a, P); // Secret key for Alice
    kb = power(x, b, P); // Secret key for Bob
    printf("Secret key for the Alice is : %lld\n", ka);
    printf("Secret Key for the Bob is : %lld\n", kb);
    return 0;
}

