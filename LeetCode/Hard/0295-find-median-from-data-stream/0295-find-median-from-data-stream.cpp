class MedianFinder {
    int n;
    priority_queue<int> minheap;
    priority_queue<int> maxheap;
public:
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        n++;
        if(maxheap.size() <= minheap.size()) {
            maxheap.push(num);
        } else {
            minheap.push(-num);
        }

        if(!maxheap.empty() && !minheap.empty() && maxheap.top() > -minheap.top()) {
            maxheap.push(-minheap.top());
            minheap.push(-maxheap.top());

            maxheap.pop();
            minheap.pop();
        }  
    }
    
    double findMedian() {
        if(n & 1) {
            return maxheap.top();
        } else {
            return (double)(maxheap.top() - minheap.top()) / 2.0; 
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */