#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
 
char matrix[5][5]; 
 
void createMatrix(char key[]) 
{ 
    int seen[26] = {0}; 
    seen['J' - 'A'] = 1; 
    int row = 0; 
    int col = 0; 
    for (int i = 0; key[i] != '\0'; i++)
    { 
        if (isalpha(key[i])) 
        { 
            char ch = toupper(key[i]); 
            if (ch == 'J') 
            { 
                ch = 'I'; 
            } 
            if (seen[ch - 'A'] == 0) 
            { 
                matrix[row][col++] = ch; 
                seen[ch - 'A'] = 1; 
            } 
            if (col == 5) 
            { 
                row++; 
                col = 0; 
            } 
        } 
    } 
    for (char ch = 'A'; ch <= 'Z'; ch++) 
    { 
        if (seen[ch - 'A'] == 0) 
        { 
            matrix[row][col++] = ch; 
            seen[ch - 'A'] = 1; 
        } 
        if (col == 5) 
        { 
            row++; 
            col = 0; 
        } 
    } 
} 
 
void printmatrix() 
{ 
    for (int i = 0; i < 5; i++) 
    { 
        for (int j = 0; j < 5; j++)
         { 
            printf("%c\t", matrix[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
int findrow(char ch) 
{ 
    for (int i = 0; i < 5; i++) 
    { 
        for (int j = 0; j < 5; j++) 
        { 
            if (matrix[i][j] == ch) 
            { 
                return i; 
            } 
        } 
    } 
    return -1; 
} 
int findcol(char ch) 
{ 
    for (int i = 0; i < 5; i++) 
    { 
        for (int j = 0; j < 5; j++) 
        { 
            if (matrix[i][j] == ch) 
            { 
                return j; 
            } 
        } 
    } 
    return -1; 
} 
 
void encrypt(char plain[], char cipher[]) 
{ 
    char temp[100]; 
    int k = 0; 
 int len = 0; 
    for (int i = 0; plain[i] != '\0'; i++) 
    { 
        len++; 
    } 
    for (int i = 0; i < len; i++) 
    { 
        if (plain[i] == 'J') 
        { 
            temp[k++] = 'I'; 
        } 
        else 
        { 
            temp[k++] = toupper(plain[i]); 
        } 
        if (i + 1 < len && toupper(plain[i]) == toupper(plain[i + 
1])) 
        { 
            temp[k++] = 'X'; 
        } 
    } 
    if (k % 2 != 0) 
    { 
        temp[k++] = 'Z'; 
    } 
    temp[k] = '\0'; 
 
    int ci = 0; 
    for (int i = 0; i < k; i += 2) 
    { 
        int r1 = findrow(temp[i]); 
        int r2 = findrow(temp[i + 1]); 
        int c1 = findcol(temp[i]); 
        int c2 = findcol(temp[i + 1]); 
 
        if (r1 == r2) 
        { 
            cipher[ci++] = matrix[r1][(c1 + 1) % 5]; 
            cipher[ci++] = matrix[r1][(c2 + 1) % 5]; 
        }
         else if (c1 == c2) 
        { 
            cipher[ci++] = matrix[(r1 + 1) % 5][c1]; 
            cipher[ci++] = matrix[(r2 + 1) % 5][c1]; 
        } 
        else 
        { 
            cipher[ci++] = matrix[r1][c2]; 
            cipher[ci++] = matrix[r2][c1]; 
        } 
    } 
    cipher[ci] = '\0'; 
} 
void main() 
{ 
    char plain[] = "hello"; 
    char key[] = "war"; 
    char cipher[100]; 
    createMatrix(key); 
    printmatrix(); 
    printf("%s\n", plain); 
    encrypt(plain, cipher); 
    printf("%s\n", cipher);
}
