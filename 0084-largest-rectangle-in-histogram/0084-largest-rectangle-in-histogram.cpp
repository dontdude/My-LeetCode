class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int res = 0; 
        int n = arr.size();
        int l[n], r[n]; 
        stack<int> lg, rg; 
        
        l[0] = -1;   lg.push(0);
        r[n-1] = n;  rg.push(n-1);
        
        for(int i = 1; i < n; i++)
        {  
            while(!lg.empty() && arr[lg.top()] >= arr[i])
            {          lg.pop();                        }
            
            l[i] = lg.empty() ? -1 : lg.top();
            
            lg.push(i); 
        }
        
        for(int i = n-2; i >= 0; i--)
        {  
            while(!rg.empty() && arr[rg.top()] >= arr[i])
            {          rg.pop();                        }
            
            r[i] = rg.empty() ? n : rg.top();
            
            rg.push(i); 
        }
        
        for(int i = 0; i < n; i++)
        {  // cout<<arr[i]<<" "<<l[i]<<" "<<r[i]<<"\n"; 
            int curr = (r[i]-l[i] - 1)*arr[i]; 
            res = max(curr, res); 
        }
     return(res); 
    }
};