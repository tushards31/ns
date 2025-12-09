#include <stdio.h>

// Function to compute (base^exp) % mod using fast exponentiation
int power(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int main() {
    int p = 61;                 // prime 1
    int q = 53;                 // prime 2
    int n = p * q;              // n = 3233
    int phi = (p - 1) * (q - 1); // phi(n) = 3120
    int e = 17;                 // Public exponent
    int d = 2753;               // Private exponent (precomputed)
    int plaintext = 123;        // Message to encrypt

    // Encryption: c = (m^e) mod n
    int ciphertext = power(plaintext, e, n);

    // Decryption: m = (c^d) mod n
    int decrypted = power(ciphertext, d, n);

    printf("Plaintext : %d\n", plaintext);
    printf("Encrypted : %d\n", ciphertext);
    printf("Decrypted : %d\n", decrypted);

    return 0;
}
