#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *p = head;
        while(p) {
            Node *node = new Node(0);
            node->val = p->val;
            node->next = p->next;
            p->next = node;
            p = p->next->next;
        }
        p = head;
        while(p) {
            Node *copy = p->next;
            copy->random = p->random == nullptr ? nullptr : p->random->next;
            p = p->next->next;
        }
        Node *dummy = new Node(0), *cur = dummy;
        p = head;
        while(p) {
            cur->next = p->next;
            p->next = p->next->next;
            p = p->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};

int main(void) {


    return 0;
}