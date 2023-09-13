// https://leetcode.com/problems/contains-duplicate/description/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> numMap;

        for(auto &num : nums) {
            if(numMap.find(num) != numMap.end()) {
                return true;
            }
            numMap.insert(num);
        }

        return false;

    }
};
