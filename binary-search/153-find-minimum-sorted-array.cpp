// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
      int low=0, high = nums.size()-1;

      int res = INT_MAX;
      while(low <= high) {
          int mid = (low + high)/2;
          if(nums[low] <= nums[mid]) {
              res = std::min(res, nums[low]);
              low = mid+1;
          } else {
              res = min(res, nums[mid]);
              high = mid-1;
          }
      }

      return res;
    }
};
