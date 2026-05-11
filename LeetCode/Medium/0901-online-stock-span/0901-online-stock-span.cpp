class StockSpanner {
    int n;
    stack<pair<int, int>> mds;
public:
    StockSpanner() {
        n = 0;
        while(!mds.empty())  mds.pop();
    }
    
    int next(int price) {
        n++;
        while(!mds.empty() && mds.top().first <= price) {
            mds.pop();
        }

        int res = n;
        if(!mds.empty())  res = n - mds.top().second;

        mds.push({price, n});
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */