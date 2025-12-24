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
};

void solve( ) {
    string s;
    cin >> s;

    int n = s.size( );
    KMP kmp(s);
    vector<int> lps = kmp.getLPS( );
    // dbg(lps);

    int longest = lps[n - 1];
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < n - 1; i++) vis[lps[i]] = true;

    // lps[i] = substring s[0..i], there’s a prefix = suffix of length lps[i].
    // vis[lps[i]] = true, a prefix of length lps[i] that also appears somewhere before the end

    while (longest > 0) {
        if (vis[longest]) {
            cout << s.substr(0, longest) << endl;
            return;
        }
        longest = lps[longest - 1];
    }

    cout << "Just a legend" << endl;
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