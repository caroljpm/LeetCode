// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;
        unordered_map<string, vector<string>> groupMap;

        for(auto &str: strs) {
            string t = str;
            std::sort(t.begin(), t.end());
            groupMap[t].emplace_back(str);
        }

        for(auto &m : groupMap) {
            result.emplace_back(m.second);
        }

        return result;
        
    }
};
