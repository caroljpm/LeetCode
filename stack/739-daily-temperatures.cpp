// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    void helper(stack<int> &tempStack, int n, vector<int> &temperatures, vector<int> &result) {
        while(tempStack.size() > 0) {
            if(temperatures[n] >= temperatures[tempStack.top()]) {
                tempStack.pop();
            } else {
                result[n] = tempStack.top() - n;
                break;
            }
        } 
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> result(temperatures.size());
        stack<int> tempStack;

        for(int n=temperatures.size()-1; n>=0; n--) {
            if(tempStack.size() > 0) {
                helper(tempStack, n, temperatures, result);
            }
            tempStack.push(n);
        }
        return result;
    }
};
