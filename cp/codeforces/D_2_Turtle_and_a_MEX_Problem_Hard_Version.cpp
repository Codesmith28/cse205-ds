#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, m;
    cin >> n >> m;

    int mxmex = 0;
    set<int> st;

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        while (l--) {
            int x;
            cin >> x;
            st.insert(x);
        }

        // find the second mex value
        bool first = false;
        int num = 0;
        while (true) {
            if (st.find(num) == st.end()) {
                if (!first) {
                    first = true;
                } else {
                    mxmex = max(mxmex, num);
                    break;
                }
            }
            num++;
        }

        st.clear();
    }

    if (mxmex >= m) {
        cout << (m + 1) * mxmex << endl;
    } else {
        // upto mxmex the ans is mxmex
        int a = (mxmex + 1) * mxmex;
        // after mxmex the ans is mxmex + 1
        int b = ((m) * (m + 1)) / 2 - ((mxmex) * (mxmex + 1)) / 2;
        cout << a + b << endl;
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