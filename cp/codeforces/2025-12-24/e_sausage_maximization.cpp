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
const int MXBITS = 60;

class BitTrie {
        struct TrieNode {
                TrieNode *child[2];
                TrieNode( ) {
                        for (int i = 0; i < 2; i++) child[i] = nullptr;
                }
        };
        TrieNode *root;

      public:
        BitTrie( ) {
                root = new TrieNode( );
        }
        void insert(int num) {
                TrieNode *node = root;
                for (int i = MXBITS; i >= 0; i--) {
                        int bit = (num >> i) & 1;
                        if (!node->child[bit]) {
                                node->child[bit] = new TrieNode( );
                        }
                        node = node->child[bit];
                }
        }
        int getMaxXor(int num) {
                TrieNode *node = root;
                int mxXor = 0;
                for (int i = MXBITS; i >= 0; i--) {
                        int bit = (num >> i) & 1;
                        int want = 1 - bit;
                        if (node->child[want]) { // if wanted bit exists
                                mxXor |= (1LL << i);
                                node = node->child[want];
                        } else { // go to existing bit
                                node = node->child[bit];
                        }
                }
                return mxXor;
        }
};

void solve( ) {
        int n;
        cin >> n;
        vector<int> a(n);
        int total = 0;
        for (int &i : a) {
                cin >> i;
                total ^= i;
        }

        // suff = a_j ^ a_j+1 ^ ... ^ a_n
        // total = a_1 ^ a_2 ^ ... ^ a_n [constant]
        // suff = total ^ pref_j-1
        // thus pref ^ suff = total ^ pref ^ pref_j-1

        BitTrie btrie;
        btrie.insert(0);
        int pref = 0;

        int res = 0;
        for (int i : a) {
                pref ^= i;
                btrie.insert(pref);
                int best = btrie.getMaxXor(total ^ pref);
                res = max(res, best);
        }

        cout << res << endl;
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
