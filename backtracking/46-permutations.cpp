// https://leetcode.com/problems/permutations/description/

class Solution {
public:

    void calculatePermutations(vector<int> &nums, int idx, vector<vector<int>> &result) {
        if(idx >= nums.size()) {
            result.emplace_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++) {
             swap(nums[idx], nums[i]);
             calculatePermutations(nums, idx+1, result);
             swap(nums[idx], nums[i]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        calculatePermutations(nums, 0, result);

        return result;
    }
};
