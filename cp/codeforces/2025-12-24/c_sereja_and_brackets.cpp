#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;

class SegTree {
      public:
        string s;
        int n;

        struct Node {
                int open, close, full;
                Node(int o = 0, int c = 0, int f = 0) {
                        open = o;  // unmatched open
                        close = c; // unmatched close
                        full = f;  // full valid len
                }
        };
        vector<Node> tree;

        Node merge(Node a, Node b) {
                int t = min(a.open, b.close);
                int f = 2 * t + a.full + b.full;
                int o = a.open + b.open - t;
                int c = b.close + a.close - t;
                return {o, c, f};
        }

        Node query(int node, int start, int end, int left, int right) {
                if (right < start || left > end) return {0, 0, 0};
                if (left <= start && end <= right) return tree[node];
                int mid = start + (end - start) / 2;
                Node q1 = query(2 * node, start, mid, left, right);
                Node q2 = query(2 * node + 1, mid + 1, end, left, right);
                return merge(q1, q2);
        }

        int query(int left, int right) {
                Node res = query(1, 0, n - 1, left, right);
                return res.full;
        }

        void build(int node, int start, int end) {
                if (start == end) {
                        if (s[start] == '(')
                                tree[node] = {1, 0, 0};
                        else if (s[start] == ')')
                                tree[node] = {0, 1, 0};
                        return;
                }

                int mid = start + (end - start) / 2;
                build(2 * node, start, mid);
                build(2 * node + 1, mid + 1, end);
                tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }

        SegTree(string s) {
                this->s = s;
                n = s.size( );
                tree.resize(4 * n, Node( ));
                build(1, 0, n - 1);
        }
};

void solve( ) {
        string s;
        cin >> s;
        int q;
        cin >> q;

        SegTree st(s);

        while (q--) {
                int l, r;
                cin >> l >> r;
                cout << st.query(l - 1, r - 1) << endl;
        }
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int test_cases = 1;
        // cin >> test_cases;

        while (test_cases--) {
                solve( );
        }

        return 0;
}
