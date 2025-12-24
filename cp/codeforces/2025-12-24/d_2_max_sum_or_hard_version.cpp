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

struct BitTrie {
      public:
        struct Node {
                Node *child[2];
                int cnt;
                Node( ) {
                        child[0] = child[1] = nullptr;
                        cnt = 0;
                }
        };

        Node *root;
        BitTrie( ) {
                root = new Node( );
        }

        void insert(int num) {
                Node *curr = root;
                for (int bit = 31; bit >= 0; bit--) {
                        int b = (num >> bit) & 1;
                        if (curr->child[b] == nullptr) {
                                curr->child[b] = new Node( );
                        }
                        curr = curr->child[b];
                        curr->cnt++;
                }
        }

        int getBestErase(int x) {
                Node *curr = root;
                int res = 0;
                for (int bit = 31; bit >= 0; bit--) {
                        int b = (x >> bit) & 1;
                        int want = (b == 0 ? 1 : 0);
                        int take = -1;
                        if (curr->child[want] && curr->child[want]->cnt > 0) {
                                take = want;
                        } else {
                                take = 1 - want;
                        }
                        curr = curr->child[take];
                        curr->cnt--;
                        res |= (take << bit);
                }
                return res;
        }
};

void solve( ) {
        int l, r;
        cin >> l >> r;
        vector<int> b(r - l + 1);
        iota(b.begin( ), b.end( ), l);

        auto reverseBits = [&](int x) -> int {
                int y = 0;
                for (int bit = 0; bit < 32; bit++) {
                        if (x & (1LL << bit)) y |= (1LL << (31 - bit));
                }
                return y;
        };

        BitTrie bt;
        for (int &i : b) bt.insert(reverseBits(i));
        vector<int> a = b;
        for (int &i : a) i = reverseBits(bt.getBestErase(reverseBits(i)));

        int res = 0;
        for (int i = 0; i < a.size( ); i++) res += (a[i] | b[i]);
        cout << res << endl;
        for (int &i : a) cout << i << " ";
        cout << endl;
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int testCases = 1;
        cin >> testCases;

        while (testCases--) {
                solve( );
        }

        return 0;
}
