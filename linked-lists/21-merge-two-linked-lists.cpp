// https://leetcode.com/problems/merge-two-sorted-lists/description/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

          ListNode *result = new ListNode();
          auto head = result;
 
          while(list1 && list2) {
              if(list1->val <= list2->val) {
                  result->next = list1;
                  list1 = list1->next;
              } else {
                  result->next = list2;
                  list2 = list2->next;
              }
              result = result->next;
          }

          if(list1) {
              result->next = list1;
          }

          if(list2) {
              result->next = list2;
          }

          return head->next;
    }
};
