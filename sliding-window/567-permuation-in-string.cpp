// https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length()) {
            return false;
        }

        vector<int> countS1(26, 0), countS2(26, 0);
        for(int i=0;i <s1.size(); i++) {
            countS1[s1[i]-'a']++;
            countS2[s2[i]-'a']++;
        }

        if(countS1 == countS2) {
            return true;
        }

        for(int i=s1.size(), j=0; i<s2.size(); i++, j++) {
            countS2[s2[i] - 'a']++;
            countS2[s2[j] - 'a']--;

            if(countS1 == countS2) {
                return true;
            }
        }

        return false;
    }
};
