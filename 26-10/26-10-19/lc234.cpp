#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head)
            return false;
        ListNode *fast = head->next, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(slow)
            slow = slow->next;
        ListNode *pre = nullptr, *cur = slow;
        while(cur) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt; 
        }
        ListNode *p1 = head, *p2 = pre;
        while(p1 && p2) {
            if(p1->val != p2->val)
                return false;
            p1 = p1->next, p2 = p2->next;
        }
        return true;
    }
};