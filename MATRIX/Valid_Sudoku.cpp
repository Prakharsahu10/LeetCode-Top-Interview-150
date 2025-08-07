/*

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.

*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Create 9 sets for rows, columns, and boxes to track seen digits
        vector<unordered_set<char>> rows(9); // rows[i] stores digits seen in row i
        vector<unordered_set<char>> cols(9); // cols[j] stores digits seen in column j
        vector<unordered_set<char>> boxes(9); // boxes[boxIndex] stores digits seen in 3x3 box

        // Traverse every cell in the 9x9 board
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                // Skip empty cells
                if (num == '.') continue;

                // Check if num already exists in the current row
                if (rows[i].count(num)) return false; // Duplicate in row
                rows[i].insert(num); // Mark num as seen in this row

                // Check if num already exists in the current column
                if (cols[j].count(num)) return false; // Duplicate in column
                cols[j].insert(num); // Mark num as seen in this column

                // Calculate the index for the 3x3 sub-box
                // There are 9 boxes, indexed from 0 to 8
                // boxIndex = (i / 3) * 3 + (j / 3)
                int boxIndex = (i / 3) * 3 + (j / 3);
                // Check if num already exists in the current 3x3 box
                if (boxes[boxIndex].count(num)) return false; // Duplicate in box
                boxes[boxIndex].insert(num); // Mark num as seen in this box
            }
        }
        // If no duplicates found, the board is valid
        return true;
    }
};

// Time Complexity: O(1) - The board size is fixed at 9x9, so the operations are constant time.
// Space Complexity: O(1) - The sets for rows, columns, and boxes are of fixed size (9 each), so space usage is constant.
