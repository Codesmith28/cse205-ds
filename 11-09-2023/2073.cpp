#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        queue<int> que;

        for (int i = 0; i < tickets.size(); i++) {
            // storing idx for reference:
            que.push(i);
        }

        while (true) {
            if (tickets[k] == 0) {
                break;
            }

            int idx = que.front();
            time++;
            tickets[idx]--;

            que.pop();
            if (tickets[idx] != 0) {
                que.push(idx);
            }
        }

        return time;
    }

    // iteratively:
    // int timeRequiredToBuy(vector<int>& tickets, int k) {
    //     int count = 0, idx = 0;

    //     while(tickets[k] != 0) {
    //         if(idx == tickets.size()) {
    //             idx = 0;
    //         }

    //         if(tickets[idx] == 0) {
    //             idx++;
    //             continue;
    //         } else {
    //             tickets[idx]--;
    //             count++;
    //             idx++;
    //         }
    //     }

    //     return count;
    // }
};

int main()
{
    Solution sol;
    vector<int> tickets = { 2,6,3,4,5 };
    int k = 2;

    cout << sol.timeRequiredToBuy(tickets, k) << endl;

    return 0;
}