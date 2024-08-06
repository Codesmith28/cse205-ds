#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

bool subseq(const string &s, const string &t) {
    int j = 0;
    for (int i = 0; i < s.size() && j < t.size(); i++) {
        if (s[i] == t[j]) {
            j++;
        }
    }
    return j == t.size();
}

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();
    bool found = false;
    string result;

    for (int i = 0; i <= n - m; i++) {
        string temp = s;
        bool valid = true;

        for (int j = 0; j < m; j++) {
            if (temp[i + j] == '?') {
                temp[i + j] = t[j];
            } else if (temp[i + j] != t[j]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            for (int k = 0; k < n; k++) {
                if (temp[k] == '?') {
                    temp[k] = 'a';
                }
            }

            if (subseq(temp, t)) {
                result = temp;
                found = true;
                break;
            }
        }
    }

    if (found) {
        cout << "YES\n" << result << "\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}