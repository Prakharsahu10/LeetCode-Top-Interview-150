/*
Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Key Insight:
Anagrams have the same characters with the same frequencies. We can use this property to create
a unique "signature" for each group of anagrams and use HashMap to group them efficiently.

Two main approaches:
1. Sorting approach: Sort each string to create a canonical form as the key
2. Frequency counting: Use character frequency as the signature

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // HashMap to store groups of anagrams
        // Key: sorted string (canonical form), Value: vector of original anagram strings
        unordered_map<string, vector<string>> ans;

        // Process each string in the input array
        for (string& s : strs) {
            // Create a key by sorting the current string
            // All anagrams will produce the same sorted key
            // Example: "eat", "tea", "ate" all become "aet" when sorted
            string key = s;
            sort(key.begin(), key.end());
            
            // Add the original string to the group identified by the sorted key
            // This automatically groups all anagrams together
            ans[key].push_back(s);
        }

        // Convert the HashMap values to the required output format
        vector<vector<string>> result;
        for (auto& entry : ans) {
            // Each entry.second contains a group of anagrams
            result.push_back(entry.second);
        }

        return result;
    }
};

// Time Complexity: O(N × K log K) where N = number of strings, K = average string length
// Space Complexity: O(N × K) for storing all strings in the HashMap and result 