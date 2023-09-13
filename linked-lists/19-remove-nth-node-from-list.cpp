// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *left=dummy, *right=head;
  
        while(n>0 && right) {
            right = right->next;
            n--;
        }

        while(left && right) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy->next;        
    }
};
