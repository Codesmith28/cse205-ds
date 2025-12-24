#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

/*
    Given string s,
    we can reverse any substring of s
    find the total number of distinct strings we can get by reversing substrings of s
*/

// int variability(string s) {
//     int n = s.size( );
//     set<string> dis;
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             string temp = s;
//             reverse(temp.begin( ) + i, temp.begin( ) + j + 1);
//             dis.insert(temp);
//         }
//     }
//     return dis.size( );
// }

int variability(string s) {
    int n = s.size( );
    int ans = 1;
    map<char, int> cnt;
    cnt[s[n - 1]] = 1;
    for (int i = n - 2; i >= 0; i--) {
        ans += (n - i - 1);
        ans -= cnt[s[i]];
        cnt[s[i]]++;
    }
    return ans;
}

int main( ) {
    string s;
    cin >> s;
    cout << variability(s);
    return 0;
}