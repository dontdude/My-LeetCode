class LRUCache {
private:
    class DLL {
    public:
        int key, val;
        DLL* next;
        DLL* prev;
        DLL(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
    };

    unordered_map<int, DLL*> hash;
    int cap;
    DLL *head, *tail;

    void removeNode(DLL* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAfterHead(DLL* node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

public:
    LRUCache(int capacity) : cap(capacity) {  // :variable_name(value) is a member initializer, more efficient 
        head = new DLL(-1, -1);
        tail = new DLL(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (hash.find(key) == hash.end()) return -1;

        DLL* node = hash[key];
        int val = node->val;
        removeNode(node);
        insertAfterHead(node);
        return val;
    }

    void put(int key, int value) {
        DLL* node;
        if (hash.find(key) != hash.end()) {
            node = hash[key];
            node->val = value;
            removeNode(node);
        } else {
            if (hash.size() >= cap) {
                DLL* leastNode = tail->prev;
                hash.erase(leastNode->key);
                removeNode(leastNode);
                delete leastNode;
            }

            node = new DLL(key, value);
        }

        insertAfterHead(node);
        hash[key] = node;
    }

    ~LRUCache() {   // Deconstructor
        while (head) {
            DLL* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */