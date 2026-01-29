class LFUCache {
private:
    class DLL {
    public:
        int key;
        int val;
        int freq; 
        DLL* next;
        DLL* prev;
        DLL(int _key, int _val, int _freq) : key(_key), val(_val), freq(_freq), next(NULL), prev(NULL) {}
    };

    int cap, minFreq;
    map<int,  pair<DLL*, DLL*>> freqDLL;
    map<int, DLL*> hash; 

    void createNewFreqDLL(int freq) {
        DLL* head = new DLL(-1, -1, freq);
        DLL* tail = new DLL(-1, -1, freq);
        head->next = tail;
        tail->prev = head;

        freqDLL[freq] = {head, tail};
    }

    void removeLFU() {
        auto &dllPair = freqDLL[minFreq];
        DLL* tail = dllPair.second;
        DLL* nodeToDelete = tail->prev;  // This is the least-recently used node.
        removeNode(nodeToDelete);
        hash.erase(nodeToDelete->key);
        delete nodeToDelete;
    }

    void removeNode(DLL* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        int oldFreq = node->freq;
        if (freqDLL[oldFreq].first->next == freqDLL[oldFreq].second && minFreq == oldFreq) {  // head and tail are same
           minFreq = oldFreq + 1;
        }
    }

    void insertIntoLFU(DLL* node) {
        int freq = node->freq;
        if(freqDLL.size() <= freq) {
            createNewFreqDLL(freq);
        }

        DLL* curHead = freqDLL[freq].first;
        node->next = curHead->next;
        curHead->next->prev = node;
        node->prev = curHead;
        curHead->next = node;
    }

public:
    LFUCache(int capacity) :cap(capacity), minFreq(0) {
        createNewFreqDLL(0);
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end()) {
            return -1;
        }

        DLL* node = hash[key];
        int val = node->val;

        removeNode(node);
        node->freq++;
        insertIntoLFU(node);

        return val;
    }
    
    void put(int key, int value) {
         if (cap <= 0)
            return;
        if(hash.find(key) != hash.end()) {
            DLL* node = hash[key];
            node->val = value;
            
            removeNode(node);
            node->freq++;
            insertIntoLFU(node);
        } else {
            if((int)hash.size() >= cap) {
                removeLFU();
            }

            DLL* newNode = new DLL(key, value, 0);
            hash[key] = newNode;
            minFreq = 0;
            insertIntoLFU(newNode);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */