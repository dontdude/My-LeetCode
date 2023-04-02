class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        for(int& spell : spells){
            if(!spell)  continue;
            long long fact = ceil((double)success / spell); 
            int pos = lower_bound(potions.begin(), potions.end(), fact) - potions.begin();  
            spell = potions.size() - pos;
        }
        
        return spells;
    }
};