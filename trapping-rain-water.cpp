class Solution {
    public:
        int trap(vector<int>& height) {
            int sz = height.size();
            int pembatas[sz];
            int leftMostHeight[sz];
            int rightMostHeight[sz];
            int maxLocalLeft = 0;
            leftMostHeight[0] = 0;
            int ans = 0;
            for(int i = 1; i<sz; i++){
                leftMostHeight[i] = max(height[i-1], leftMostHeight[i-1]);
            }
    
            rightMostHeight[sz-1] = 0;
            for(int i = sz-2; i>=0; i--){
                rightMostHeight[i] = max(height[i+1], rightMostHeight[i+1]);
            }
    
            for(int i = 0; i<sz; i++){
                ans += max(0, min(rightMostHeight[i], leftMostHeight[i])-height[i]);
            }
    
            return ans;
        }
    };