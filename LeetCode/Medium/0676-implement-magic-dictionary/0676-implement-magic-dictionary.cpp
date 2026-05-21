class MagicDictionary {
    class Trie {
        struct TrieNode {
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

        TrieNode* getRoot() {
            return root;
        }

        void addWord(string& word) {
            TrieNode* curr = root;

            for(const char& c: word) {
                if(curr->children[c - 'a'] == nullptr) {
                    curr->children[c - 'a'] = new TrieNode();
                }

                curr = curr->children[c - 'a'];
            }

            curr->isEnd = true;
        }

        bool searchWithDiff(int diff, int index, TrieNode* curr, string& word) {
            if(index == word.size())  return curr->isEnd && diff == 0;

            bool isSubtreeSearchFound = false;

            int chIndex = word[index] - 'a';
            if(curr->children[chIndex] != nullptr) {
                isSubtreeSearchFound |= searchWithDiff(diff, index + 1, curr->children[chIndex], word);
            }

            if(diff == 1) {
                for(int i = 0; i < 26; i++) {
                    if(chIndex != i && curr->children[i] != nullptr) {
                        isSubtreeSearchFound |= searchWithDiff(diff - 1, index + 1, curr->children[i], word);
                    }
                }
            }

            return isSubtreeSearchFound;
        }
    };
    Trie* trie;
public:
    MagicDictionary() {
        trie = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string& word : dictionary) {
            trie->addWord(word);
        }
    }
    
    bool search(string searchWord) {
        int diff = 1;
        return trie->searchWithDiff(diff, 0, trie->getRoot(), searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */