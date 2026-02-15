class StockSpanner {
    int index;
    stack<pair<int, int>> mis;  // monotonic increasing stack, {stock value, index}
public:
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        while(mis.empty() == false && mis.top().first <= price) {
            mis.pop();
        }

        int lastBiggerElemIndex = -1;
        if(mis.empty() == false) {
            lastBiggerElemIndex = mis.top().second;
        }

        int stockSpan = index - lastBiggerElemIndex;

        mis.push({price, index}); // first stock has 0 index
        index++;

        return stockSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */