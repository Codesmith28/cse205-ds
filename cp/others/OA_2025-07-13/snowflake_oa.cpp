/*
    array reduction algo that processes array of n ints
    init empty array, len n
    select integer k in [1, n]
    append MEX of first k elems
    remove first k elems

    we are given arr
    what is the lexicographically largest array we can get using this algo ?
*/

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

void max_mext(vector<int> &arr, int n) {
    set<int> st;
    int net_mex = 0;
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
        while (st.count(net_mex)) net_mex++;
    }

    st.clear( );
    string res;
    int curr_mex = 0;
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
        while (st.count(curr_mex)) curr_mex++;
        if (curr_mex == net_mex) {
            res += to_string(curr_mex);
            curr_mex = 0;
            st.clear( );
        }
    }

    if (curr_mex) res += to_string(curr_mex);
    for (char c : res) cout << c << endl;
}

int main( ) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr) cin >> i;
    max_mext(arr, n);
    return 0;
}