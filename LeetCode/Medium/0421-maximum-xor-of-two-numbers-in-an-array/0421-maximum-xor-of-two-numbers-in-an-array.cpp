class Solution {
    class Trie {
        struct TrieNode {
            vector<TrieNode*> bits;

            TrieNode() {
                bits.resize(2, nullptr);
            }
        };
        
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        void addNumToTrie(int num) {
            TrieNode* curr = root;

            for(int i = 31; i >= 0; i--) {  // why msb is placed on trie node tree first, because when we process it.. we want the msb first to process, so that if we try to get 1 in inital phases of traversal we are sure shot it will be best answer.
                int bit = 0;
                if(num & (1 << i)) {
                    bit  = 1;
                }

                if(curr->bits[bit] == nullptr) {
                    curr->bits[bit] = new TrieNode();
                }

                curr = curr->bits[bit];
            }
        }

        void findMaxXor(TrieNode* node1, TrieNode* node2, int i, int curr, int& res) {
            if(node1 == nullptr || node2 == nullptr || i < 0) {
                res = max(res, curr);
                return;
            }

            int bit = 0, oppbit = 1;
            int newCurr = (curr ^ (1 << i));

            if(node1->bits[bit]) {
                if(node2->bits[oppbit]) {
                    findMaxXor(node1->bits[bit], node2->bits[oppbit], i - 1, newCurr, res);
                } else {
                    findMaxXor(node1->bits[bit], node2->bits[bit], i - 1, curr, res);
                }
            }

            if(node1->bits[oppbit]) {
                if(node2->bits[bit]) {
                    findMaxXor(node1->bits[oppbit], node2->bits[bit], i - 1, newCurr, res);
                } else {
                    findMaxXor(node1->bits[oppbit], node2->bits[oppbit], i - 1, curr, res);
                }
            }
        }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        for(const int& num : nums) {
            trie->addNumToTrie(num);
        }

        int res = 0;
        trie->findMaxXor(trie->root, trie->root, 31, 0, res);

        return res;
    }
};