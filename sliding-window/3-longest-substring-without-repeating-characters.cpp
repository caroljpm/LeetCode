// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, result = 0;
        unordered_set<char> charSet;
        int tresult = 0;
        
        for(int i=0; i<s.length(); i++) {
            if(charSet.find(s[i]) == charSet.end()) {
                tresult++;
                result = max(result, tresult);
                charSet.insert(s[i]);
            } else {
                // We have found a repeat character    
                while(charSet.find(s[i]) != charSet.end()) {
                    charSet.erase(s[left]);
                    left++;
                }
                tresult = charSet.size();
                charSet.insert(s[i]);
                tresult++;
            }
        }
        
        return result;
    }
};
