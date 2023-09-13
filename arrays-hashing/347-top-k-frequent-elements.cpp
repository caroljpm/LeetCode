// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

         int top = INT_MIN;
         unordered_map<int, int> first,second;

         for(auto &num: nums) {
             first[num]++;
         }

         priority_queue<pair<int, int>> queue;
         for(auto &m: first) {
             queue.push(make_pair(m.second, m.first));
         }

         vector<int> result;
         for(int i=k; i>0; --i) {
             auto pair = queue.top();
             result.push_back(pair.second);
             queue.pop();
         }

         return result;
      
    }     
};
