class TrieNode{
public:
    bool isWord;
    TrieNode* childNode[26];

    TrieNode() {
        isWord = false; 
        memset(childNode, 0, sizeof(childNode)); 
    }
};

class WordDictionary {
public:
    int mxword;
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
        mxword = 0;
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word){
            int idx = ch - 'a';
            if(node->childNode[idx]==NULL) node->childNode[idx] = new TrieNode();
            node = node->childNode[idx];
        }
        node->isWord = true;
        mxword = max(mxword, (int)word.size());
    }
    
    bool search(string word) {
        if(word.size() > mxword)  return false;   // optimization
        
        stack<pair<TrieNode*, int>> st;     // Iterative DFS
        st.push({root, 0});

        while(!st.empty()){
            auto call = st.top();  st.pop();
            int ind = call.second;
            TrieNode* curr = call.first;
             
            if(ind == word.size()) {
                if(curr->isWord)  return true;
                else continue;     
            }

            if(word[ind] == '.'){         // for dot, moving to any child node which is not null
                for(int i = 0; i < 26; i++){          
                    if(curr->childNode[i])  st.push({curr->childNode[i], ind + 1});
                }
            }
            else {
                int i = word[ind] - 'a';
                if(curr->childNode[i])  st.push({curr->childNode[i], ind + 1});
            }
        }

        return false;
    }
};