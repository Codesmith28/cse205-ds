#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct SegTree {
    vector<int> tree;
    int n;

    SegTree(int sz) {
        n = sz;
        tree.resize(4 * n, 0);
    }

    void build(vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, left, right);
        int p2 = query(2 * node + 1, mid + 1, end, left, right);
        return p1 + p2;
    }
};

class MyCalendarThree {
  public:
    SegTree *tree;

    MyCalendarThree() {
    }

    int book(int startTime, int endTime) {
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */

int main() {
    MyCalendarThree *obj = new MyCalendarThree();
    cout << obj->book(10, 20) << endl;
    cout << obj->book(50, 60) << endl;
    cout << obj->book(10, 40) << endl;
    cout << obj->book(5, 15) << endl;
    cout << obj->book(5, 10) << endl;
    cout << obj->book(25, 55) << endl;
    return 0;
}