class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int sz = nums.size();
            bool arr[sz+1];
            for(int i = 0; i<sz+1; i++) arr[i] = 0;
            for(int i = 0; i<sz; i++){
                if(nums[i] >= 1 && nums[i]<=sz) arr[nums[i]] = true;
            }
            int ans = 0;
            for(int i = 1; i<=sz; i++){
                if(!arr[i]){
                    ans = i;
                    break;
                }
            }
    
            if(ans==0) ans = sz+1;
    
            return ans;
        }
    };