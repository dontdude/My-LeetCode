class CombinationIterator {
    string original;
    vector<int> combination;
    bool hasNextCombination;
public:
    CombinationIterator(string characters, int combinationLength) {
        original = characters;

        combination.resize(combinationLength);
        for(int i = 0; i < combinationLength; i++) {
            combination[i] = i;
        }

        hasNextCombination = true;
    }
    
    string next() {
        int m = original.size(), n = combination.size();

        string result = "";
        for(int k = 0; k < n; k++) {
            result.push_back(original[combination[k]]);
        }

        int i = n - 1, j = m - 1;
        while(i > 0) {
            if(combination[i] < j) {
                break;
            }

            i--;
            j--;
        }

        if(i == 0 && combination[i] == m - n) {
            hasNextCombination = false;
            return result;
        }

        combination[i]++;
        for(int k = i + 1; k < n; k++) {
            combination[k] = combination[k - 1] + 1;
        }

        return result;
    }
    
    bool hasNext() {
        return hasNextCombination;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */