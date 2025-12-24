#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

vector<int> longestCommonPrefix(vector<string> &words) {
    int n = words.size( );
    vector<int> arr(n - 1);

    if (n == 1) return {0};

    auto lcp = [&](string &a, string &b) -> int {
        int i = 0;
        while (i < a.size( ) && i < b.size( ) && a[i] == b[i]) {
            i++;
        }
        return i;
    };

    for (int i = 0; i < n - 1; ++i) arr[i] = lcp(words[i], words[i + 1]);

    vector<int> pref(n - 1, 0), suff(n - 1, 0);
    pref[0] = arr[0];
    for (int i = 1; i < n - 1; ++i) pref[i] = max(pref[i - 1], arr[i]);

    suff[n - 2] = arr[n - 2];
    for (int i = n - 3; i >= 0; --i) suff[i] = max(suff[i + 1], arr[i]);

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int mx = 0;
        if (i > 0 && i < n - 1) mx = lcp(words[i - 1], words[i + 1]);
        if (i > 1) mx = max(mx, pref[i - 2]);
        if (i < n - 2) mx = max(mx, suff[i + 1]);

        ans[i] = mx;
    }

    return ans;
}

int main( ) {
    vector<vector<string>> v = {
        // {"jump", "run", "run", "jump", "run"},
        // {"dog", "racer", "car"},
        // {"fec", "fef", "acaa", "adfa", "afc", "fdbda"},
        {"f", "cfe", "feab", "fcc", "cdfda", "fcec", "afae", "cdeb", "dc", "bffd", "edabe"}
    };
    for (int i = 0; i < v.size( ); i++) {
        vector<string> words = v[i];
        vector<int> result = longestCommonPrefix(words);
        for (int j = 0; j < result.size( ); j++) {
            cout << result[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
