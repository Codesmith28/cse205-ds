#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class MyCalendarTwo {
  public:
    vector<pair<int, int>> events;
    vector<pair<int, int>> overlaps;

    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        for (auto &[s, e] : overlaps) {
            if (max(start, s) < min(end, e)) {
                return false;
            }
        }

        for (auto &[s, e] : events) {
            if (max(start, s) < min(end, e)) {
                overlaps.push_back({max(start, s), min(end, e)});
            }
        }

        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

int main() {
    // ["MyCalendarTwo","book","book","book","book","book","book"]
    // [[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]

    MyCalendarTwo *obj = new MyCalendarTwo();
    cout << obj->book(10, 20) << endl;
    cout << obj->book(50, 60) << endl;
    cout << obj->book(10, 40) << endl;
    cout << obj->book(5, 15) << endl;
    cout << obj->book(5, 10) << endl;
    cout << obj->book(25, 55) << endl;

    return 0;
}