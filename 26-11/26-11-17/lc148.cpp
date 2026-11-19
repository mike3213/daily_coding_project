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
        if(head || head->next) {
            return head;
        }
        ListNode *dummy =  new ListNode(0, head);
        ListNode *pre = dummy;
        for(int len = 1; ; len *= 2) {
            ListNode *cur = head;
            for(int i = 0; ; i += len * 2) {
                ListNode *left = cur, *right = split(left, len);
                cur = split(right, len);
                pre->next = merge(left, right);
                while(pre->next) {
                    pre = pre->next;
                }
            }
        }
        return dummy->next;
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

    ListNode *split(ListNode *left, int n) {
        ListNode *cur = left;
        while(--n) {
            if(cur->next)
                cur = cur->next;
            else
                break;
        }
        cur->next = nullptr;
        return left;
    }
};

int main(void) {


    return 0;
}