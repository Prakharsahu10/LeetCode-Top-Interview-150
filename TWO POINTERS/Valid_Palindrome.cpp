/*
Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Approach:
This problem is solved using the two-pointer technique:
1. Use two pointers, one starting from the beginning and one from the end
2. Skip all non-alphanumeric characters (using isalnum())
3. Compare characters after converting to lowercase (using tolower())
4. If all pairs match, the string is a palindrome

Time Complexity: O(n) where n is the length of the string
Space Complexity: O(1) as we only use two pointers regardless of input size

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

*/

class Solution {
public:
    bool isPalindrome(string s) {
        // Initialize two pointers, one at the beginning and one at the end
        int left = 0, right = s.length() - 1;

        // Continue until the two pointers meet or cross each other
        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left])) left++;
            
            // Skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right])) right--;

            // Compare the characters (case-insensitive)
            // If they don't match, it's not a palindrome
            if (tolower(s[left]) != tolower(s[right]))
                return false;

            // Move both pointers toward the center
            left++;
            right--;
        }

        // If we've checked all characters without finding a mismatch,
        // the string is a palindrome
        return true;
    }
};

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), as we are using only two pointers and no additional data structures.