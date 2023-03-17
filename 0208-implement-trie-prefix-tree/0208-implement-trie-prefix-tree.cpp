class TrieNode {
public:
    bool isCompleteWord;
    TrieNode* childNode[26];

    TrieNode() {
        isCompleteWord = false;
        for(int i = 0; i < 26; i++)  childNode[i] = NULL;
    } 
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for(auto c : word){
            int i = c - 'a';  
            if(curr->childNode[i] == NULL){
                TrieNode* newNode = new TrieNode();
                curr->childNode[i] = newNode;
            }
            curr = curr->childNode[i];
        }
        curr->isCompleteWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto c : word){
            int i = c - 'a';
            if(curr->childNode[i] == NULL)  return false;

            curr = curr->childNode[i];
        }
        return curr->isCompleteWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto c : prefix){
            int i = c - 'a';
            if(curr->childNode[i] == NULL)  return false;

            curr = curr->childNode[i];
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