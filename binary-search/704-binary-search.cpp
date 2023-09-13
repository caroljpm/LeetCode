
//https://leetcode.com/problems/binary-search/

class Solution {
public:

    int binary_search(vector<int> &nums, int target, int low, int high) {
        while(low <= high) {
            int mid = (low + high)/2;

            if(nums[mid] == target) {
                return mid;
            } else if(target > nums[mid]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
  
        return -1;
    }

    int search(vector<int>& nums, int target) {
         return binary_search(nums, target, 0, nums.size()-1);
    }
};
