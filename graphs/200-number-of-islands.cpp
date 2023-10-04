// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:

    void checkIslands(int rows, int cols, int r, int c, vector<vector<char>> &grid) {
        if(r < 0 || c < 0 || r >= rows || c >= cols) {
            return;
        }

        if(grid[r][c] == '*' || grid[r][c] == '0') {
            return;
        }

        if(grid[r][c]) {
            grid[r][c] = '*';
            checkIslands(rows, cols, r+1, c, grid);
            checkIslands(rows, cols, r, c+1, grid);
            checkIslands(rows, cols, r-1, c, grid);
            checkIslands(rows, cols, r, c-1, grid);

            return;
        }

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i=0; i<rows; i++)  {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    checkIslands(rows, cols, i, j, grid);
                }
            }
        }

        return islands;
    }
};
