class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> minheap;

    void pushKth(int num) {
        minheap.push(num);
        if(minheap.size() > k) {
            minheap.pop();
        }
    }

    int getKth() {
        if(minheap.empty())  return -1;
        return minheap.top();
    }
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) {
            this->pushKth(num);
        }
    }
    
    int add(int val) {
        this->pushKth(val);
        return this->getKth();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */