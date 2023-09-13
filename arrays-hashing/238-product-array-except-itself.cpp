// https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int now = 1;

        if(nums.size() <= 1) {
            return nums;
        }

        vector<int> result(nums.size(), 1);
        for(int i=1; i<nums.size(); i++) {
            now = now * nums[i-1];
            result[i] = now;
        }

        now = 1;

        for(int i=nums.size()-2; i>=0; i--) {
            now = now  * nums[i+1];
            result[i] = result[i] * now;
        }

        return result;
        
    }
};
