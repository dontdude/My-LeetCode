class Trie {
    struct TrieNode {
        map<char, TrieNode*> childMap;
        bool isEnd;

        TrieNode() {
            isEnd = false;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();    
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for(char ch : word) {
            if(curr->childMap[ch] == NULL) {
              curr->childMap[ch] = new TrieNode;
            }
            curr = curr->childMap[ch];
        }

        curr->isEnd  = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for(char ch : word) {
            if(curr->childMap[ch] == NULL) {
              return false;
            }
            curr = curr->childMap[ch];
        }

        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(char ch : prefix) {
            if(curr->childMap[ch] == NULL) {
              return false;
            }
            curr = curr->childMap[ch];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */