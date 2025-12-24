#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indeg;

        for (int i = 0; i < n; i++) {
            for (char c : dict[i]) {
                indeg[c] = 0;
            }
        }

        auto recur = [&](string a, string b, int idx, auto &&recur) -> void {
            if (idx >= a.size() or idx >= b.size()) return;
            if (a[idx] != b[idx]) {
                adj[a[idx]].push_back(b[idx]);
                indeg[b[idx]]++;
                return;
            }
            recur(a, b, idx + 1, recur);
        };

        for (int i = 0; i < n - 1; i++) {
            recur(dict[i], dict[i + 1], 0, recur);
        }

        queue<char> q;
        string res;

        for (auto &it : indeg) {
            if (it.second == 0) q.push(it.first);
        }

        while (!q.empty()) {
            char x = q.front();
            q.pop();
            res += x;

            for (char it : adj[x]) {
                indeg[it]--;
                if (indeg[it] == 0) {
                    q.push(it);
                }
            }
        }

        return (res.size() != k) ? "0" : res;
    }
};

int main() {
    vector<int> n = {5, 3};
    vector<int> k = {4, 3};
    vector<string> dict[] = {
        {"baa", "abcd", "abca", "cab", "cada"},
        {"caa", "aaa", "aab"},
    };

    Solution s;

    for (int i = 0; i < n.size(); i++) {
        string dictArr[dict[i].size()];
        for (int j = 0; j < dict[i].size(); j++) {
            dictArr[j] = dict[i][j];
        }
        cout << s.findOrder(dictArr, n[i], k[i]) << endl;
    }
    return 0;
}