class Solution {
    class Trie {
        struct TrieNode {
            bool isEnd;
            vector<TrieNode*> child;

            TrieNode() {
                isEnd = false;
                child.resize(26, nullptr);
            }
        };

        TrieNode* root;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
    public:
        vector<string> result;
        Trie() {
            root = new TrieNode();
        }

        void add(string word) {
            TrieNode* curr = root;

            for(const char& c : word) {
                if(curr->child[c - 'a'] == nullptr) {
                    curr->child[c - 'a'] = new TrieNode();
                }

                curr = curr->child[c - 'a'];
            }

            curr->isEnd = true;
        }

        void traverseAll(vector<vector<char>>& board, int m, int n) {
            string path = "";
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    dfs(i, j, m, n, board, path, root);
                }
            }
        }

        void dfs(int i, int j, int m, int n, vector<vector<char>>& board, string& path, TrieNode* curr) {
            char c = board[i][j];
            if(curr->child[c - 'a'] == nullptr)  return;
            
            curr = curr->child[c - 'a'];
            board[i][j] = '.';
            path.push_back(c);

            if(curr->isEnd == true) {
                result.push_back(path);
                curr->isEnd = false;  // to make sure, one string considered in result only 1 time
            }
            
            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if((x >= 0 && x < m) && (y >= 0 && y < n) && board[x][y] != '.') {
                    dfs(x, y, m, n, board, path, curr);
                }
            }

            board[i][j] = c;
            path.pop_back();
        }
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        int m = board.size(), n = board[0].size();

        for(const string& word : words) {
            trie.add(word);
        }

        trie.traverseAll(board, m, n);

        return trie.result;
    }
};