class Solution {
    static bool sortBoxByUnits(vector<int>& a, vector<int>& b) {
        if(a[1] == b[1])  return a[0] > b[0];
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), sortBoxByUnits);

        int totalUnits = 0;
        for(vector<int>& boxType : boxTypes) {
            int boxes = boxType[0];
            int units = boxType[1];

            if(truckSize <= boxes) {
                totalUnits += truckSize * units;
                truckSize = 0;
                break;
            } else {
                totalUnits += boxes * units;
                truckSize -= boxes;
            }
        }

        return totalUnits;
    }
};

