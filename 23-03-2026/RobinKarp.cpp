# There will be collisions because of weak hash function and we can use rolling hash function 
vector<int> rabinKarp(const string& pattern, const string& text) {
    const int base = 31; 
    const int mod = 1e9 + 9;

    int patternLen = pattern.size();
    int textLen = text.size();

    vector<long long> power(max(patternLen, textLen));
    power[0] = 1;
    for (int i = 1; i < (int)power.size(); i++)
        power[i] = (power[i - 1] * base) % mod;

    vector<long long> prefixHash(textLen + 1, 0);
    for (int i = 0; i < textLen; i++)
        prefixHash[i + 1] = 
            (prefixHash[i] + (text[i] - 'a' + 1) * power[i]) % mod;

    long long patternHash = 0;
    for (int i = 0; i < patternLen; i++)
        patternHash = 
            (patternHash + (pattern[i] - 'a' + 1) * power[i]) % mod;

    vector<int> matchPositions;

    for (int i = 0; i + patternLen - 1 < textLen; i++) {
        long long currentHash =
            (prefixHash[i + patternLen] + mod - prefixHash[i]) % mod;

        if (currentHash == (patternHash * power[i]) % mod)
            matchPositions.push_back(i);
    }

    return matchPositions;
}
