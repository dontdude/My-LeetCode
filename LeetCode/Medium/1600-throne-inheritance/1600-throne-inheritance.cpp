class ThroneInheritance {
    string king;
    unordered_map<string, vector<string>> familyTree;
    unordered_set<string> dead;

    void preOrderFamilyTree(string node, vector<string>& curOrder) {
        if(dead.find(node) == dead.end()) curOrder.push_back(node);

        if(familyTree.find(node) == familyTree.end()) return;

        for(const string& successor : familyTree[node]) {
            preOrderFamilyTree(successor, curOrder);
        }
    }
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        familyTree[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> curOrder;
        preOrderFamilyTree(king, curOrder);
        return curOrder;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */