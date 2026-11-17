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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *groupPre = dummy;
        while(true) {
            ListNode *kth = groupPre;
            for(int i = 0; i < k && kth; ++i) {
                kth = kth->next;
            }
            if(!kth) {
                break;
            } else {
                ListNode *groupNext = kth->next;

                ListNode *cur = groupPre->next;
                ListNode *pre = groupNext;

                while(cur != groupNext) {
                    ListNode *p = cur->next;
                    cur->next = pre;
                    pre = cur;
                    cur = p;
                }

                ListNode *p = groupPre->next;
                groupPre->next = kth;
                groupPre = p;
            }
        }
        return dummy->next;        
    }
};


int main(void) {


}