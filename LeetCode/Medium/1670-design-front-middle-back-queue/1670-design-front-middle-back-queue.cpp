class FrontMiddleBackQueue {
    struct ListNode {
        int data;
        ListNode* prev;
        ListNode* next;

        ListNode(int val) {
            data = val;
            prev = nullptr;
            next = nullptr; 
        }
    };

    int size;
    ListNode* head;
    ListNode* tail;

    void insertAfter(ListNode* prevNode, ListNode* insertNode) {
        ListNode* nextNode = prevNode->next;

        insertNode->next = nextNode;
        insertNode->prev = prevNode;

        prevNode->next = insertNode;
        nextNode->prev = insertNode;
    }

    int removeNode(ListNode* node) {
        ListNode* prevNode = node->prev;
        ListNode* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        int val = node->data;
        delete node;

        return val;
    }

    ListNode* getMiddle() {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
public:
    FrontMiddleBackQueue() {
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void pushFront(int val) {
        ListNode* node = new ListNode(val);
        insertAfter(head, node);
        size++;
    }
    
    void pushMiddle(int val) {
        ListNode* node = new ListNode(val);
        ListNode* mid = getMiddle();

        if(size & 1) {
            insertAfter(mid->prev, node);
        } else {
            insertAfter(mid, node);
        }

        size++;
    }
    
    void pushBack(int val) {
        ListNode* node = new ListNode(val);
        insertAfter(tail->prev, node);
        size++;
    }
    
    int popFront() {
        if(head->next == tail)  return -1;
        size--;
        return removeNode(head->next);
    }
    
    int popMiddle() {
        if(head->next == tail)  return -1;
        size--;
        ListNode* mid = getMiddle();
        return removeNode(mid);
    }
    
    int popBack() {
        if(head->next == tail)  return -1;
        size--;
        return removeNode(tail->prev);
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */