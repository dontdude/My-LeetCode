class ProductOfNumbers {
    vector<int> streamPrd;
    int lastZeroPos = -1;
public:
    ProductOfNumbers() { 
        streamPrd.push_back(1);   
    }
    
    void add(int num) {
        if(num == 0) {
            lastZeroPos = streamPrd.size();
            streamPrd.push_back(1);
            return;
        }

        streamPrd.push_back(streamPrd.back() * num);
    }
    
    int getProduct(int k) {
        int n = streamPrd.size() - 1;

        if(lastZeroPos > n - k)  return 0;
        
        return streamPrd[n] / streamPrd[n - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */