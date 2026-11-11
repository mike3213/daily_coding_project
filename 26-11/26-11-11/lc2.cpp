#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){};
    ListNode(int val): val(val), next(nullptr){};
    ListNode(int val, ListNode* next): val(val), next(next){};
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(), *cur = dummy;
        int carry = 0;
        while(l1 || l2) {
            int add1 = 0, add2 = 0;
            if(l1)
                add1 = l1->val;
            if(l2)
                add2 = l2->val;
            int sum = add1 + add2 + carry;
            carry = 0;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            ListNode* p = new ListNode(sum, nullptr);
            cur->next = p;
            cur = cur->next;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry) {
            cur->next = new ListNode(1, nullptr);
        }
        return dummy->next;
    }
};

int main(void) {

    return 0;
}