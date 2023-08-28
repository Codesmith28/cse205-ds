#include<bits/stdc++.h>
using namespace std;

int finder(int x, int n, vector<int> nums, int it, vector<int> curr) {

    if (x < 0) {
        return 0;
    }

    if (x == 0) {
        for (auto it : curr) {
            cout << it << " ";
        }
        cout << endl;
        return 1;
    }

    if (it > nums.size() - 1) {
        return 0;
    }

    curr.push_back(nums[it]);
    int take = finder(x - pow(nums[it], n), n, nums, it + 1, curr);

    curr.pop_back();
    int notTake = finder(x, n, nums, it + 1, curr);

    return take + notTake;
}

int main() {
    int x, n;
    cin >> x >> n;

    vector<int> nums;
    int lim = pow(x, 1.0 / n);

    vector<int> curr;

    for (int i = 1; i <= lim; i++) {
        nums.push_back(i);
    }

    cout << finder(x, n, nums, 0, curr) << endl;
    return 0;
}