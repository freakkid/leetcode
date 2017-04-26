bool isAnagram(char* s, char* t) {
    int ss[27] = {0}, tt[27] = {0};
    for (int i = 0; i < strlen(s); i++)
        ++ss[s[i] - 'a' + 1];
    for (int i = 0; i < strlen(t); i++)
        ++tt[t[i] - 'a' + 1];
    for (int i = 0; i < 26; i++) {
        if (tt[i] != ss[i])
            return false;
    }
    return true;
}