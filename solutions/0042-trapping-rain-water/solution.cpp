/*
 * Problem: 42. Trapping Rain Water
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/trapping-rain-water/
 * 
 * Approach: Two Pointers
 * Time Complexity: O(n), where n is the size of the height array
 * Space Complexity: O(1), using only constant extra space
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int result = 0;
        
        // Use two pointers to scan from left and right
        while (left < right) {
            // If the left height is smaller, move from left to right
            if (height[left] < height[right]) {
                // If current height is greater than max seen so far, update max
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } 
                // Otherwise, we can trap water here
                else {
                    result += maxLeft - height[left];
                }
                left++;
            } 
            // If the right height is smaller or equal, move from right to left
            else {
                // If current height is greater than max seen so far, update max
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } 
                // Otherwise, we can trap water here
                else {
                    result += maxRight - height[right];
                }
                right--;
            }
        }
        
        return result;
    }
};

/*
 * Alternative Solution: Dynamic Programming
 * Time Complexity: O(n), where n is the size of the height array
 * Space Complexity: O(n), for storing the left and right max arrays
 */

class AlternativeSolution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        
        // Calculate maximum height to the left for each position
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        
        // Calculate maximum height to the right for each position
        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        
        // Calculate trapped water at each position
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return result;
    }
};