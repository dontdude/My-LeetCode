class Solution {
    class Trie {
        struct TrieNode {
            vector<TrieNode*> children;

            TrieNode() {
                children.resize(2, nullptr);
            }
        };

        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(int num) {
            TrieNode* curr = root;

            for(int i = 31; i >= 0; i--) {
                int bit = ((num >> i) & 1);

                if(curr->children[bit] == nullptr) {
                    curr->children[bit] = new TrieNode();
                }

                curr = curr->children[bit];
            }
        }

        int currNumMaxXOR(int num) {
            TrieNode* curr = root;
            int currXor = 0;

            for(int i = 31; i >= 0; i--) {
                int bit = ((num >> i) & 1);
                int oppBit = (bit ^ 1);

                if(curr->children[oppBit] != nullptr) {
                    currXor = (currXor ^ (1 << i));
                    curr = curr->children[oppBit];
                } else {
                    curr = curr->children[bit];
                }
            }

            return currXor;
        }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();

        for(int num : nums) {
            trie->insert(num);
        }

        int res = 0;
        for(int num : nums) {
            res = max(res, trie->currNumMaxXOR(num));
        }

        return res;
    }
};