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
};

void solve( ) {
    string s, t;
    cin >> s >> t;
    int n = s.size( );
    int m = t.size( );

    KMP kmp(t);
    set<int> occur = kmp.getOccurrences(s);
    // dbg(occur);

    vector<bool> good(n + 1, 0);
    for (auto &i : occur) good[i + m] = true;

    vector<int> endsAt, res, sum;
    endsAt = res = sum = vector<int>(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!good[i]) {
            endsAt[i] = endsAt[i - 1];
        } else {
            int start = i - m;
            int waysToPick = start + 1;
            endsAt[i] = ((start >= 0 ? sum[start] : 0) + (waysToPick)) % mod;
        }
        res[i] = (res[i - 1] + endsAt[i]) % mod;
        sum[i] = (sum[i - 1] + res[i]) % mod;
    }

    cout << res[n] % mod << endl;
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
