// https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(t.length() != s.length()) {
            return false;
        } 

        std:vector<int> countVec(26);
        for(auto &ch : s) {
            countVec[ch - 97]++;
        }

        for(auto &ch : t ) {
            if(countVec[ch - 97] == 0) {
                return false;
            } else {
                countVec[ch - 97]--;
            }
        }

        return true;
    }
};
