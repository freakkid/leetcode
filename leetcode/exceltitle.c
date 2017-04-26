#include <stdio.h>

char* convertToTitle(int n) {
    char s[10] = {0};
    s[0] = n % 26 + 'A' - 1;
    putchar(s[0]);
    int len = n / 26, i = 0;
    while (len) {
        s[++i] = len % 26 + 'A' - 1;
        len /= 26;
    }
    putchar(s[0]);
    char t[10];
    int j = 0, k = i ;
    for (; k >= 0; j++, k--) {
        t[j] = s[k];
    }
    t[j] = '\0';
    //for (int l = 0; l < i; l++)
        putchar(t[0]);
    return t;
}

int main () {
    int a = 1;
    convertToTitle(a);
  //  printf("%s\n", convertToTitle(a));
    return 0;
}