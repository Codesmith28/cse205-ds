#include <bits/stdc++.h>
#include <vector>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int wins = 0;

    vi c1 = {a, b};
    vi c2 = {c, d};
    vi c3 = {b, a};
    vi c4 = {d, c};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int w = c1[i];
            int x = c3[i];
            int y = c2[j];
            int z = c4[j];

            int win = 0;
            int lose = 0;

            if (w > y) {
                win++;
            } else if (w < y) {
                lose++;
            }

            if (x > z) {
                win++;
            } else if (x < z) {
                lose++;
            }

            if (win > lose) {
                wins++;
            }
        }
    }

    cout << wins << endl;
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}