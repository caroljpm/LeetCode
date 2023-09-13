// https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {

        int result = INT_MIN;
        int left = 0, right = height.size()-1;

        while(left < right) {
            result = max(result, (right-left) * min(height[left], height[right]));

            if(height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return result;
    }
};
