class AllOne {
    class DLL {
        struct ListNode {
            int freq;
            unordered_set<string> hashSet;
            ListNode* next;
            ListNode* prev;

            ListNode(int count) {
                freq = count;
                next = nullptr;
                prev = nullptr;
            }
        };

        ListNode *head, *tail;
        unordered_map<int, ListNode*> hashNode;
    public:
        DLL() {
            head = new ListNode(-1);
            tail = new ListNode(-1);
            head->next = tail;
            tail->prev = head;
            hashNode[-1] = head;
        }

        string getMaxFreqKey() {
            if(tail->prev->hashSet.empty()) return "";
            return *tail->prev->hashSet.begin();
        }

        string getMinFreqKey() {
            if(head->next->hashSet.empty()) return "";
            return *head->next->hashSet.begin();
        }
 
        bool isDLLNodeEmpty(int count) {
            return hashNode[count]->hashSet.empty();
        }

        void addStringToDLL(int count, string& str, int prevCount) {
            if(hashNode.find(count) != hashNode.end()) {
                hashNode[count]->hashSet.insert(str);
            } else {
                addDLLNode(count, str, prevCount);
            }
        }

        int removeStringFromDLL(int count, string& str, bool isInc) {
            hashNode[count]->hashSet.erase(str);

            int newPrevCount = isInc ? count : hashNode[count]->prev->freq;
            if(isDLLNodeEmpty(count)) {
                newPrevCount = hashNode[count]->prev->freq;
                removeDLLNode(count);
            }

            return newPrevCount;
        }

        ListNode* addDLLNode(int count, string& str, int prevCount) {
            ListNode* node = new ListNode(count);
            ListNode* prevNode = hashNode[prevCount];
            node->hashSet.insert(str);

            ListNode* nextNode = prevNode->next;
            prevNode->next = node;
            node->prev = prevNode;
            node->next = nextNode;
            nextNode->prev = node;

            hashNode[count] = node;
            return node;
        }

        void removeDLLNode(int count) { 
            ListNode* node = hashNode[count];
            ListNode* prevNode = node->prev;
            ListNode* nextNode = node->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            hashNode.erase(count);
            delete node;
        }
    };

    DLL *dll;
    unordered_map<string, int> hashMap;
public:
    AllOne() {
        dll = new DLL();
    }
    
    void inc(string key) {
        if(hashMap.find(key) == hashMap.end()) {
            dll->addStringToDLL(1, key, -1);
            hashMap[key] = 1;
            
            return;
        } 

        int prevCount = hashMap[key];
        int newPrevCount = dll->removeStringFromDLL(prevCount, key, true);
        dll->addStringToDLL(prevCount + 1, key, newPrevCount);

        hashMap[key] = prevCount + 1;
    }
    
    void dec(string key) {
        if(hashMap.find(key) == hashMap.end()) {
            return;
        } 

        int prevCount = hashMap[key];
        int newPrevCount = dll->removeStringFromDLL(prevCount, key, false);

        if(prevCount > 1)  {
            dll->addStringToDLL(prevCount - 1, key, newPrevCount);
            hashMap[key] = prevCount - 1;
        } else {
            hashMap.erase(key);
        }
    }
    
    string getMaxKey() {
        return dll->getMaxFreqKey();
    }
    
    string getMinKey() {
        return dll->getMinFreqKey();
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