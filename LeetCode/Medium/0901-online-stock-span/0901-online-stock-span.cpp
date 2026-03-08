class StockSpanner {
    stack<pair<int, int>> mds;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 0;
        while(mds.empty() == false && mds.top().first <= price) {
            count += mds.top().second;
            mds.pop();
        }

        mds.push({price, count + 1});

        return count + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */