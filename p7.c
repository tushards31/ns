#include <stdio.h>

int mod_pov(int base, int exp, int mod) {
    int res = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    int p, g;
    int priv_a, priv_b;

    printf("Enter prime p: ");
    scanf("%d", &p);   // original value: 23

    printf("Enter generator g: ");
    scanf("%d", &g);   // original value: 5

    printf("Enter private key for A: ");
    scanf("%d", &priv_a);  // original value: 6

    printf("Enter private key for B: ");
    scanf("%d", &priv_b);  // original value: 15

    int pub_a = mod_pov(g, priv_a, p);
    int pub_b = mod_pov(g, priv_b, p);

    int key_a = mod_pov(pub_b, priv_a, p);
    int key_b = mod_pov(pub_a, priv_b, p);

    printf("\nShared keys (Diffie–Hellman):\n");
    printf("Key computed by A: %d\n", key_a);
    printf("Key computed by B: %d\n", key_b);

    return 0;
}
