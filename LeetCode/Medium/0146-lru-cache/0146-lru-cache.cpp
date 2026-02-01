class LRUCache {
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };

    int cap, currSize;
    Node *head, *tail;
    unordered_map<int, Node*> hash;

    void insertAfterHead(Node*  node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        currSize = 0;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end()) {
            return -1;
        }

        Node* node = hash[key];
        removeNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(hash.find(key) == hash.end()) {
            Node* node = new Node(key, value);
            insertAfterHead(node);
            hash[key] = node;
            currSize++;

            if(currSize > cap) {
                Node* lru = tail->prev;
                int key = lru->key;
                removeNode(lru);
                hash.erase(key);
                delete lru;
                currSize--;
            }
        }

        Node* node = hash[key];
        removeNode(node);

        node->val = value;
        insertAfterHead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */