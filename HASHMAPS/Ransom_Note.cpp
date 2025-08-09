/*
Ransom Note Problem

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Approach:
This problem is solved using frequency counting. We need to check if the magazine has 
enough of each character required by the ransom note.

Algorithm:
1. Count frequency of each character in both strings
2. For each character, check if magazine has at least as many as needed by ransom note
3. If any character is insufficient in magazine, return false

Time Complexity: O(n + m) where n = ransomNote length, m = magazine length
Space Complexity: O(1) since we use fixed-size arrays of 26 elements

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Create frequency arrays for both strings
        // Since we only have lowercase letters (a-z), we use arrays of size 26
        vector<int> freqRansom(26, 0);  // Count of each character needed by ransom note
        vector<int> freqMag(26, 0);     // Count of each character available in magazine

        // Count frequency of each character in ransom note
        for (char ch : ransomNote)
            freqRansom[ch - 'a']++;  // Convert char to index (a=0, b=1, ..., z=25)

        // Count frequency of each character in magazine
        for (char ch : magazine)
            freqMag[ch - 'a']++;     // Convert char to index (a=0, b=1, ..., z=25)

        // Check if magazine has enough of each character required by ransom note
        for (int i = 0; i < 26; i++) {
            // If ransom note needs more of character i than magazine has
            if (freqRansom[i] > freqMag[i])
                return false;  // Impossible to construct ransom note
        }

        // If we reach here, magazine has sufficient characters for ransom note
        return true;
    }
};

// Time Complexity: O(n + m) where n = ransomNote length, m = magazine length
// Space Complexity: O(1) since we use fixed-size arrays of 26 elements