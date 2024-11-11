#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> even(26, 0), odd(26, 0);

    if (n % 2 == 1) {
        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 0) {
                even[s[i] - 'a']++;
            } else {
                odd[s[i] - 'a']++;
            }
        }

        int maxEven = *max_element(even.begin(), even.end());
        int maxOdd = *max_element(odd.begin(), odd.end());

        int res = n - maxEven - maxOdd;

        for (int i = n - 2; i >= 0; i--) {
            if (i % 2) {
                odd[s[i] - 'a']--;
                odd[s[i + 1] - 'a']++;
            } else {
                even[s[i] - 'a']--;
                even[s[i + 1] - 'a']++;
            }

            maxEven = *max_element(even.begin(), even.end());
            maxOdd = *max_element(odd.begin(), odd.end());

            res = min(res, n - maxEven - maxOdd);
        }

        cout << res << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even[s[i] - 'a']++;
        } else {
            odd[s[i] - 'a']++;
        }
    }

    int maxEven = *max_element(even.begin(), even.end());
    int maxOdd = *max_element(odd.begin(), odd.end());

    int res = n - maxEven - maxOdd;
    cout << res << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
