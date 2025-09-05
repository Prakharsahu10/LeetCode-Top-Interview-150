/*

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

#include <vector>
using namespace std;

class Solution {
public:
    /*
    ALGORITHM: In-Place Matrix Zero Setting with O(1) Space
    
    PROBLEM CHALLENGE:
    - Set entire row and column to 0 when element is 0
    - Must be done in-place (no extra matrix)
    - Follow-up asks for O(1) space complexity
    
    KEY INSIGHT: 
    Use first row and first column as "marker arrays" to track which rows/columns need zeroing
    
    INTUITION:
    Instead of using separate arrays to mark rows/columns, we repurpose the matrix's own
    first row and column as flags. This is the key to achieving O(1) space complexity.
    
    ALGORITHM BREAKDOWN:
    1. Check if first row/column originally contain zeros (need special handling)
    2. Scan matrix and mark first row/column when zero found
    3. Use markers to zero out the matrix
    4. Handle first row/column based on original state
    
    TIME COMPLEXITY: O(m×n) - three passes through matrix
    SPACE COMPLEXITY: O(1) - only using two boolean flags
    */
    
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        // Flags to track if first row/column originally had zeros
        // We need these because we'll use first row/column as markers
        bool firstRowZero = false, firstColZero = false;
        
        // STEP 1: Check if first row originally contains zero
        // Important: We need to know this before using first row as marker
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;  // Found one zero, entire row will be zeroed
            }
        }
        
        // STEP 2: Check if first column originally contains zero  
        // Important: We need to know this before using first column as marker
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;  // Found one zero, entire column will be zeroed
            }
        }
        
        // STEP 3: Use first row and first column as markers
        // Scan the inner matrix (excluding first row/column)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // Mark row i needs zeroing by setting matrix[i][0] = 0
                    matrix[i][0] = 0;
                    // Mark column j needs zeroing by setting matrix[0][j] = 0
                    matrix[0][j] = 0;
                }
            }
        }
        
        // STEP 4: Set zeroes based on markers in first row/column
        // Process inner matrix using the markers we just set
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // If row i is marked OR column j is marked, set to zero
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // STEP 5: Handle first row based on original state
        // If first row originally had zero, zero out entire first row
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // STEP 6: Handle first column based on original state  
        // If first column originally had zero, zero out entire first column
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

/*
ALGORITHM WALKTHROUGH:

Example: matrix = [[1,1,1],[1,0,1],[1,1,1]]

Initial Analysis:
- First row [1,1,1]: no zeros → firstRowZero = false
- First column [1,1,1]: no zeros → firstColZero = false

Step 3 - Marking Phase:
- Found zero at (1,1)
- Mark row 1: matrix[1][0] = 0
- Mark column 1: matrix[0][1] = 0
- Matrix becomes: [[1,0,1],[0,0,1],[1,1,1]]

Step 4 - Zeroing Phase:
- (1,1): row 1 marked AND column 1 marked → set to 0
- (1,2): row 1 marked → set to 0  
- (2,1): column 1 marked → set to 0
- Matrix becomes: [[1,0,1],[0,0,0],[1,0,1]]

Steps 5-6: First row/column handling:
- firstRowZero = false → don't zero first row
- firstColZero = false → don't zero first column

Final Result: [[1,0,1],[0,0,0],[1,0,1]] ✓

SPACE COMPLEXITY COMPARISON:

1. Naive O(mn): Create copy of entire matrix
2. Improved O(m+n): Use separate boolean arrays for rows/columns  
3. Optimal O(1): Use first row/column as marker arrays ← This solution

WHY THIS APPROACH WORKS:

Key Insight: The first row and column can serve dual purposes:
1. Store original values (initially)
2. Act as marker arrays (after processing)

Critical Detail: We must check original state of first row/column BEFORE 
using them as markers, hence the boolean flags.

EDGE CASES HANDLED:

1. First row contains zero: firstRowZero flag ensures proper handling
2. First column contains zero: firstColZero flag ensures proper handling
3. Zero at (0,0): Both flags will be true, both first row/column zeroed
4. Single row/column: Algorithm naturally handles via the flags
5. All zeros: Markers will be set everywhere, entire matrix zeroed
6. No zeros: No markers set, matrix unchanged

ALGORITHM CORRECTNESS:

The order of operations is crucial:
1. Save original state of first row/column (Steps 1-2)
2. Use them as markers for inner matrix (Step 3)  
3. Apply markers to inner matrix (Step 4)
4. Handle first row/column based on saved state (Steps 5-6)

This ensures we don't confuse "original zeros" with "marker zeros".
*/
