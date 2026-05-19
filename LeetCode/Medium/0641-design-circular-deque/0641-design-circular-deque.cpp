class MyCircularDeque {
    int size;
    int count;
    int front;
    int rear;
    vector<int> circularDq;

public:
    MyCircularDeque(int k) {
        size = k;
        count = 0;
        front = 0;
        rear = 0;
        circularDq.resize(k);
    }
    
    bool insertFront(int value) {
        if(front == rear && count == size)  return false;

        front = (front - 1 + size) % size;
        circularDq[front] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(front == rear && count == size)  return false;

        circularDq[rear] = value;
        rear = (rear + 1) % size;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(front == rear && count == 0)  return false;

        front = (front + 1) % size;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(front == rear && count == 0)  return false;

        rear = (rear - 1 + size) % size;
        count--;
        return true;
    }
    
    int getFront() {
        if(front == rear && count == 0)  return -1;

        return circularDq[front];
    }
    
    int getRear() {
        if(front == rear && count == 0)  return -1;

        return circularDq[(rear - 1 + size) % size];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return size == count;   
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */