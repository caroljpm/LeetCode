// https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:

    void helper(vector<string> &result, string str, int n, int open, int closed) {
        if((open>=n) && (closed>=n)) {
            result.emplace_back(str);
            return;
        }

        if(open < n) {
            helper(result, str+"(", n, open+1, closed);
        }

        if(closed < open) {
            helper(result, str+")", n, open, closed+1);
        }

    }


    vector<string> generateParenthesis(int n) {
    
       vector<string> result;
       helper(result, "(", n, 1, 0);

       return result;
    }
};
