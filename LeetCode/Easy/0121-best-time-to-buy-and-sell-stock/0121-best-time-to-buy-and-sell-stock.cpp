class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrice = 1e4 + 1;

        for(int price : prices) {
            if(minPrice > price) {
                minPrice = price;
            } else if(maxProfit < price - minPrice) {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit;
    }
};