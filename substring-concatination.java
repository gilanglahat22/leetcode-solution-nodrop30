import java.util.*;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        
        if (s == null || words == null || words.length == 0 || s.length() < words.length * words[0].length()) {
            return result;
        }

        int wordLength = words[0].length();
        int totalLength = wordLength * words.length;

        Map<String, Integer> wordMap = new HashMap<>();
        for (String word : words) {
            wordMap.put(word, wordMap.getOrDefault(word, 0) + 1);
        }

        // Sliding window approach
        for (int i = 0; i < wordLength; i++) {
            int left = i;
            int right = i;
            Map<String, Integer> windowMap = new HashMap<>();
            int count = 0;

            while (right + wordLength <= s.length()) {
                String word = s.substring(right, right + wordLength);
                right += wordLength;

                // If the word is valid, add it to the window
                if (wordMap.containsKey(word)) {
                    windowMap.put(word, windowMap.getOrDefault(word, 0) + 1);
                    count++;

                    // If the word appears more than it should, slide the window
                    while (windowMap.get(word) > wordMap.get(word)) {
                        String leftWord = s.substring(left, left + wordLength);
                        left += wordLength;
                        windowMap.put(leftWord, windowMap.get(leftWord) - 1);
                        count--;
                    }

                    if (count == words.length) {
                        result.add(left);
                    }
                } else {
                    windowMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return result;
    }
}
