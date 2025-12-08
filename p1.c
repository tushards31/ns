#include <stdio.h> 
void caesar(char text[], int shift) 
{ 
    for (int i = 0; text[i] != '\0'; i++) 
    { 
        if (text[i] >= 'a' && text[i] <= 'z') 
        { 
            text[i] = 'a' + (text[i] - 'a' + shift + 26) % 26; 
        } 
        else if (text[i] >= 'A' && text[i] <= 'Z') 
        { 
            text[i] = 'A' + (text[i] - 'A' + shift + 26) % 26; 
        } 
    } 
} 
void main() 
{ 
    char text[] = "hello how are you"; 
    int shift = 3; 
    printf("Original message:%s\n", text); 
    caesar(text, shift); 
    printf("encrypted message:%s\n", text); 
    caesar(text, -shift); 
    printf("decrypted message:%s\n", text); 
    
}
