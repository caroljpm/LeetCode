//https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0, high = rows - 1;;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(target == matrix[mid][0] || target == matrix[mid][cols-1]) {
                return true;
            } else if(target > matrix[mid][0] && target < matrix[mid][cols-1]) {
                low = mid;
                break;
            } else if(target > matrix[mid][cols-1]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        if(high < low || low > high) {
            return false;
        }

        int row = low;
        low = 0, high = cols-1;
        while(low <= high) {
            int mid = (low + high) / 2;

            if(target == matrix[row][mid]) {
                return true;
            } else if(target > matrix[row][mid]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return false;
    }
};
