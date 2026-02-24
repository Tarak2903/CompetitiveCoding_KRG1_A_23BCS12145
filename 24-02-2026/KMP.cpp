#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);

    int len = 0; 
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}


vector<int> KMP(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPS(pattern);
    vector<int> occurrences;

    int i = 0; 
    int j = 0; 

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            occurrences.push_back(i - j); 
            j = lps[j - 1];             
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return occurrences;
}


int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";

    vector<int> result = KMP(text, pattern);

    for (int idx : result) {
        cout << "Pattern found at index: " << idx << endl;
    }

    return 0;
}
