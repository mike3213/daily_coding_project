#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = dummy, *second = dummy;
        while(--n >= -1) {
            first = first->next;
        } 
        while(first) {
            first = first->next;
            if(second)
                second = second->next;
        }
        if(second && second->next) {
            ListNode *p = second->next;
            second->next = second->next->next;
            delete p;
        }
        return dummy->next;
    }
};

int main(void)
{

    return 0;
}