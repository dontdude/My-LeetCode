class CustomStack {
    int maxSize;
    vector<int> st;
    vector<int> inc;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(maxSize == st.size()) return;
        st.push_back(x);
        inc.push_back(0);
    }
    
    int pop() {
        if(st.size() == 0)  return -1;

        int i = st.size() - 1;

        int val = st[i] + inc[i];
        if(i > 0) inc[i - 1] += inc[i];

        st.pop_back();
        inc.pop_back();

        return val;
    }
    
    void increment(int k, int val) {
        int i = min(k, (int)st.size()) - 1;

        if(i >= 0)  inc[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */