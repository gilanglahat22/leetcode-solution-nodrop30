class Solution {
    public:
        int longestValidParentheses(string s) {
            int leftCount = 0;
            int rightCount = 0;
            int sz = s.size();
            int ans = 0;
            int prevMax = 0;
            for(int i = sz-1; i>=0; i--){
                if(s[i]==')') rightCount++;
                else leftCount++;
                if(leftCount>rightCount) {
                    leftCount=0;
                    rightCount=0;
                }else if(leftCount==rightCount){
                    ans = max(ans, 2*min(leftCount, rightCount));
                }
            }
            leftCount=0;
            rightCount=0;
            for(int i = 0; i<sz; i++){
                if(s[i]==')') rightCount++;
                else leftCount++;
                if(leftCount<rightCount) {
                    leftCount=0;
                    rightCount=0;
                }else if(leftCount==rightCount){
                    ans = max(ans, 2*min(leftCount, rightCount));
                }
            }
            return ans;
        }
    };