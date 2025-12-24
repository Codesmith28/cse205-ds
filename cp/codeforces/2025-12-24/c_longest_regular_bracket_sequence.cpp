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

// largest regular bracket sequence and its count
void solve( ) {
        string s;
        cin >> s;

        int n = s.size( );
        vector<int> match(n + 1, -1); // pos of match '(' for each ')'
        vector<int> chain(n + 1, -1); // start of longest valid seq ending at i

        stack<int> st;
        for (int i = 0; i < n; i++) {
                if (s[i] == '(') {
                        st.push(i);
                } else if (s[i] == ')') {
                        if (!st.empty( )) {
                                int openIdx = st.top( );
                                st.pop( );
                                match[i] = openIdx;
                                chain[i] = openIdx;

                                // if prev ended as regular string:
                                if (openIdx > 0 && chain[openIdx - 1] != -1) {
                                        chain[i] = chain[openIdx - 1];
                                } else {
                                        chain[i] = match[i];
                                }
                        }
                }
        }

        int mxLen, cnt;
        mxLen = cnt = 0;

        for (int i = 0; i < n; i++) {
                if (chain[i] != -1) {
                        int len = i - chain[i] + 1;
                        if (len > mxLen) {
                                mxLen = len;
                                cnt = 1;
                        } else if (len == mxLen) {
                                cnt++;
                        }
                }
        }

        // invalid case:
        if (mxLen == 0) cnt = 1;

        cout << mxLen << " " << cnt << endl;
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
