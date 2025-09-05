/*

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

*/

class Solution {
public:
    /*
    ALGORITHM: Two-Step Matrix Rotation (90° Clockwise)
    
    Key Insight: 90° clockwise rotation = Vertical Flip + Transpose
    
    INTUITION:
    Instead of complex coordinate transformations, we break down the rotation into two simpler operations:
    1. Flip the matrix vertically (reverse rows)
    2. Transpose the matrix (swap elements across main diagonal)
    
    WHY THIS WORKS:
    - Original position (i,j) after 90° rotation goes to position (j, n-1-i)
    - Vertical flip: (i,j) → (n-1-i, j)  
    - Transpose: (n-1-i, j) → (j, n-1-i) ✓
    
    TIME COMPLEXITY: O(n²) - visit each element twice
    SPACE COMPLEXITY: O(1) - in-place transformation
    */
    
    void rotate(vector<vector<int>>& matrix) {
        int edgeLength = matrix.size();

        // STEP 1: VERTICAL FLIP (Reverse Rows)
        // Swap top row with bottom row, moving inward
        int top = 0;
        int bottom = edgeLength - 1;

        while (top < bottom) {
            // Swap entire rows element by element
            for (int col = 0; col < edgeLength; col++) {
                int temp = matrix[top][col];
                matrix[top][col] = matrix[bottom][col];
                matrix[bottom][col] = temp;
            }
            top++;      // Move top pointer down
            bottom--;   // Move bottom pointer up
        }

        // STEP 2: TRANSPOSE MATRIX
        // Swap elements across the main diagonal (i,j) ↔ (j,i)
        for (int row = 0; row < edgeLength; row++) {
            // Only process upper triangle to avoid double swapping
            for (int col = row + 1; col < edgeLength; col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            } 
        }
    }
};

/*
ALGORITHM WALKTHROUGH:

Example: matrix = [[1,2,3],[4,5,6],[7,8,9]]

STEP 1 - Vertical Flip:
Original:  [1,2,3]    After flip:  [7,8,9]
           [4,5,6]    ──────────→   [4,5,6]  
           [7,8,9]                  [1,2,3]

Process:
- Swap row 0 with row 2: [1,2,3] ↔ [7,8,9]
- Row 1 stays in middle (no swap needed)

STEP 2 - Transpose:
After flip: [7,8,9]    After transpose: [7,4,1]
            [4,5,6]    ──────────────→   [8,5,2]
            [1,2,3]                      [9,6,3]

Process:
- (0,1): 8 ↔ 4, (0,2): 9 ↔ 1, (1,2): 6 ↔ 2
- Elements across main diagonal are swapped

FINAL RESULT: [7,4,1],[8,5,2],[9,6,3] ✓

ALTERNATIVE APPROACHES:

1. Direct Coordinate Transformation:
   - For each (i,j), move to (j, n-1-i)
   - Requires careful handling to avoid overwriting

2. Layer-by-Layer Rotation:
   - Process concentric squares from outside to inside
   - Four-way swapping in each layer

3. Using Extra Space:
   - Create new matrix with rotated positions
   - Not allowed due to in-place constraint

WHY TWO-STEP APPROACH IS OPTIMAL:
- Simple to understand and implement
- No complex coordinate calculations
- Natural in-place operations
- Easy to verify correctness
- Works for any n×n matrix

EDGE CASES HANDLED:
- 1×1 matrix: No operations needed (top >= bottom, no transpose pairs)
- 2×2 matrix: One row swap + one diagonal swap
- Empty matrix: Edge length 0, no operations
*/

// Time Complexity: O(n^2), where n is the number of rows (or columns) in the n x n matrix.
// - Each element is visited twice: once during the vertical flip and once during the transpose.
// Space Complexity: O(1) - in-place transformation