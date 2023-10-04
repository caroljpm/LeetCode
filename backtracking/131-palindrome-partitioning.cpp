// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
   
    bool checkPalindrome(string &s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
    void findPartitions(vector<string> &partition, vector<vector<string>> &result, string s, int idx) {
        if(idx == s.size()) {
            result.emplace_back(partition);
            return;
        }

        for(int i=idx; i<s.size(); i++) {
            if(checkPalindrome(s, idx, i)) {
                partition.emplace_back(s.substr(idx, i-idx+1));
                findPartitions(partition, result, s, i+1);
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> partition;

        findPartitions(partition, result, s, 0);
        return result;      
    }
};
