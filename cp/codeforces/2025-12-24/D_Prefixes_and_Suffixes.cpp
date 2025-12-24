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

    map<int, int> fq;
    for (int i = 0; i < n; i++) fq[lps[i]]++;                // prefix fq
    for (int i = n - 1; i > 0; i--) fq[lps[i - 1]] += fq[i]; // propagate prefix
    for (int i = 1; i <= n; i++) fq[i]++;                    // each prefix appears atleast once

    vector<pii> res; // [li, ci]
    int longest = n;
    while (longest > 0) {
        res.push_back({longest, fq[longest]});
        longest = lps[longest - 1]; // hop to next longest pref=suff
    }

    sort(res.begin( ), res.end( ), [&](pii a, pii b) {
        return a.first < b.first;
    });
    cout << res.size( ) << endl;
    for (auto &[li, ci] : res) cout << li << " " << ci << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}