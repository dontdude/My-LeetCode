class AllOne {
    class DLL {
        struct Node {
            int freq;
            Node* prev;
            Node* next;
            unordered_set<string> keySet;

            Node(int count) {
                freq = count;
                prev = nullptr;
                next = nullptr;
            }
        };
        
        Node* head;
        Node* tail;
        unordered_map<string, Node*> nodeMap;
    public:
        DLL() {
            head = new Node(0);
            tail = new Node(0);
            head->next = tail;
            tail->prev = head;
        }

        bool isKeyPresent(string& key) {
            return nodeMap.find(key) != nodeMap.end();
        }

        void addKeyToNextOfHead(string& key) {
            addKeyToNextOfNode(key, head);
        }

        string getKeyFromTail() {
            if(tail->prev == head || tail->prev->keySet.empty()) return "";
            return *tail->prev->keySet.begin();
        }

        string getKeyFromHead() {
            if(head->next == tail || head->next->keySet.empty())  return "";
            return *head->next->keySet.begin();
        }

        void addToNextAndDeleteFromCurr(string& key) {
            Node* node = nodeMap[key];
            addKeyToNextOfNode(key, node);
            removeKeyFromNode(key, node);
        }

        void addToPrevAndDeleteFromCurr(string& key) {
            Node* node = nodeMap[key];
            addKeyToPrevOfNode(key, node);
            removeKeyFromNode(key, node);
        }

        void addKeyToNextOfNode(string& key, Node* node) {
            Node* nextNode = node->next;

            if(node->freq + 1 == nextNode->freq) {
                nextNode->keySet.insert(key);
                nodeMap[key] = nextNode;
            } else {
                Node* newNode = new Node(node->freq + 1);
                newNode->keySet.insert(key);
                nodeMap[key] = newNode;

                node->next = newNode;
                nextNode->prev = newNode;
                newNode->prev = node;
                newNode->next = nextNode;
            }
        }

        void addKeyToPrevOfNode(string& key, Node* node) {
            Node* prevNode = node->prev;
            if(node->freq == 1) {
                nodeMap.erase(key);
                return;
            }

            if(node->freq - 1 == prevNode->freq) {
                prevNode->keySet.insert(key);
                nodeMap[key] = prevNode;
            } else {
                Node* newNode = new Node(node->freq - 1);
                newNode->keySet.insert(key);
                nodeMap[key] = newNode;

                node->prev = newNode;
                prevNode->next = newNode;
                newNode->prev = prevNode;
                newNode->next = node;
            }
        }

        void removeKeyFromNode(string& key, Node* node) {
            node->keySet.erase(key);
            if(node->keySet.empty()) {
                node->next->prev = node->prev;
                node->prev->next = node->next;
            }
        }
    };

    DLL dll;
public:
    AllOne() {
    }
    
    void inc(string key) {
        if(dll.isKeyPresent(key) == false) {
            dll.addKeyToNextOfHead(key);
            return;
        }

        dll.addToNextAndDeleteFromCurr(key);
    }
    
    void dec(string key) {
        if(dll.isKeyPresent(key) == false) {
            return;
        }

        dll.addToPrevAndDeleteFromCurr(key);
    }
    
    string getMaxKey() {
        return dll.getKeyFromTail();
    }
    
    string getMinKey() {
        return dll.getKeyFromHead();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */