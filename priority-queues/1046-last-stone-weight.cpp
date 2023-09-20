// https://leetcode.com/problems/last-stone-weight/description/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto &stone : stones) {
            pq.push(stone);
        }

        while(pq.size() > 1) {
            int high = pq.top();
            pq.pop();
            int low = pq.top();
            pq.pop();

            if(high != low) {
                pq.push(high-low);
            }
        }

        if(pq.size()) {
            return pq.top();
        } else {
            return 0;
        }
    }
};
