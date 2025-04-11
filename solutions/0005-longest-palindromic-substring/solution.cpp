/*
 * Problem: 5. Longest Palindromic Substring
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-palindromic-substring/
 * 
 * Approach: Dynamic Programming
 * Time Complexity: O(n²), where n is the length of the string
 * Space Complexity: O(n²) for the DP table
 */

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

/*
 * Alternative Solution: Expand Around Center
 * Time Complexity: O(n²), where n is the length of the string
 * Space Complexity: O(1), only constant extra space used
 */

class AlternativeSolution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLength = 1;
        
        for (int i = 0; i < s.length(); i++) {
            // Expand around center for odd length palindromes
            expandAroundCenter(s, i, i, start, maxLength);
            
            // Expand around center for even length palindromes
            expandAroundCenter(s, i, i + 1, start, maxLength);
        }
        
        return s.substr(start, maxLength);
    }
    
private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLength) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        // Calculate length of palindrome
        int length = right - left - 1;
        
        // Update if current palindrome is longer
        if (length > maxLength) {
            maxLength = length;
            start = left + 1;
        }
    }
};