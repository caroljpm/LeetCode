// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:

    void removeAlpha(string &s) {
        string t;
        for(int i=0; i<s.size(); i++) {
            bool is_alpha = ((s[i] >= 'A' && s[i] <= 'Z') ||
                            (s[i] >= 'a' && s[i] <= 'z') || 
                            (s[i] >= '0' && s[i] <= '9'));
                             
           if(is_alpha) {
               t+=tolower(s[i]);
           }
        }
        s = t;
    }

    bool isPalindrome(string s) {
        removeAlpha(s); 

        std::cout << "isPalindrome :" << s << std::endl;

        int left=0, right=s.size()-1;

        while(left < right) {
            if(s[left] != s[right])  {
                return false;
            } 
            left++;
            right--;
        } 

        return true;  
        
    }
};
