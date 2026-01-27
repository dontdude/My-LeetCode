class LRUCache {
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
    };

    int cap;
    Node *head, *tail;
    unordered_map<int, Node*> hash;

    void insertAfterHead(Node* node) {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
public:
    LRUCache(int capacity) {
        this->cap = capacity;  

        hash.clear();

        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
       if(hash.find(key) != hash.end()) {
        Node* node = hash[key];
        removeNode(node);
        insertAfterHead(node);
        return node->val;
       } 

       return -1;
    }
    
    void put(int key, int value) {
        Node* node;
        
        if(hash.find(key) != hash.end()) {
            node = hash[key];
            removeNode(node);
            node->val = value;
        } else {
            node = new Node(key, value);
            hash[key] = node;
        }
        
        insertAfterHead(node);

        if(hash.size() > cap) {
            int lru_key = tail->prev->key;
            removeNode(tail->prev);
            hash.erase(lru_key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */