class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
        while(left.empty() == false) {
            left.pop();
        }

        while(right.empty() == false) {
            right.pop();
        }
    }
    
    void addNum(int num) {
       if(left.size() <= right.size()) {
        left.push(num);
       } else {
        right.push(num);
       }

       if(right.empty() == false && left.top() > right.top()) {
        right.push(left.top());
        left.pop();

        left.push(right.top());
        right.pop();
       }
    }
    
    double findMedian() {
        if((left.size() + right.size()) & 1) {
            return (double)left.top();
        } else {
            return (double)((left.top() + right.top()) / 2.0);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */