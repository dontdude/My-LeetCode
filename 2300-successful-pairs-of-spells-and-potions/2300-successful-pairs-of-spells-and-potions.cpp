class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        for(int& spell : spells){
            long long fact = (success + spell - 1) / spell; 
            spell = potions.end() - lower_bound(potions.begin(), potions.end(), fact);
        }
        return spells;
    }
};