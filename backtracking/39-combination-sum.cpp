// https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
   
    void findSum(int index, vector<vector<int>> &result, vector<int> &subset, vector<int> &candidates, int target) {
        if(target == 0) {
            result.emplace_back(subset);
            return;
        } 

        if(target < 0) {
            return;
        }

        for(int i=index; i<candidates.size(); i++) {
            subset.emplace_back(candidates[i]);
            findSum(i, result, subset, candidates, target-candidates[i]);
            subset.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> subset;

        findSum(0, result, subset, candidates, target);
        return result;
    }
};
