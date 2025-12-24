// Problem Statement
//
// Ishaan has N friends. During his summer break, he got some free time and planned to visit his friends. All of his friend's houses are connected with the roads. All the roads connected to Ishaan's friend's house are in the form of a tree. Ishaan wants to determine that for each friend's house, what is the maximum distance to another house?
//
// Input Format
//
//     The first line contains an integer N, the total number of Ishaan's friends.
//     The second line contains an integer (N - 1) - Number of roads.
//     The third line contains an integer 2, representing that there will be 2 integers in the next N - 1 lines.
//     The next N - 1 lines contain 2 integers A and B - representing a route from A to B.
//
// Output Format
//
//     Print N integers - representing the maximum distance from the ith person's house.
//
// Constraints
//
//     1 ≤ N ≤ 200000
//     1 ≤ A , B ≤ N
//
// Evaluation Parameters
//
//     Sample Input
//
// 5
// 4
// 2
// 1 2
// 1 3
// 3 4
// 3 5
//
//     Sample Output
//
// 2
// 3
// 2
// 3
// 3﻿

#include <bits/stdc++.h>
using namespace std;

int main( ) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, dummy;
    cin >> n >> m >> dummy;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Lambda for BFS
    auto bfs = [&](int start) -> vector<int> {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        while (!q.empty( )) {
            int sz = q.size( );
            while (sz--) {
                int u = q.front( );
                q.pop( );
                for (int v : graph[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
        return dist;
    };

    // Step 1: BFS from node 1 to find farthest node A
    vector<int> dist_from_1 = bfs(1);
    int A = max_element(dist_from_1.begin( ), dist_from_1.end( )) - dist_from_1.begin( );

    // Step 2: BFS from A to get distances and find B
    vector<int> distA = bfs(A);
    int B = max_element(distA.begin( ), distA.end( )) - distA.begin( );

    // Step 3: BFS from B
    vector<int> distB = bfs(B);

    // Step 4: For each node, output max(distA[i], distB[i])
    for (int i = 1; i <= n; i++) {
        cout << max(distA[i], distB[i]) << '\n';
    }

    return 0;
}
