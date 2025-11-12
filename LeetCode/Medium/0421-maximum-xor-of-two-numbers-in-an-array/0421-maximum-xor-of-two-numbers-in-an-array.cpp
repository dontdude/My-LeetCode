struct TrieNode {
    TrieNode* children[2]; // children[0] for bit 0, children[1] for bit 1

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* curr = root;

        // Iterate from the most significant bit (31) down to 0
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; 
            
            if (curr->children[bit] == nullptr) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }

    // 3. Find max XOR using the same bitwise greedy strategy
    int getMaxXor(int num) {
        TrieNode* curr = root;
        int currentMaxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite_bit = 1 - bit;

            currentMaxXor = (currentMaxXor << 1);

            // Greedy choice: Do we have the opposite bit?
            if (curr->children[opposite_bit] != nullptr) {
                // Yes! Add 1 to the result
                currentMaxXor = (currentMaxXor | 1);
                curr = curr->children[opposite_bit];
            } else {
                // No. We are forced to take the same bit path
                curr = curr->children[bit];  // we can freely move to this because (opposite bit is already not there, so it is sure shot, this bit is there, since every number is of same length in bit wise representation here ie, 32)
            }
        }
        return currentMaxXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        
        // 1. Insert all numbers into the Trie
        for (int num : nums) {
            trie->insert(num);
        }

        int maxResult = 0;
        
        // 2. For each number, find its max XOR pair in the Trie
        for (int num : nums) {
            maxResult = max(maxResult, trie->getMaxXor(num));
        }

        return maxResult;
    }
};