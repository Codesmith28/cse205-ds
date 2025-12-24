#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct TrieNode {
    TrieNode *child[26];
    bool isEnd; // word ended

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

void insert(TrieNode *root, string key) {
    TrieNode *temp = root;
    for (char c : key) {
        int idx = c - 'a';
        if (!temp->child[idx]) {
            temp->child[idx] = new TrieNode();
        }
        temp = temp->child[idx];
    }
    temp->isEnd = true;
}

bool search(TrieNode *root, string key) {
    TrieNode *temp = root;
    for (char c : key) {
        int idx = c - 'a';
        if (!temp->child[idx]) {
            return false;
        }
        temp = temp->child[idx];
    }
    return temp->isEnd;
}

int main() {
    return 0;
}
