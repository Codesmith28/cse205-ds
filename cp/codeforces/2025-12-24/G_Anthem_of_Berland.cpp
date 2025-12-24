#include <algorithm>
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;

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

    set<int> search(const string &text) {
        set<int> occurrences;
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
                occurrences.insert(i - j);
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

  public:
    KMP(const string &pat) : pattern(pat) {
        int m = pattern.size( );
        lps.resize(m, 0);
        computeLPS( );
    }

    vector<int> getLPS( ) const {
        return lps;
    }

    set<int> getOccurrences(const string &text) {
        return search(text);
    }

    // return the len of pattern matched at jth idx and cth char
    vector<vector<int>> buildNext( ) const {
        int m = pattern.size( );
        vector<vector<int>> nxt(m + 1, vector<int>(26, 0));
        for (int j = 0; j <= m; j++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (j < m && pattern[j] == c)
                    nxt[j][c - 'a'] = j + 1; // j + 1 len of pattern is matched
                else if (j == 0)
                    nxt[j][c - 'a'] = 0;
                else
                    nxt[j][c - 'a'] = nxt[lps[j - 1]][c - 'a']; // fallback to prev matched len
            }
        }
        return nxt;
    }
};

void solve( ) {
    string s, p; // string, pattern
    cin >> s >> p;
    int n = s.size( );
    int m = p.size( );

    KMP kmp(p);
    vector<vector<int>> nxt = kmp.buildNext( );
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] == -1) continue;
            if (s[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    int nxtJ = nxt[j][c - 'a'];
                    int val = dp[i][j] + (nxtJ == m);
                    dp[i + 1][nxtJ] = max(dp[i + 1][nxtJ], val);
                }
            } else {
                int c = s[i] - 'a';
                int nxtJ = nxt[j][c];
                int val = dp[i][j] + (nxtJ == m);
                dp[i + 1][nxtJ] = max(dp[i + 1][nxtJ], val);
            }
        }
    }

    cout << *max_element(dp[n].begin( ), dp[n].end( )) << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}