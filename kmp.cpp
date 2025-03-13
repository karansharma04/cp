#include<bits/stdc++.h>
using namespace std;


int main() {
    string text , pattern;
    cin >> text >> pattern;
    int n = text.size() , m = pattern.size();
    vector<int> lps(m , 0);
    for (int i = 1;i < m;i++) {
        if (pattern[lps[i - 1]] == pattern[i]) {
            lps[i] = lps[i - 1] + 1;
        }
        else if (pattern[i] == pattern[i - 1]) lps[i] = lps[i - 1];
        else lps[i] = 0;
    }
    int j = 0 , i = 0;
    int cnt = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            j++;
            i++;
            if (j == m) {
                cnt++;
                j = lps[j - 1];
                continue;
            }
        }
        else {
            if (j == 0) {
                i++;
                continue;
            }
            j = lps[j - 1];
        }
    }
    cout << cnt << endl;
    return 0;
}