#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max 10

int key[max][max];
int size;

void encrypt(char message[], char cipher[]) {
    int len = strlen(message);

    while (len % size != 0) {
        message[len++] = 'X';
    }
    message[len] = '\0';

    for (int i = 0; i < len; i += size) {
        for (int row = 0; row < size; row++) {
            int sum = 0;
            for (int col = 0; col < size; col++) {
                sum += key[row][col] * (message[i + col] - 'A');
            }
            cipher[i + row] = (sum % 26) + 'A';
        }
    }
    cipher[len] = '\0';
}

void main() {
    char message[50], cipher[50];

    printf("Enter the size of the key matrix:\n");
    scanf("%d", &size);

    printf("Enter the key matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    printf("Enter the message:\n");
    scanf("%s", message);

    for (int i = 0; message[i]; i++) {
        message[i] = toupper(message[i]);
    }

    encrypt(message, cipher);

    printf("%s\n", cipher);
}
