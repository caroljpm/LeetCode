// https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n+1, 0); 
        res[0] = 1;

        for(int i=0; i<n; i++) {
            if(i+1 <= n) {
                res[i+1]+=res[i];
            }

            if(i+2 <= n) {
                res[i+2]+=res[i];
            }
        }
        
        return res[n];
    }
};