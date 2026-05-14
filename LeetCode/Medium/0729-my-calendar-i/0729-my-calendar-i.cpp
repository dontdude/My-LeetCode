class MyCalendar {
    struct ListNode {
        int start;
        int end;
        ListNode* next;

        ListNode(int startTime, int endTime) {
            start = startTime;
            end = endTime;
            next = nullptr;
        }
    };

    ListNode* root;
public:
    MyCalendar() {
        root = nullptr;
    }

    void insertNewNode(int startTime, int endTime, ListNode* prev) {
        
    }
    
    bool book(int startTime, int endTime) {
        ListNode* node = root;
        ListNode* prev = nullptr;

        while(node && node->end <= startTime) {
            prev = node;
            node = node->next;
        }

        if(node == nullptr) { 
            node = new ListNode(startTime, endTime);

            if(prev) {
                prev->next = node;
            } else {
                root = node;
            }
            
            return true;
        } else {
            if(endTime <= node->start) {
                ListNode* newNode = new ListNode(startTime, endTime);
                if(prev) {
                    prev->next = newNode;
                } else {
                    root = newNode;
                }
                newNode->next = node;
                return true;
            } 
        }

        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */