/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Edge case: empty array
        if (strs.empty()) return "";
        
        // Use first string as the initial prefix
        string prefix = strs[0];
        
        // Compare prefix with each remaining string
        for (int i = 1; i < strs.size(); i++) {
            // Trim prefix until it matches the beginning of the current string
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If prefix becomes empty, there's no common prefix
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};

// Time Complexity: O(n * m), where n is the number of strings and m is the length of the shortest string.
// Space Complexity: O(1), since we are using a fixed amount of extra space for the prefix variable.    