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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)
            return nullptr;

        for(int len = 1; len < n; len *= 2) {
            for(int i = 0; i + len < n; i += len * 2) {
                lists[i] = merge(lists[i], lists[i + len]);
            }
        }
        return lists[0];
    }
private:
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode *dummy = new ListNode(), *pre = dummy;
        while(left && right) {
            if(left->val <= right->val) {
                pre->next = left;
                left = left->next;
            } else {
                pre->next = right;
                right = right->next;
            }
            pre = pre->next;
        }
        pre->next = left ? left : right;
        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }

};

int main(void) {


    return 0;
}