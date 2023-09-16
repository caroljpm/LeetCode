// https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int characterReplacement(string s, int k) {
       int left=0, maxRepeat=0, result=0;
       unordered_map<char, int> count;

       for(int i=0;i<s.length(); i++) {
           count[s[i]]++;
           maxRepeat = max(maxRepeat, count[s[i]]);

           int window_size=i-left+1;
           if(window_size - maxRepeat > k) {
               count[s[left]]--;
               left++;
           }

           result = max(result, (i-left+1));
       }

       return result;
    }
};
