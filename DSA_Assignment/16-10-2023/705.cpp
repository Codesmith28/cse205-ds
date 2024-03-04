#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class MyHashSet {
public:

    set<int> st;

    MyHashSet() {

    }

    void add(int key) {
        st.insert(key);
    }

    void remove(int key) {
        st.erase(key);
    }

    bool contains(int key) {
        return st.find(key) != st.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
*/

int main() {
    MyHashSet* obj = new MyHashSet();
    obj->add(1);
    obj->add(2);
    obj->remove(1);
    cout << obj->contains(1) << endl;
    return 0;
}