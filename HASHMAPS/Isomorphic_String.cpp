/*
Isomorphic Strings Problem

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Key Insight:
For strings to be isomorphic, we need a bijective (one-to-one) mapping between characters.
This means:
1. Each character in s maps to exactly one character in t
2. Each character in t maps to exactly one character in s
3. No two different characters can map to the same character

Algorithm:
1. Use two hash maps to track bidirectional mapping
2. For each character pair (s[i], t[i]):
   - Check if s[i] already maps to a different character in t
   - Check if t[i] already maps to a different character in s
   - If either condition fails, strings are not isomorphic
3. Update both mappings

Time Complexity: O(n) where n is the length of strings
Space Complexity: O(k) where k is the number of unique characters

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true

 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Edge case: strings must have same length to be isomorphic
        if (s.length() != t.length()) return false;
        
        // Two hash maps to maintain bidirectional mapping
        unordered_map<char, char> mapST;  // Maps characters from s to t
        unordered_map<char, char> mapTS;  // Maps characters from t to s

        // Process each character pair at the same position
        for (int i = 0; i < s.length(); i++) {
            char sc = s[i], tc = t[i];  // Current characters from both strings

            // Check if character sc in s already has a mapping to a different character
            // If sc maps to something other than tc, strings are not isomorphic
            if (mapST.count(sc) && mapST[sc] != tc) return false;
            
            // Check if character tc in t already has a mapping to a different character
            // If tc maps to something other than sc, strings are not isomorphic
            if (mapTS.count(tc) && mapTS[tc] != sc) return false;

            // Establish/update the bidirectional mapping
            mapST[sc] = tc;  // s[i] maps to t[i]
            mapTS[tc] = sc;  // t[i] maps to s[i]
        }
        
        // If we've processed all characters without conflicts, strings are isomorphic
        return true;
    }
};

// Time Complexity: O(n) where n is the length of strings
// Space Complexity: O(k) where k is the number of unique characters

