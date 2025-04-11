class Solution {
    public:
        string longestPalindrome(string s) {
            int sz = s.length();
    
            // Create a DP table to store whether s[i..j] is a palindrome
            vector<vector<bool>> dp(sz, vector<bool>(sz, false));
    
            // Every single character is a palindrome
            for (int i = 0; i < sz; i++) {
                dp[i][i] = true;
            }
    
            int left = 0;
            int right = 0;
    
            // Check for palindromes of length 2
            for (int i = 0; i < sz - 1; i++) {
                if (s[i] == s[i + 1]) {
                    dp[i][i + 1] = true;
                    left = i;
                    right = i + 1;
                }
            }
    
            // Check for palindromes of length greater than 2
            for (int len = 3; len <= sz; len++) {
                for (int i = 0; i <= sz - len; i++) {
                    int j = i + len - 1;  // Ending index of the current substring
    
                    // Check if the current substring is a palindrome
                    if (dp[i + 1][j - 1] && s[i] == s[j]) {
                        dp[i][j] = true;
    
                        // Update the longest palindrome indices
                        if (len > (right - left + 1)) {
                            left = i;
                            right = j;
                        }
                    }
                }
            }
    
            // Construct the longest palindrome substring
            string ans = s.substr(left, right - left + 1);
            return ans;
        }
    };