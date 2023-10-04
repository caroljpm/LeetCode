// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    void findCombs(string &combs, vector<string> &result, int idx, string digits, unordered_map<char, string> &numMap) {
        if(digits.empty()) {
            return;
        }

        if(combs.size() == digits.size()) {
            result.emplace_back(combs);
            return;
        }

        string res = numMap[digits[idx]];
        std::cout << "findCombs :" << res << std::endl;  
        for(int i=0; i<res.size(); i++) {
            combs.push_back(res[i]);
            findCombs(combs, result, idx+1, digits, numMap);
            combs.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string combs;
        vector<string> result;

        unordered_map<char, string> numMap= {
            {'2', "abc"},
            {'3', "def"}, 
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        findCombs(combs, result, 0, digits, numMap);
        return result;
    }
};
