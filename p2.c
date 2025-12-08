#include <stdio.h>
#include <ctype.h>
void encrypt(char plain[], char key[], char cipher[])
{
 int i;
 for (i = 0; plain[i] != '\0'; i++)
 {
 char ch = plain[i];
 if (isalpha(ch))
 {
 if (islower(ch))
 cipher[i] = key[ch - 'a'];
 else
 cipher[i] = key[ch - 'A'];
 }
 else
 {
 cipher[i] = ch;
 }
 }
 cipher[i] = '\0';
}
void decrypt(char cipher[], char key[], char decrypted[])
{
 int i;
 int j;
 for (i = 0; cipher[i] != '\0'; i++)
 {
 if (isalpha(cipher[i]))
 {
 for (j = 0; j < 26; j++)
 {
 if (toupper(key[j]) == toupper(cipher[i]))
 {
 break;
 }
}
 decrypted[i] = isupper(cipher[i]) ? ('A' + j) : ('a' +
j);
 }
 else
 {
 decrypted[i] = cipher[i];
 }
 }
 decrypted[i] = '\0';
}
void main()
{
 char key[] = "qwertyuiopasdfghjklzxcvbnm";
 char plain[] = "the quick brown fox jumps over the lazy dog";
 char cipher[1000], decrypted[1000];
 printf("original message: %s\n", plain);
 encrypt(plain, key, cipher);
 printf("encrypted message: %s\n", cipher);
 decrypt(cipher, key, decrypted);
 printf("decrypted message: %s\n", decrypted);
}
