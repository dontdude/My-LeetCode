class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0, s = flowerbed.size();
        for(int i = 0; i < s; i++){
            if(flowerbed[i])  continue;

            bool left = true, right = true;
            if(i && flowerbed[i-1])   left = false;
            if(i < s-1 && flowerbed[i+1])  right = false;

            if(left && right)  flowerbed[i] = 1,  count++;
        }
        return n <= count;
    }
};