class KthLargest {
public:
    int kth;
    priority_queue<int, vector<int>, greater<int>> minheap;

    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (int n : nums) {
            if (minheap.size() < kth) {
                minheap.push(n);
            } else if (minheap.top() < n) {
                minheap.pop();
                minheap.push(n);
            }
        }
    }

    int add(int val) {
        if(minheap.size() < kth) {
            minheap.push(val);
        } else if (minheap.top() < val) {
            minheap.pop();
            minheap.push(val);
        }

        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */