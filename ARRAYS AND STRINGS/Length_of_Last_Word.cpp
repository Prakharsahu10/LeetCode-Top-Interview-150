/*

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

*/

/*
Intuition:
To find the length of the last word in a string, we need to:
1. Skip any trailing spaces (if any)
2. Count consecutive non-space characters moving backwards from the end
3. Return the count

The key insight is that we can solve this efficiently by starting from the end of the string
and working backwards. This way, we encounter the last word first and don't need to process
the entire string unnecessarily.

Approach:
1. Start from the end of the string and skip all trailing spaces
2. Count consecutive non-space characters until we hit a space or the beginning of the string
3. Return the count as the length of the last word

This approach is efficient with O(n) time complexity where n is the length of the string,
and O(1) space complexity as we only use a few variables regardless of input size.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool counting = false;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                counting = true;
                length++;
            } else if (counting) {
                break;
            }
        }
        return length;
    }
};

/*
Time Complexity: O(n), where n is the length of the string.
                 In the worst case, we might need to traverse the entire string once.

Space Complexity: O(1), as we only use a constant amount of extra space
                  regardless of the input size.

Alternative approaches:
1. We could split the string into words and return the length of the last word,
   but that would require O(n) extra space.
2. We could iterate from left to right, keeping track of word lengths as we go,
   but that would require processing the entire string.

The backwards approach is more efficient as it allows us to stop once we've found
the last word, potentially saving time for very long strings.
*/

