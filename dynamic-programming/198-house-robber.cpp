// https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if(size == 0) {
            return 0;
        }

        if(size == 1) {
            return nums[0];
        }

        if(size == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> dp(size, 0);
        dp[0] = max(nums[0], nums[size-1]);
        dp[1] = max(nums[0], nums[1] + nums[size-1]);

        for(int i=2; i<size; i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        return dp[size-1];
        
    }
};