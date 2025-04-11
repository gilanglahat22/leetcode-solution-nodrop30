/*
 * Problem: 30. Substring with Concatenation of All Words
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 * 
 * Approach: Sliding Window with Hash Map
 * Time Complexity: O(N * M * L), where N is the length of the string, M is the length of each word, and L is the number of words
 * Space Complexity: O(L) for the hash maps
 */

import java.util.*;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        
        // Edge cases
        if (s == null || words == null || words.length == 0 || s.length() < words.length * words[0].length()) {
            return result;
        }

        int wordLength = words[0].length();
        int totalLength = wordLength * words.length;

        // Create a frequency map of all words
        Map<String, Integer> wordMap = new HashMap<>();
        for (String word : words) {
            wordMap.put(word, wordMap.getOrDefault(word, 0) + 1);
        }

        // Sliding window approach
        // Start at each possible offset (0 to wordLength-1)
        for (int i = 0; i < wordLength; i++) {
            int left = i;
            int right = i;
            Map<String, Integer> windowMap = new HashMap<>();
            int count = 0;  // Count of valid words in current window

            while (right + wordLength <= s.length()) {
                // Get the next word from the string
                String word = s.substring(right, right + wordLength);
                right += wordLength;

                // If the word is in our word list
                if (wordMap.containsKey(word)) {
                    windowMap.put(word, windowMap.getOrDefault(word, 0) + 1);
                    count++;

                    // If the word appears more times than it should, slide the window
                    while (windowMap.get(word) > wordMap.get(word)) {
                        String leftWord = s.substring(left, left + wordLength);
                        left += wordLength;
                        windowMap.put(leftWord, windowMap.get(leftWord) - 1);
                        count--;
                    }

                    // If we have found all words in the correct order
                    if (count == words.length) {
                        result.add(left);
                    }
                } else {
                    // If we encounter an invalid word, reset the window
                    windowMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return result;
    }
}

/*
 * Alternative Solution: Brute Force with Optimization
 * This approach checks each possible starting position in the string.
 */
class AlternativeSolution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        
        if (s == null || words == null || words.length == 0) {
            return result;
        }
        
        int wordLen = words[0].length();
        int totalLen = wordLen * words.length;
        
        if (s.length() < totalLen) {
            return result;
        }
        
        // Create a frequency map for words
        Map<String, Integer> wordCount = new HashMap<>();
        for (String word : words) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }
        
        // Check each possible starting position
        for (int i = 0; i <= s.length() - totalLen; i++) {
            Map<String, Integer> seen = new HashMap<>();
            boolean valid = true;
            
            // Check if substring starting at position i is valid
            for (int j = 0; j < words.length; j++) {
                int start = i + j * wordLen;
                String currWord = s.substring(start, start + wordLen);
                
                // If word is not in our list, break
                if (!wordCount.containsKey(currWord)) {
                    valid = false;
                    break;
                }
                
                // Update seen words
                seen.put(currWord, seen.getOrDefault(currWord, 0) + 1);
                
                // If word appears more times than it should, break
                if (seen.get(currWord) > wordCount.get(currWord)) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                result.add(i);
            }
        }
        
        return result;
    }
}
