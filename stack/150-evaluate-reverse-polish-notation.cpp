// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    
    int calculate(int left, int right, string &op) {
        if(op == "+") {
            return left + right;
        } else if(op == "-") {
            return left - right;
        } else if(op == "*") {
            return left * right;
        } else {
            return left/right;
        }
    }

    int evalRPN(vector<string>& tokens) {

        stack<int> st;
        int result = INT_MIN;
        for(auto &token : tokens) {
             if (token == "+" || token == "-" || token == "*" || token == "/"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();

                result = calculate(first, second, token);
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};
