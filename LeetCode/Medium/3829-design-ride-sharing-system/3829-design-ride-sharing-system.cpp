class RideSharingSystem {
    class RiderList {
        struct Node {
            int val;
            Node* next;
            Node* prev;

            Node(int riderId) {
                val = riderId;
                next = nullptr;
                prev = nullptr;
            }
        };

        Node* head;
        Node* current;
        unordered_map<int, Node*> hashMap;
    public:
        RiderList() {
            head = new Node(-1);
            current = head;
        }

        bool isEmptyList() {
            return hashMap.empty();
        }

        void addNode(int riderId) {
            if(hashMap.find(riderId) != hashMap.end())  return;

            Node* newRiderNode = new Node(riderId);
            current->next = newRiderNode;
            newRiderNode->prev = current;
            current = newRiderNode;

            hashMap[riderId] = newRiderNode;
        }

        int getLatest() {
            if(hashMap.empty())  return -1;

            int latestRiderId = head->next->val;
            removeNode(latestRiderId);
            return latestRiderId;
        }

        void removeNode(int riderId) {
            if(hashMap.find(riderId) == hashMap.end())  return;

            Node* removeRiderNode = hashMap[riderId];
            Node* prevNode = removeRiderNode->prev;

            prevNode->next = removeRiderNode->next;
            if(removeRiderNode->next) removeRiderNode->next->prev = prevNode;

            if(current == removeRiderNode) current = prevNode;

            hashMap.erase(riderId);
            delete removeRiderNode;
        }
    };

    RiderList* riderList;
    queue<int> driverList;
public:
    RideSharingSystem() {
        riderList = new RiderList();
    }
    
    void addRider(int riderId) {
        riderList->addNode(riderId);
    }
    
    void addDriver(int driverId) {
        driverList.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(riderList->isEmptyList() || driverList.empty()) return {-1, -1};
        
        int driverId = driverList.front();
        driverList.pop();
        int riderId = riderList->getLatest();

        return {driverId, riderId};
    }
    
    void cancelRider(int riderId) {
       riderList->removeNode(riderId); 
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */