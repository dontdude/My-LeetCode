class StockSpanner {
private: 
    int index;
    stack<pair<int, int>> monoDecrStack;
public:
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        while(!monoDecrStack.empty() && monoDecrStack.top().first <= price) {
            monoDecrStack.pop();
        }

        int lastGreaterIndex = 0;
        if(!monoDecrStack.empty()) {
            lastGreaterIndex = monoDecrStack.top().second;
        } 
        index++;
        monoDecrStack.push({price, index});
        return index - lastGreaterIndex;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */