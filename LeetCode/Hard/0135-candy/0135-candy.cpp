class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n <= 1)  return 1;

        vector<int> localMinima;
        for(int i = 0; i < n; i++) {
            int prev = i > 0 ? ratings[i - 1] : INT_MAX;
            int next = i < n - 1 ? ratings[i + 1] : INT_MAX;

            if(prev >= ratings[i] && ratings[i] <= next) {
                localMinima.push_back(i);
            }
        }

        vector<int> candies(n, 1);
        for(int mini : localMinima) {
            //fill candies on left of local minima
            int previ = mini;
            int curri = mini - 1;
            while(curri >= 0 && ratings[previ] < ratings[curri]) {
                candies[curri] = max(candies[curri], candies[previ] + 1);
                
                previ = curri;
                curri--;
            }

            //fil candies on right of local minima
            previ = mini;
            curri = mini + 1;
            while(curri < n && ratings[previ] < ratings[curri]) {
                candies[curri] = max(candies[curri], candies[previ] + 1);
                
                previ = curri;
                curri++;
            }
        }

        int requiredCandies = 0;
        for(int candy : candies) {
            requiredCandies += candy;
        }

        return requiredCandies;
    }
};