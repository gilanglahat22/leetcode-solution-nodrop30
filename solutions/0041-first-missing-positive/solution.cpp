/*
 * Problem: 41. First Missing Positive
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/first-missing-positive/
 * 
 * Approach: Array Marking
 * Time Complexity: O(n), where n is the size of the array
 * Space Complexity: O(n) for the boolean array
 */

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int sz = nums.size();
            bool arr[sz+1];
            
            // Initialize the boolean array
            for(int i = 0; i < sz+1; i++) 
                arr[i] = 0;
            
            // Mark numbers that are in range [1, n]
            for(int i = 0; i < sz; i++){
                if(nums[i] >= 1 && nums[i] <= sz) 
                    arr[nums[i]] = true;
            }
            
            // Find the first missing positive number
            int ans = 0;
            for(int i = 1; i <= sz; i++){
                if(!arr[i]){
                    ans = i;
                    break;
                }
            }
    
            // If all numbers from 1 to n are present, return n+1
            if(ans == 0) 
                ans = sz+1;
    
            return ans;
        }
};

/*
 * Alternative Solution: O(1) Space In-place Algorithm
 * Time Complexity: O(n), where n is the size of the array
 * Space Complexity: O(1), uses the input array itself for marking
 */

class AlternativeSolution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Move all positive integers <= n to their correct positions
        // For example, 1 should be at index 0, 2 at index 1, etc.
        for (int i = 0; i < n; ++i) {
            // Keep swapping until we place the current number at its correct position
            // or the number is out of range or we have a duplicate
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Find the first position where the value doesn't match its position
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all positions match, return n+1
        return n + 1;
    }
};