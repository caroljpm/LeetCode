// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void findCombSum(vector<int> &subset, vector<vector<int>> &result, vector<int> &candidates, int target,  int idx) {
        if(target == 0) {
            result.emplace_back(subset);
            return;
        }

        if(target < 0) {
            return;
        }

        for(int i=idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }

            subset.emplace_back(candidates[i]);
            findCombSum(subset, result, candidates, target-candidates[i], i+1);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        findCombSum(subset, result, candidates, target, 0);

        return result;
    }
};
