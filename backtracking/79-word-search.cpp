// https://leetcode.com/problems/word-search/

class Solution {
public:
    
    bool traverseMatrix(int rows, int cols, int row, int col, int index, string &word, vector<vector<char>> &board) {
        if(index == word.size()) {
            return true;
        }
    
        if(row < 0 || col < 0 || row >= rows || col >= cols) {
             return false;
        }
        
        if(board[row][col] != word[index]) {
            return false;
        }
    
        char temp = board[row][col];
        board[row][col] = '*';
        bool t1 = traverseMatrix(rows, cols, row+1, col, index+1, word, board);
        bool t2 = traverseMatrix(rows, cols, row, col+1, index+1, word, board);
        bool t3 = traverseMatrix(rows, cols, row-1, col, index+1, word, board);
        bool t4 = traverseMatrix(rows, cols, row, col-1, index+1, word, board);
        board[row][col] = temp;

        return t1 || t2 || t3 || t4;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        std::cout << "Rows :" << rows << ", Cols :" << cols << std::endl;
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(traverseMatrix(rows, cols, row, col, 0, word, board)){
                    return true;
                }
            }
        }

        return false;
    }
};
