//https://leetcode.com/problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') {
            return 0;
        }

        int len = s.length();
        vector<int> dp(len+1, 0);
        dp[0] = 1;
        dp[1] = 1;


        for (int i = 2; i <= len; ++i) {
        int one = s[i-1] - '0';
        int two = stoi(s.substr(i-2, 2));

        if(one) {
            dp[i] += dp[i-1];
        }

        if(two >=10 && two <=26) {
            dp[i] += dp[i-2];
        }
        }

        return dp[len];
    }
};