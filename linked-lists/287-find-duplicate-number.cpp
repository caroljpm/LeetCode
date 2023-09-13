// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        for(int i=0; i<nums.size(); i++) {  
            int val = abs(nums[i]);      
            if(nums[val] < 0) {
                return val;
            }

            nums[val] = nums[val] * -1;
        }

        return -1;
        
    }
};
