#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class MyHashMap {
public:

    vector<int> mp;

    MyHashMap() {
        int k = 1e6 + 1;
        mp.resize(k);
        fill(mp.begin(), mp.end(), -1);
    }
    //  Removes the value key in the H
    void put(int key, int value) {
        mp[key] = value;
    }

    int get(int key) {
        return mp[key];
    }

    void remove(int key) {
        mp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    MyHashMap mhmp;
    return 0;
}