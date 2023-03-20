class Solution {
public:
    int trap(vector<int>& height) {

       // dp solution : maintaining leftmax and rightmax array
       // This is a 2 pointer solution 
    
       int left = 0, right = height.size()-1;
       int water = 0, mxleft = 0, mxright = 0;

       while(left < right){
          if(height[left] <= height[right]){   // we are going to move left
            water += max(0, mxleft - height[left]);    // since we know height[right] >= height[left], and we only move left pointer if left was smaller so, mxleft <= height[right],  so mxleft act as the wall for the water that the curr height[left have] 
            mxleft = max(mxleft, height[left++]);
          } 
          else {
            water += max(0, mxright - height[right]);
            mxright = max(mxright, height[right--]);
          }
       }

       return water;
    }
};