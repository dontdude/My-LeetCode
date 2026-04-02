class Trie {
    struct TrieNode {
        int size;
        bool isEndOfWord;
        vector<TrieNode*> children;

        TrieNode(int n) {
            size = n;
            isEndOfWord = false;
            children.resize(size, nullptr);
        }
    };

    int n = 26;
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode(n);
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            int ind = c - 'a';
            if(curr->children[ind] == nullptr) {
                curr->children[ind] = new TrieNode(n);
            }

            curr = curr->children[ind];
        }

        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            int ind = c - 'a';
            if(curr->children[ind] == nullptr)  return false;

            curr = curr->children[ind];
        }

        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix) {
            int ind = c - 'a';
            if(curr->children[ind] == nullptr)  return false;

            curr = curr->children[ind];
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