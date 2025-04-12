class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int sz = prices.size();
            int ans = 0;
            int min_ind = 0;
            int max_ind = 0;
            int max_diff_local = 0;
            for(int i = 1; i<sz; i++){
                if(prices[min_ind]>=prices[i]){
                    min_ind = i;
                }else if(prices[max_ind]<=prices[i]){
                    max_ind = i;
                }
    
                if(max_ind<=min_ind){
                    max_ind = i;
                }else{
                    max_diff_local = max(max_diff_local, prices[max_ind]-prices[min_ind]);
                }
    
                if(prices[max_ind] >= prices[i]){
                    ans += max_diff_local;
                    max_ind = i;
                    min_ind = i;
                    max_diff_local = 0;
                }
            }
            return ans;
        }
    };