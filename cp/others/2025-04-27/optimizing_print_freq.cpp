/*
Problem Statement

You own a Xerox shop and take pride in your time management skills. A customer arrives with N files to be printed, and each file 'files[i]' indicates the time it takes to print. With your k printer machines, the objective is to create an optimal assignment, ensuring the minimum possible maximum working time among all machines.

The working time of any machine is defined as the sum of the time it takes to complete all files assigned to it. Your task is to devise an efficient strategy to allocate files to machines, aiming to minimize the maximum working time.

Input Format

    The First line of input contains an integer k.
    The Second line of input contains an integer n (length of files).
    The next n line of input contains an integer.

Constraints

    1 <= k <= files.length <= 12
    1 <= files[i] <= 107

Output Format

    It will be an integer, which is the minimum possible maximum working time among all machines.

Sample test case

Input

2
5
1
2
4
7
8

Output

11
*/

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

int main( ) {
    int k, n;
    cin >> k >> n;
    vector<int> files(n);
    for (int &i : files) cin >> i;
    sort(files.begin( ), files.end( ));

    int low = 0, high = accumulate(files.begin( ), files.end( ), 0);
    int res = 0;
    vector<int> load(k, 0);

    auto chk = [&](auto &&go, int i, int mid) -> bool {
        if (i == n) return true;
        int curr = files[i];

        for (int j = 0; j < k; j++) {
            if (load[j] + curr <= mid) {
                load[j] += curr;
                if (go(go, i + 1, mid)) return true;
                load[j] -= curr;
            }
            if (load[j] == 0) break;
        }

        return false;
    };

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (chk(chk, 0, mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << res << endl;

    return 0;
}
