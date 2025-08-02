/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

*/

class Solution {
public:
    string convert(string s, int numRows) {
        // Edge cases
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        // Create a vector of strings to store characters in each row
        vector<string> rows(numRows);
        
        // Variables to track current position
        int currentRow = 0;
        bool goingDown = false;
        
        // Place each character in its corresponding row
        for (char c : s) {
            rows[currentRow] += c;
            
            // Change direction when we reach the first or last row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to next row based on current direction
            currentRow += goingDown ? 1 : -1;
        }
        
        // Combine all rows to form the result
        string result;
        for (string row : rows) {
            result += row;
        }
        
        return result;
    }
};

// Time Complexity: O(n), where n is the length of the input string s.
// Space Complexity: O(n), since we are storing the characters in a vector of strings.