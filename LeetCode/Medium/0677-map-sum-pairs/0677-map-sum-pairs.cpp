class MapSum {
    class Trie {
        struct TrieNode {
            int sum;
            vector<TrieNode*> child;

            TrieNode() {
                sum = 0;
                child.resize(26, nullptr);
            }
        };

        TrieNode* root;
    public: 
        Trie() {
            root = new TrieNode();
        }

        void add(const string& word, int val) {
            TrieNode* node = root;

            for(const char& c : word) {
                int ind = c - 'a';
                if(node->child[ind] == nullptr) {
                    node->child[ind] = new TrieNode();
                }

                node = node->child[ind];
                node->sum += val;
            }
        } 

        int getPrefixSum(const string& prefix) {
            TrieNode* node = root;
            for(const char& c : prefix) {
                int ind = c - 'a';
                if(node->child[ind] == nullptr) return 0;

                node = node->child[ind];
            }

            return node->sum;
        }
    };

    Trie *trie;
    unordered_map<string, int> hashMap;
public:
    MapSum() {
        trie = new Trie();
    }
    
    void insert(string key, int val) {
        int diffVal = val - hashMap[key];
        hashMap[key] = val;

        trie->add(key, diffVal);
    }
    
    int sum(string prefix) {
        return trie->getPrefixSum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */