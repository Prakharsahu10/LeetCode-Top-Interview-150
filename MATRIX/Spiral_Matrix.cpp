/*
Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

Algorithm Approach:
The key insight is to traverse the matrix layer by layer from outside to inside.
Each layer involves traversing 4 sides: top row, right column, bottom row, left column.

We maintain 4 boundaries that shrink inward after processing each side:
- stRow, endRow: current top and bottom boundaries
- stCol, endCol: current left and right boundaries

Traversal pattern for each layer:
1. Top row: left to right (stRow, stCol → stCol, endCol)
2. Right column: top to bottom (stRow+1, endCol → endRow, endCol)  
3. Bottom row: right to left (endRow, endCol-1 → endRow, stCol)
4. Left column: bottom to top (endRow-1, stCol → stRow+1, stCol)

After each side, we shrink the corresponding boundary and continue until all elements are processed.

Time Complexity: O(m × n) - visit each element exactly once
Space Complexity: O(1) - only using variables to track boundaries (excluding output space)

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Get matrix dimensions
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ans;

        // Variables to track progress and boundaries
        int count = 0, total = row * col;  // count: elements processed, total: target count
        int stRow = 0, stCol = 0;          // Starting boundaries (top-left)
        int endRow = row - 1, endCol = col - 1;  // Ending boundaries (bottom-right)

        // Continue until all elements are processed
        while (count < total) {
            
            // Traverse TOP ROW: left to right
            // Move along the current top row from stCol to endCol
            for (int index = stCol; count < total && index <= endCol; index++) {
                ans.push_back(matrix[stRow][index]);
                count++;
            }
            stRow++;  // Move top boundary down (shrink from top)

            // Traverse RIGHT COLUMN: top to bottom  
            // Move along the current right column from stRow to endRow
            for (int index = stRow; count < total && index <= endRow; index++) {
                ans.push_back(matrix[index][endCol]);
                count++;
            }
            endCol--;  // Move right boundary left (shrink from right)

            // Traverse BOTTOM ROW: right to left
            // Move along the current bottom row from endCol to stCol  
            for (int index = endCol; count < total && index >= stCol; index--) {
                ans.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--;  // Move bottom boundary up (shrink from bottom)

            // Traverse LEFT COLUMN: bottom to top
            // Move along the current left column from endRow to stRow
            for (int index = endRow; count < total && index >= stRow; index--) {
                ans.push_back(matrix[index][stCol]);
                count++;
            }
            stCol++;  // Move left boundary right (shrink from left)
        }
        
        return ans;
    }
};

/*
ALGORITHM WALKTHROUGH:

Example: matrix = [[1,2,3],[4,5,6],[7,8,9]]

Initial state:
- stRow=0, endRow=2, stCol=0, endCol=2
- count=0, total=9

Layer 1:
1. Top row (row 0): 1→2→3, count=3, stRow=1
2. Right column (col 2): 6→9, count=5, endCol=1  
3. Bottom row (row 2): 8→7, count=7, endRow=1
4. Left column (col 0): 4, count=8, stCol=1

Layer 2:
1. Top row (row 1): 5, count=9, stRow=2
2. count=total, exit

Result: [1,2,3,6,9,8,7,4,5]

KEY DESIGN ELEMENTS:

1. Boundary Management:
   - Four boundaries shrink inward after processing each side
   - Ensures we never revisit processed elements
   - Natural termination when boundaries cross

2. Count Check: count < total && condition
   - Prevents going out of bounds
   - Handles edge cases like single row/column matrices
   - Ensures we stop exactly when all elements are processed

3. Direction Pattern:
   - Right → Down → Left → Up (clockwise spiral)
   - Each direction corresponds to one side of current layer
   - Boundaries shrink in opposite direction of traversal

4. Edge Cases Handled:
   - Single row: only top row traversal happens
   - Single column: only top row and right column traversals happen  
   - 1x1 matrix: only first element of top row traversal

VISUALIZATION:
For 3x3 matrix:
Layer 1: 1→2→3
         ↓
         6→9
         ↓
         8←7
         ↓
         4←5

The algorithm naturally handles matrices of any size by processing one complete layer at a time.
*/

// Time Complexity: O(m × n) where m is number of rows and n is number of columns
// - Each element is processed exactly once
// Space Complexity: O(1) - only using variables to track boundaries (excluding output space)
// - The output array does not count towards space complexity as per problem constraints