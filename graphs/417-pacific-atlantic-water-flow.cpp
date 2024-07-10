class Solution {
    vector<vector<bool>> mVisited_pacific;
    vector<vector<bool>> mVisited_atlantic;
    int mRows;
    int mCols;
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &visited, int prev, int r, int c) {
        if(r < 0 || c < 0 || r >= mRows || c >= mCols) {
            return;
        }

        if(heights[r][c] < prev || visited[r][c]) {
            return;
        }

        visited[r][c] = true;

        dfs(heights, visited, heights[r][c], r+1, c);
        dfs(heights, visited, heights[r][c], r-1, c);
        dfs(heights, visited, heights[r][c], r, c+1);
        dfs(heights, visited, heights[r][c], r, c-1);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        mRows = heights.size();
        mCols = heights[0].size();

        mVisited_pacific = vector<vector<bool>>(mRows, vector<bool>(mCols, false));
        mVisited_atlantic = vector<vector<bool>>(mRows, vector<bool>(mCols, false));

        for(int i=0; i<mRows; i++) {
            dfs(heights, mVisited_pacific, INT_MIN, i, 0);
            dfs(heights, mVisited_atlantic, INT_MIN, i, mCols-1);
        }

        for(int i=0; i<mCols; i++) {
            dfs(heights, mVisited_pacific, INT_MIN, 0, i);
            dfs(heights, mVisited_atlantic, INT_MIN, mRows-1, i);
        }

  
        for(int i=0; i<mRows; i++) {
            for(int j=0; j<mCols; j++) {
                if(mVisited_atlantic[i][j] && mVisited_pacific[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
        
    }
};