class Solution {
    class Trie {
        struct TrieNode {
            vector<TrieNode*> children;
            int min_val;

            TrieNode() {
                children.resize(2, nullptr);
                min_val = INT_MAX;
            }
        };

        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(int num) {
            root->min_val = min(root->min_val, num);
            TrieNode* curr = root;

            for(int i = 31; i >= 0; i--) {
                int bit = ((num >> i) & 1);

                if(curr->children[bit] == nullptr) {
                    curr->children[bit] = new TrieNode();
                }

                curr = curr->children[bit];
                curr->min_val = min(curr->min_val, num);
            }
        }

        int getMaxXOR(int x, int m) {
            int minOverallInsertedInTrie = root->min_val;
            if(minOverallInsertedInTrie > m) return -1; 

            TrieNode* curr = root;
            int currMaxXor = 0;

            for(int i = 31; i >= 0; i--) {
                int bit = ((x >> i) & 1);
                int opp_bit = (bit ^ 1);

                if(curr->children[opp_bit] != nullptr && curr->children[opp_bit]->min_val <= m) {
                    currMaxXor = (currMaxXor ^ (1 << i));
                    curr = curr->children[opp_bit];
                } else {
                    curr = curr->children[bit];
                }
            }

            return currMaxXor;
        }
    };
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;

        for(int num : nums) {
            trie.insert(num);
        }

        int q = queries.size();
        vector<int> res(q);
        
        for(int i = 0; i < q; i++) {
            res[i] = trie.getMaxXOR(queries[i][0], queries[i][1]);
        }

        return res;
    }
};