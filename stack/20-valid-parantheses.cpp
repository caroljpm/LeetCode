// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> bMap;
        bMap['}'] = '{';
        bMap[']'] = '[';
        bMap[')'] = '('; 

        stack<char> bStack;

        for(auto &ch: s) {
            auto it = bMap.find(ch);
            if(it == bMap.end()) {
                bStack.push(ch);
            } else {
                if(!bStack.size() || it->second != bStack.top()) {
                    return false;
                } else {
                    bStack.pop();
                }
            }
        }

        if(bStack.size()) {
            return false;
        } else {
            return true;
        }

    }
};
