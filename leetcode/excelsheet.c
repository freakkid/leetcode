int titleToNumber(char* s) {
    int len = strlen(s), sum = 0;
    for (int i = 0; i < len; i++) {
        sum *= 26;
        sum += s[i] - 'A';
    }
    return sum;
}