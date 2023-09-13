// https://leetcode.com/problems/reorder-list/description/

class Solution {
public:

    ListNode* middle(ListNode *head) {
        ListNode *slow=head, *fast=head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode *head) {
        ListNode *prev=nullptr, *next=nullptr;

        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        if(!head || !head->next) {
            return;
        }

        ListNode *mid = middle(head);
        ListNode *right = reverse(mid->next);
        mid->next = nullptr;
    
        ListNode *first = head; 
        ListNode *second = right;
        ListNode *next1 = nullptr;
        ListNode *next2 = nullptr;

        while(second) {
            next1 = first->next;
            next2 = second->next;

            first->next = second;
            second->next = next1;

            first = next1;
            second = next2;
        }
    }
};
