// https://leetcode.com/problems/subsets/description/

class Solution {
public:

    void addSubsets(vector<vector<int>> &result, vector<int> &subsets, int idx, vector<int> &nums) {
        result.emplace_back(subsets);

        for(int i=idx; i<nums.size(); i++) {
             subsets.emplace_back(nums[i]);
             addSubsets(result, subsets, i+1, nums);
             subsets.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subsets;

        addSubsets(result, subsets, 0, nums);
        return result;
    }
};
