class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
       // No special setup is needed, as the heaps are initialized by default 
    }
    
    void addNum(int num) {
        // first care about pushing the elements
        if(maxHeap.size() == minHeap.size()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // now fix the top nodes, to make sure max of left <= min of right
        if(!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            maxHeap.push(minHeap.top());  minHeap.pop();
            minHeap.push(maxHeap.top());  maxHeap.pop();
        }
    }
    
    double findMedian() {
        return maxHeap.size() > minHeap.size() 
                ? maxHeap.top() 
                : (double)(maxHeap.top() + minHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */