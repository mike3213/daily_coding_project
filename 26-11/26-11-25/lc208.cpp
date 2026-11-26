#include <bits/stdc++.h>
using namespace std;
int main(void) {

    return 0;
}

class Trie {
private:
    struct Node {
        Node* children[26];
        bool isEnd;

        Node(): isEnd(false) {
            for(int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;

        for(char c : word) {
            int idx = c - 'a';

            if(cur->children[idx] == nullptr) {
                cur->children[idx] = new Node();
            }

            cur = cur->children[idx];
        }

        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node* cur = findPrefix(word);

        return cur != nullptr && cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        return findPrefix(prefix) != nullptr;
    }

private:
    Node* findPrefix(const string& s) {
        Node* cur = root;
        for(char c : s) {
            int idx = c - 'a';

            if(cur->children[idx] == nullptr) {
                return nullptr;
            }

            cur = cur->children[idx];
        }

        return cur;
    }
};
