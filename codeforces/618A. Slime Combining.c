#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num;
    scanf("%d", &num);
    char str[25];
    itoa(num, str, 2);
    int length = strlen(str);
    int result[25];
    int i = 0, j = 0;
    for (i = 0; i < length; i++) {
        if (str[i] == '1') {
            result[j++] = length - i;
        }     
    }
    for (i = 0; i < j; i++) {
        printf("%d", result[i]);
        if (i != j - 1) {
            putchar(' ');
        }
    }
    putchar('\n');
    return 0;
}