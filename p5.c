#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {
    char pt[100], ct[100], key[100], dt[100];

    printf("Enter pt:\n");
    scanf("%s", pt);

    printf("Enter key:\n");
    scanf("%s", key);

    int ptlen = strlen(pt);
    int keylen = strlen(key);

    for (int i = 0; i < ptlen; i++) {
        ct[i] = (pt[i] - 'a' + key[i % keylen] - 'a') % 26 + 'a';
    }
    ct[ptlen] = '\0';

    for (int i = 0; i < ptlen; i++) {
        int val = (ct[i] - 'a' - (key[i % keylen] - 'a'));
        if (val < 0) {
            val += 26;
        }
        dt[i] = val % 26 + 'a';
    }
    dt[ptlen] = '\0';

    printf("%s\n", ct);
    printf("%s\n", dt);
}
