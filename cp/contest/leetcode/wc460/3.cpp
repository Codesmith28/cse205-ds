#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

const int N = 1e6 + 5;
vector<bool> is_prime(N, true);
vector<int> primes;

void sieve( ) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}

vector<int> get_fac(int x) {
    vector<int> res;
    for (int p : primes) {
        if (p * p > x) break;
        if (x % p == 0) {
            res.push_back(p);
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1) res.push_back(x);
    return res;
}

class Solution {
  public:
    int minJumps(vector<int> &nums) {
        sieve( );
        int n = nums.size( );

        map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int p : get_fac(nums[i])) {
                adj[p].push_back(i);
            }
        }

        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;

        int steps = 0;
        while (!q.empty( )) {
            int sz = q.size( );
            while (sz--) {
                int node = q.front( );
                q.pop( );
                if (node == n - 1) return steps;

                // prev and next
                for (int it : {node - 1, node + 1}) {
                    if (it >= 0 && it < n && !vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }

                // prime
                int p = nums[node];
                if (is_prime[p]) {
                    for (int idx : adj[p]) {
                        if (!vis[idx]) {
                            vis[idx] = true;
                            q.push(idx);
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

int main( ) {
    vector<vector<int>> testCases = {
        {1, 2, 4, 6},
        {2, 3, 4, 7, 9},
        {4, 6, 5, 8},
        {7, 5, 7},
        {136, 343, 319, 341, 472, 278, 182, 356, 237, 387, 200, 45, 34, 111, 471, 155, 462, 500, 468, 513, 185, 210, 70},
        {350, 404, 300, 366, 304, 452, 410, 515, 100, 176, 140, 109, 14, 67, 132, 276, 454, 156, 503, 459, 377, 315, 473}
    };
    Solution sol;
    for (auto &testCase : testCases) {
        int result = sol.minJumps(testCase);
        cout << result << endl;
    }
    return 0;
}
