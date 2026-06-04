class RLEIterator {
    int index;
    int size;
    vector<int> encoded;
public:
    RLEIterator(vector<int>& encoding) {
        index = 0;
        size = encoding.size();
        encoded = encoding;
    }
    
    int next(int n) {
        while(index < size && n > encoded[index]) {
            n -= encoded[index];
            index += 2;
        }

        int val = -1;
        if(index < size) {
            encoded[index] -= n;
            val = encoded[index + 1];
        }

        return val;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */