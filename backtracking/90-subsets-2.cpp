// https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    void findSubsets(vector<int> &subset, vector<int> &nums, vector<vector<int>> &result, int idx) {
        result.emplace_back(subset);

         for(int i=idx; i<nums.size(); i++) {
             if(i>idx && nums[i] == nums[i-1]) {
                 continue;
             }
             subset.emplace_back(nums[i]);
             findSubsets(subset, nums, result, i+1);
             subset.pop_back();
         }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        sort(nums.begin(), nums.end());
        findSubsets(subset, nums, result, 0);
        return result;      
    }
};
