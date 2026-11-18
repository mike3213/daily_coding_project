#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if()
    }
private:
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode *dummy = new ListNode(), *cur = dummy;
        while(left && right) {
            if(left->val <= right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        cur->next = left ? left : right;
        ListNode *head = dummy->next;
        delete dummy;

        return head; 
    }
};

int main(void) {


    return 0;
}