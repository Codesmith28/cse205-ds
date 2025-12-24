#include <bits/stdc++.h>
#include <cmath>
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
const int mod = 1e9 + 7;

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

  public:
    KMP(const string &pat) : pattern(pat) {
        int m = pattern.size( );
        lps.resize(m, 0);
        computeLPS( );
    }

    vector<int> getLPS( ) const {
        return lps;
    }

    vector<int> getOccurrences(const string &text) {
        return search(text);
    }

    int conv(char c) const {
        return c == '(' ? 0 : 1;
    }

    vector<vector<int>> buildNext( ) const {
        int m = pattern.size( );
        vector<vector<int>> nxt(m + 1, vector<int>(2, 0));
        vector<char> chars = {'(', ')'};

        for (int j = 0; j <= m; j++) {
            for (char c : chars) {
                if (j < m && pattern[j] == c)
                    nxt[j][conv(c)] = j + 1;
                else if (j == 0)
                    nxt[j][conv(c)] = 0;
                else
                    nxt[j][conv(c)] = nxt[lps[j - 1]][conv(c)];
            }
        }

        return nxt;
    }
};

void solve( ) {
    int n;
    string s;
    cin >> n >> s;

    KMP kmp(s);
    vector<vector<int>> nxt = kmp.buildNext( );

    // {open, close, matchLen, found}
    map<tuple<int, int, int, bool>, int> dp;

    auto dfs = [&](auto &&go, int open, int close, int matchLen, bool found) -> int {
        if (open > n || close > n) return 0;
        if (open == n && close == n) return found;

        auto key = make_tuple(open, close, matchLen, found);
        if (dp.count(key)) return dp[key];

        int res = 0;

        // add "("
        if (open < n) {
            // string temp = curr + "(";
            // bool nextFound = found || (temp.find(s) != string::npos);
            // res = (res + go(go, open + 1, close, temp, nextFound)) % mod;
            int nxtMatch = nxt[matchLen][kmp.conv('(')];
            bool nxtFonud = found || (nxtMatch == s.size( ));
            res = (res + go(go, open + 1, close, nxtMatch, nxtFonud)) % mod;
        }

        // add ")"
        if (close < open) {
            // string temp = curr + ")";
            // bool nextFound = found || (temp.find(s) != string::npos);
            // res = (res + go(go, open, close + 1, temp, nextFound)) % mod;
            int nxtMatch = nxt[matchLen][kmp.conv(')')];
            bool nxtFonud = found || (nxtMatch == s.size( ));
            res = (res + go(go, open, close + 1, nxtMatch, nxtFonud)) % mod;
        }

        return dp[key] = res;
    };

    cout << dfs(dfs, 0, 0, 0, false) << endl;
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