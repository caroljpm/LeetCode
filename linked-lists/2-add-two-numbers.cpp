// https://leetcode.com/problems/add-two-numbers/description/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *result = new ListNode();
        int carry = 0;

        ListNode *iter = result;
        while(l1 || l2 || carry) {
            int val = carry;
            if(l1) {
                val += l1->val;
            }
            if(l2) {
                val += l2->val;
            }

            carry = val/10;
            ListNode *n = new ListNode(val%10);
            iter->next = n;
            iter = iter->next;
            
            if(l1){
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }

        return result->next;
    }
};
