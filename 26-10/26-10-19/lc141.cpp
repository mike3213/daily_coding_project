#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy, *slow = dummy;
        while(fast && slow) {
            fast = fast->next;
            if(fast)
                fast = fast->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }    
        if(fast == NULL)
            return false;
        else
            return true;
    }
};