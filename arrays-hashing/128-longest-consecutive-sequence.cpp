// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
    
    if(nums.size() <= 0) {
        return 0;
    }

    int longest = 1;
    unordered_set<int> numSet;
    for(auto &num: nums) {
        numSet.insert(num);
    }

    for(auto &num: nums) {
        if(numSet.find(num-1) == numSet.end()) {
            int len=1;
            for(int i=num+1;; i++) {
                if(numSet.find(i) != numSet.end()) {
                    len++;
                } else {
                    break;
                }
            }

            longest = max(len, longest);
        }
    }
    return longest;
    }
};
