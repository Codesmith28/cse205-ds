#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool is_palin(vector<int> &char_count) {
        int odd_count = 0;
        for (int count : char_count) {
            if (count % 2 != 0) odd_count++;
        }
        return odd_count <= 1;
    }

    vector<bool> findAnswer(vector<int> &par, string s) {
        int n = par.size( );
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[par[i]].push_back(i);
            adj[i].push_back(par[i]);
        }

        vector<bool> res(n, false);
        vector<long long> forward_hash(n, 0), reverse_hash(n, 0);
        vector<long long> power(n, 1);

        const int MOD = 1e9 + 7;
        const int BASE = 31;

        auto dfs = [&](auto &&dfs, int node) -> void {
            int ch = s[node] - 'a' + 1;
            forward_hash[node] = ch;
            reverse_hash[node] = (ch * power[0]) % MOD;

            for (int child : adj[node]) {
                dfs(dfs, child);

                forward_hash[node] = (forward_hash[node] + forward_hash[child] * BASE) % MOD;
                reverse_hash[node] = (reverse_hash[node] + reverse_hash[child]) % MOD;
            }

            res[node] = (forward_hash[node] == reverse_hash[node]);

            reverse_hash[node] = (reverse_hash[node] * BASE) % MOD;
        };

        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * BASE) % MOD;
        }

        dfs(dfs, 0);

        return res;
    }
};

int main( ) {
    return 0;
}
