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

void solve( ) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a) cin >> i;

        stack<int> st;

        vector<int> prevSmaller(n);
        for (int i = 0; i < n; i++) {
                int curr = a[i];
                while (!st.empty( ) && a[st.top( )] >= curr) st.pop( );
                prevSmaller[i] = st.empty( ) ? -1 : st.top( );
                st.push(i);
        }

        while (!st.empty( )) st.pop( );

        vector<int> nextSmaller(n);
        for (int i = n - 1; i >= 0; i--) {
                int curr = a[i];
                while (!st.empty( ) && a[st.top( )] >= curr) st.pop( );
                nextSmaller[i] = st.empty( ) ? n : st.top( );
                st.push(i);
        }

        vector<int> res(n + 1, 0);
        for (int i = 0; i < n; i++) {
                int l = prevSmaller[i];
                int r = nextSmaller[i];
                int len = r - l - 1;
                res[len] = max(res[len], a[i]); // max range for a[i] to be minimum
        }
        for (int i = n - 1; i >= 0; i--) res[i] = max(res[i], res[i + 1]); // propagate answers further

        for (int i = 1; i <= n; i++) cout << res[i] << " ";
        cout << endl;
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
