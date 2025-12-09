#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main(void) {
    unsigned char key[16] = "0123456789abcdef";
    unsigned char pt[16]  = "welcome to ISE";   /* <=16 bytes */
    unsigned char ct[16], out[17];
    AES_KEY aes;

    AES_set_encrypt_key(key, 128, &aes);
    AES_encrypt(pt, ct, &aes);

    AES_set_decrypt_key(key, 128, &aes);
    AES_decrypt(ct, (unsigned char*)out, &aes);

    out[16] = '\0'; /* ensure NUL termination for printing */

    printf("Plain : %s\n", pt);
    printf("Cipher: ");
    for (int i = 0; i < 16; ++i) printf("%02x", ct[i]);
    printf("\nDec   : %s\n", out);

    return 0;
}
