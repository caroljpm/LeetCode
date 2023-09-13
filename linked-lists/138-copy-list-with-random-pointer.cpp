// https://leetcode.com/problems/copy-list-with-random-pointer/description/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> randomMap;
        Node *result = new Node(0);

        Node *original = head;
        Node *iter = result;

        while(head) {
            Node *n = new Node(head->val);
            iter->next = n;
            randomMap[head] = n;

            iter = iter->next;
            head = head->next;
        }

        iter = result->next;
        while(iter && original) {
          auto it = randomMap.find(original->random);
          if(it != randomMap.end()) {
              iter->random = it->second;
          }
          iter = iter->next;
          original = original->next;
        }

        return result->next;
    }
};
