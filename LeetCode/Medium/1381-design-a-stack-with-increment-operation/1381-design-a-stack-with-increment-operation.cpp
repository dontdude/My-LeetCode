class CustomStack {
    int size;
    stack<int> mainSt, helperSt;
public:
    CustomStack(int maxSize) {
       size = maxSize; 
    }
    
    void push(int x) {
        if(mainSt.size() == size) return;
        mainSt.push(x);
    }
    
    int pop() {
        if(mainSt.size() == 0)  return -1;

        int val = mainSt.top();
        mainSt.pop();

        return val;
    }
    
    void increment(int k, int val) {

        int skipped = mainSt.size() >= k ? mainSt.size() - k : 0;

        while(skipped--) {
            helperSt.push(mainSt.top());
            mainSt.pop();
        }

        while(!mainSt.empty()) {
            helperSt.push(mainSt.top() + val);
            mainSt.pop();
        }

        while(!helperSt.empty()) {
            mainSt.push(helperSt.top());
            helperSt.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */