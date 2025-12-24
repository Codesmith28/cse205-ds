#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class KMP {
  private:
    vector<int> lps;
    string pattern;

    void computeLPS( ) {
        int m = pattern.size( );
        int len = 0;
        lps[0] = 0; // lps[0] is always 0
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
    }

  public:
    KMP(const string &pat) : pattern(pat) {
        int m = pattern.size( );
        lps.resize(m, 0);
        computeLPS( );
    }

    vector<int> getLPS( ) const {
        return lps;
    }

    vector<int> search(const string &text) {
        vector<int> occurrences;
        int m = pattern.size( );
        int n = text.size( );

        int i = 0; // index for text
        int j = 0; // index for pattern

        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }

            if (j == m) {
                occurrences.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return occurrences;
    }
};

int main( ) {
    KMP kmp("ABABCABAB");
    vector<int> result = kmp.search("BABABABABCABABCABABA");
    for (int pos : result) {
        cout << "Pattern found at index: " << pos << endl;
    }
    return 0;
}