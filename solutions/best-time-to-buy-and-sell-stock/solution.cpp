class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int ans = 0;
            int sz = prices.size();
            int min_ind = 0;
            int max_ind = 0;
            for(int i = 1; i<sz; i++){
                if(prices[max_ind]<=prices[i]){
                    max_ind = i;
                }else if(prices[min_ind]>=prices[i]){
                    min_ind = i;
                }
                if(max_ind>min_ind){
                    ans = max(ans, prices[max_ind]-prices[min_ind]);
                }else{
                    max_ind = i;
                }
            }
    
            return ans;
        }
    };