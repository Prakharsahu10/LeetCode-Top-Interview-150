/*
Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Algorithm Intuition:
1. Reverse the entire string - this puts words in reverse order, but each word is also reversed
2. Process the reversed string from left to right:
   - Skip spaces to find word beginnings
   - Copy words to their final position
   - Reverse each individual word back to its correct order
   - Add a single space between words
3. Trim the final trailing space

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

*/

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string
        // This puts words in reverse order but each word is also reversed
        // Example: "the sky is blue" -> "eulb si yks eht"
        reverse(s.begin(), s.end());
        
        int n = s.size();
        int left = 0;    // Marks the start position of current word in result
        int right = 0;   // Current position in the result string
        int i = 0;       // Current position in the original string
        
        while (i < n) {
            // Step 2: Skip spaces
            // Skip all leading and multiple spaces between words
            while (i < n && s[i] == ' ')
                i++;
            
            // If we've reached the end of string, exit the loop
            if (i == n)
                break;
            
            // Step 3: Copy the word (which is currently reversed)
            // Move characters of the current word to their final position
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }
            
            // Step 4: Reverse the individual word to correct order
            // Since the initial reverse flipped each word, we need to flip it back
            // Example: "eulb" -> "blue"
            reverse(s.begin() + left, s.begin() + right);
            
            // Step 5: Add a single space after the word
            s[right++] = ' ';
            
            // Step 6: Update left pointer to start of next word position
            left = right;
            
            // Move to next character (skip the space we just processed)
            i++;
        }
        
        // Step 7: Remove trailing space if there is one
        // If we added any words, we'll have an extra space at the end
        // Resize the string to remove this trailing space
        s.resize(right - 1);
        
        return s;
    }
};

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), since we are modifying the string in place without using extra space.