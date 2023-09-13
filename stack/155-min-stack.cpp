// https://leetcode.com/problems/min-stack/description/

class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push_front(val);
        if(!min.size()) {
            min.push_front(val);
        } else {
            int top = min.front();
            if(val < top) {
                min.push_front(val);
            } else {
                min.push_front(top);
            }
        }
    }
    
    void pop() {
        s.pop_front();
        min.pop_front();
    }
    
    int top() {
        return s.front();
    }
    
    int getMin() {
        return min.front();
    }

    list<int> s;
    list<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
