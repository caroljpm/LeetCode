// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        unordered_map<int, int> numSet;
        for(int i=0; i<numbers.size(); i++) {
             auto it = numSet.find(target - numbers[i]);
             if(it == numSet.end()) {
                 numSet[numbers[i]] = i;
             } else {
                return {it->second+1, i+1};
             }
        }
        
        return {};
    }
};
