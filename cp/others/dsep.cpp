#include <bits/stdc++.h>
using namespace std;

set<char> dsep(const vector<pair<char, char>> &edges, const set<char> &observed, char source, bool dir) {
    map<char, vector<char>> parents;
    map<char, vector<char>> children;

    for (const auto &[u, v] : edges) {
        parents[v].push_back(u);
        children[u].push_back(v);
    }

    // Phase 1:
    queue<char> q;
    set<char> ancestors;

    for (char v : observed) q.push(v);
    q.push(source);

    while (!q.empty()) {
        char curr = q.front();
        q.pop();

        if (ancestors.find(curr) == ancestors.end()) {
            for (char p : parents[curr]) q.push(p);
            ancestors.insert(curr);
        }
    }

    // Phase 2:
    set<pair<char, bool>> visited;
    set<char> reachable;

    queue<pair<char, bool>> q2; // true -> up, false -> down
    q2.push({source, dir});

    while (!q2.empty()) {
        auto [curr, d] = q2.front();
        q2.pop();

        if (observed.find(curr) == observed.end() && reachable.find(curr) == reachable.end()) {
            reachable.insert(curr);
        }

        if (visited.insert({curr, d}).second) {
            if (d) { // up
                for (char p : parents[curr]) {
                    q2.push({p, true});
                }
                if (observed.find(curr) == observed.end()) {
                    for (char c : children[curr]) {
                        q2.push({c, false});
                    }
                }
            } else { // down
                for (char c : children[curr]) {
                    q2.push({c, false});
                }
                if (ancestors.find(curr) != ancestors.end() && observed.find(curr) == observed.end()) {
                    for (char p : parents[curr]) {
                        q2.push({p, true});
                    }
                }
            }
        }
    }

    return reachable;
}

int main() {
    vector<pair<char, char>> edges = {
        {'A', 'B'},
        {'C', 'A'},
        {'C', 'D'},
        {'D', 'E'},
        {'B', 'D'}
    };

    set<char> observed = {'C'};
    char source = 'A';
    bool direction = false;

    set<char> reachable = dsep(edges, observed, source, direction);

    cout << "Reachable nodes: ";
    for (char v : reachable) {
        cout << v << ' ';
    }
    cout << endl;

    return 0;
}