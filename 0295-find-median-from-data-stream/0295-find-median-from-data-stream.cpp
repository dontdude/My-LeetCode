class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
       // No special setup is needed, as the heaps are initialized by default 
    }
    
    void addNum(int num) {
        int n = maxHeap.size(), m = minHeap.size();
        if(n == m && n == 0) {
           maxHeap.push(num);
        } else if(n > m) {  // trying to push to right half
            if(num < maxHeap.top()) {  // whether new element is greater than max of left half
                minHeap.push(maxHeap.top());   // moving the current max of left half to right half
                maxHeap.pop();
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
        } else {
            if(num > minHeap.top()) {
                maxHeap.push(minHeap.top());  
                minHeap.pop();
                minHeap.push(num);
            } else {
                maxHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        int n = maxHeap.size(), m = minHeap.size();
        if(n == m && n == 0) {
            return 0;
        } else if(n == m) {
            return (double)(maxHeap.top() + minHeap.top()) / 2;
        } else if(n > m) {
            return (double)maxHeap.top();
        } else {
            return (double)minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */