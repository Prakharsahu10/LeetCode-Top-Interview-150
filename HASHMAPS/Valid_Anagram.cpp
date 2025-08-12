/*
Valid Anagram Problem

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Algorithm (Sorting Approach):
Two strings are anagrams if they contain the same characters with the same frequencies.
When we sort both strings, anagrams will become identical strings.

Time Complexity: O(n log n) due to sorting both strings
Space Complexity: O(1) if sorting in-place

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Sort both strings alphabetically
        // If the strings are anagrams, they will become identical after sorting
        // Example: "anagram" -> "aaagmnr", "nagaram" -> "aaagmnr" (same!)
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        // Compare the sorted strings
        // If they are equal, the original strings were anagrams
        return s == t;
    }
};