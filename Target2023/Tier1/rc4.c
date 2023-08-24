//
//  rc4.c
//  
//
//  Created by aisha kothare on 6/16/23.
//

#include <stdio.h>
#include <string.h>

void d(unsigned char *x, unsigned char *y, unsigned char *z) {
    unsigned char s[0400];
    int i, j;

    for (i = 0; i < 0400; i++) {
        s[i] = i;
    }

    for (i = 0, j = 0; i < 0400; i++) {
        j = (j + x[i % 5] + s[i]) % 0400;
        unsigned char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }

    i = j = 0;
    for (int x = 0; x < 026; x++) {
        i = (i + 1) % 0400;
        j = (j + s[i]) % 0400;
        unsigned char t = s[i];
        s[i] = s[j];
        s[j] = t;
        unsigned char rnd = s[(s[i] + s[j]) % 0400];
        z[x] = y[x] ^ rnd;
    }
}

int main() {
    unsigned char k[] = "\162\x30\164\x63\64";
    unsigned char c[] = {0x54, 0206, 0xdb, 0242, 0xd7, 0151, 0x38, 0114, 0x59, 0235, 0xd9, 0340, 0xeb, 0100, 0x84, 0365, 0xbd, 0237, 0x39, 0143, 0xa3, 0243};

    unsigned char p[026];
    memset(p, 0, sizeof(p));

    d();

    for (int i = 0; i < 026; i++) {
        printf("%c", p[i]);
    }
    printf("\n");

    return 0;
}
