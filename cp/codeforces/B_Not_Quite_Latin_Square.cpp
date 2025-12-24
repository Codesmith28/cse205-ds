#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {

    int a = 0, b = 0;

    vector<vector<char>> v(3, vector<char>(3)); // Fix: Changed int to char to correctly store '?'
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (v[i][j] == '?') {
                a = i;
                b = j;
            }
        }
    }

    // for the ath row:
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        if (v[a][i] != '?') {
            sum += (v[a][i] - 'A');
        }
    }
    sum = 3 - sum;
    if (sum == 0) {
        cout << "A" << endl;
    }
    else if (sum == 1) {
        cout << "B" << endl;
    }
    else {
        cout << "C" << endl;
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