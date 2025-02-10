class MinStack {
private:
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        
        if(!minSt.empty() && minSt.top() < val) {
            minSt.push(minSt.top());  // store min at each level in stack
        } else {
            minSt.push(val);
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */