/*
Word Pattern Problem

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.

Key Insight:
This is similar to the Isomorphic Strings problem, but instead of character-to-character mapping,
we need character-to-word mapping. We need a bijective (one-to-one) relationship between
pattern characters and words in the string.

Algorithm:
1. Parse the string s into individual words
2. Check if number of words equals number of pattern characters
3. Use two hash maps to maintain bidirectional mapping:
   - charToWord: maps pattern characters to words
   - wordToChar: maps words to pattern characters
4. For each (character, word) pair, verify no conflicting mappings exist
5. Update both mappings

Time Complexity: O(n + m) where n = pattern length, m = string length
Space Complexity: O(w) where w = number of unique words

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"

Output: true

Explanation:

The bijection can be established as:

'a' maps to "dog".
'b' maps to "cat".
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"

Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"

Output: false

 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.

*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Parse the input string into individual words using stringstream
        stringstream ss(s);
        vector<string> words;
        string word;

        // Extract words separated by spaces
        while (ss >> word) words.push_back(word);

        // Early check: number of words must equal number of pattern characters
        if (words.size() != pattern.size()) return false;

        // Two hash maps to maintain bidirectional mapping between characters and words
        unordered_map<char, string> charToWord;  // Maps pattern characters to words
        unordered_map<string, char> wordToChar;  // Maps words to pattern characters

        // Process each (character, word) pair at the same position
        for(int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];    // Current character from pattern
            string w = words[i];    // Current word from parsed string

            // Check if character c already maps to a different word
            // If c maps to something other than w, pattern doesn't match
            if (charToWord.count(c) && charToWord[c] != w) return false;
            
            // Check if word w already maps to a different character
            // If w maps to something other than c, pattern doesn't match
            if (wordToChar.count(w) && wordToChar[w] != c) return false;

            // Establish/update the bidirectional mapping
            charToWord[c] = w;  // Pattern character maps to this word
            wordToChar[w] = c;  // Word maps to this pattern character
        }
        
        // If all mappings are consistent, the string follows the pattern
        return true;
    }
};

// Time Complexity: O(n + m) where n = pattern length, m = string length
// Space Complexity: O(w) where w = number of unique words