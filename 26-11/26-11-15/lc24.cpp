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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        while(pre->next && pre->next->next) {
            ListNode *p = pre->next;
            pre->next = p->next;
            p->next = p->next->next;
            pre->next->next = p;
            
            pre = p;
        }
        return dummy->next;
    }
};

int main(void) {

    return 0;
}