#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *dummy = new ListNode(0), *fast = dummy, *slow = dummy;
        dummy->next = head;
        while(true) {
            if(slow)
                slow = slow->next;
            if(fast && fast->next)
                fast = fast->next->next;
            else
                fast = nullptr;
            if(!fast || !slow)
                return nullptr;
            if(fast == slow) {
                fast = dummy;
                while(fast != slow) {
                    if(fast)
                        fast = fast->next;
                    if(slow)
                        slow = slow->next;
                }
                return fast;
            }
        }
        
    }
};

int main(void)
{

    return 0;
}