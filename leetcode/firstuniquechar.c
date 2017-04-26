int firstUniqChar(char* s) {
    int alpha[27] = {0};
    for (int i = 0; i < strlen(s); i++)
        ++alpha[s[i] - 'a'];
    int num = 0;
    char ss[26] = {0};
    for (int i = 0; i < 26; i++) {
        if (alpha[i] == 1)
            ss[num++] = i + 'a';
    }
    if (!num)
        return -1;
    for (int i = 0; i < strlen(s); i++) {
        for (int j = 0; j < num; j++)
            if (ss[i] == s[i])
                return i;
    }
    return 0;
}
int firstUniqChar(char* s) {
    int alpha[27][2] = {0}, min = -1;
    for (int i = 0; i < strlen(s); i++) {
        if (!alpha[s[i] - 'a'][0])
            alpha[s[i] - 'a'][1] = i;
        ++alpha[s[i] - 'a'][0]; 
    }
    for (int i = 0; i < 26; i++) {
        if (!alpha[i][0] && min > alpha[i][1])
            min = alpha[i][1];
    }
    return min;
}