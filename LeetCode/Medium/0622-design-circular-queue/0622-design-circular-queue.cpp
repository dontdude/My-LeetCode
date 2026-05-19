class MyCircularQueue {
    int size;
    int count;
    int front;
    int rear;
    vector<int> circularQueue;
    
public:
    MyCircularQueue(int k) {
        size = k;
        count = 0;
        front = 0;
        rear = 0;
        circularQueue.resize(k);
    }
    
    bool enQueue(int value) {
        if(front == rear && count == size) return false;
        
        circularQueue[rear] = value;
        rear = (rear + 1) % size;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(front == rear && count == 0)  return false;
        front = (front + 1) % size;
        count--;
        return true;
    }
    
    int Front() {
        if(front == rear && count == 0)  return -1;
        return circularQueue[front];
    }
    
    int Rear() {
        if(front == rear && count == 0)  return -1;
        return circularQueue[(rear - 1 + size) % size];  // negative modulo 
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */