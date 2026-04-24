class WordDictionary {
    class Trie {
        struct TrieNode{
            bool isEnd;
            vector<TrieNode*> children;

            TrieNode() {
                isEnd = false;
                children.resize(26, nullptr);
            }
        };
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }

        TrieNode* getTrieRoot() {
            return root;
        }

        void add(string& word) {
            TrieNode* node = root;

            for(char c: word) {
                int index = c - 'a';
                if(node->children[index] == nullptr) {
                    node->children[index] = new TrieNode();
                }

                node = node->children[index];
            }

            node->isEnd = true;
        }

        bool dfs(string& word, int ind, TrieNode* node) {
            if(ind == word.size())  return node->isEnd;

            char c = word[ind];

            if(c == '.') {
                for(int i = 0; i < 26; i++) {
                    if(node->children[i]) {
                        if(dfs(word, ind + 1, node->children[i]))  return true;
                    }
                }
            } else if(node->children[c - 'a']) {
                if(dfs(word, ind + 1, node->children[c - 'a']))  return true;
            }

            return false;
        }
    };

    Trie* trie;
public:
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->add(word);
    }
    
    bool search(string word) {
        return trie->dfs(word, 0, trie->getTrieRoot());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */