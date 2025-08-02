/*
Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Problem Approach:
This is a classic string matching problem, also known as substring search. The brute force approach is to:
1. Check every possible starting position in haystack
2. For each position, compare the substring with needle
3. Return the first index where we find a complete match
4. If no match is found, return -1

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        // Edge case: If haystack is shorter than needle, needle can't be found
        if (haystack.length() < needle.length()) {
            return -1;
        }
        
        // Iterate through potential starting positions in haystack
        // We only need to check positions where the full needle can fit
        // (hence stopping at haystack.length() - needle.length())
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            // Extract substring from haystack starting at position i with length of needle
            // Compare it directly with needle
            if (haystack.substr(i, needle.length()) == needle) {
                return i;  // Found a match, return the starting index
            }
        }
        
        // If we've checked all possible positions and found no match
        return -1;        
    }
};

// Time Complexity: O((n - m + 1) * m), where n is the length of haystack and m is the length of needle.
// - We potentially check (n - m + 1) starting positions
// - For each position, we compare up to m characters when using substr
// - The substr function itself takes O(m) time to create a new string

// Space Complexity: O(m) for the substring operation, but can be considered O(1) if we ignore the substring creation.
// - We create substrings of length m when using the substr function
// - No additional data structures are used that grow with input size

// Note: More efficient algorithms like KMP, Boyer-Moore, or Rabin-Karp can solve this in O(n + m) time,
// but the above approach is more straightforward and easier to understand.