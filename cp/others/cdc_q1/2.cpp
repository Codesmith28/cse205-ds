#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int divideList(vector<int> &arr) {
    int n = arr.size( );
    vector<int> pref_pos(n + 1, 0);
    vector<int> suff_neg(n + 1, 0);

    for (int i = 0; i < n; i++) pref_pos[i + 1] = pref_pos[i] + (arr[i] >= 0 ? 1 : 0);
    for (int i = n - 1; i >= 0; i--) suff_neg[i] = suff_neg[i + 1] + (arr[i] <= 0 ? 1 : 0);

    int res = n;
    for (int i = 0; i <= n; ++i) {
        int curr = pref_pos[i] + suff_neg[i];
        res = min(res, curr);
    }

    return res;
}

int main( ) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    cout << divideList(arr) << endl;
    return 0;
}
