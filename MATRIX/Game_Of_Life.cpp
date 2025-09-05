/*

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.

Note that you do not need to return anything.

 

Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.

*/

#include <vector>
using namespace std;

class Solution {
public:
    /*
    ALGORITHM: Conway's Game of Life - Cellular Automaton Simulation
    
    PROBLEM ESSENCE:
    Simulate one generation of Conway's Game of Life where each cell's next state
    depends on its current state and the count of live neighbors.
    
    THE FOUR RULES OF LIFE:
    1. Under-population: Live cell with <2 neighbors dies
    2. Survival: Live cell with 2-3 neighbors survives  
    3. Over-population: Live cell with >3 neighbors dies
    4. Reproduction: Dead cell with exactly 3 neighbors becomes alive
    
    KEY CHALLENGE: 
    All changes must happen SIMULTANEOUSLY - we can't update cells one by one
    because that would affect neighbor counts for subsequent cells.
    
    SOLUTION APPROACH:
    1. Create a copy of the board to store next state
    2. For each cell, count live neighbors using original board
    3. Apply rules to determine next state in the copy
    4. Replace original board with the next state
    
    TIME COMPLEXITY: O(m×n) - visit each cell once, count 8 neighbors each
    SPACE COMPLEXITY: O(m×n) - create copy of entire board
    */
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        // Create a copy to store the next generation
        // This is crucial because we need to count neighbors based on CURRENT state,
        // not the partially updated state
        vector<vector<int>> next = board;
        
        // Direction vectors for 8 neighbors (all adjacent cells)
        // Covers: top-left, top, top-right, left, right, bottom-left, bottom, bottom-right
        vector<int> dx = {-1,-1,-1,0,0,1,1,1};
        vector<int> dy = {-1,0,1,-1,1,-1,0,1};
        
        // Process each cell in the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = 0;
                
                // Count live neighbors in all 8 directions
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];  // Neighbor's row
                    int y = j + dy[k];  // Neighbor's column
                    
                    // Check if neighbor is within board boundaries
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        // Count this neighbor if it's alive (use original board!)
                        liveNeighbors += board[x][y];
                    }
                }
                
                // Apply Conway's rules based on current state and neighbor count
                if (board[i][j] == 1) {
                    // Current cell is ALIVE
                    
                    // Rule 1: Under-population death
                    // Rule 3: Over-population death  
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        next[i][j] = 0;  // Cell dies
                    }
                    // Rule 2: Survival (2 or 3 neighbors)
                    else {
                        next[i][j] = 1;  // Cell survives (stays alive)
                    }
                } else {
                    // Current cell is DEAD
                    
                    // Rule 4: Reproduction (exactly 3 neighbors)
                    if (liveNeighbors == 3) {
                        next[i][j] = 1;  // Cell becomes alive
                    }
                    // Otherwise stays dead (next[i][j] already 0 from copy)
                }
            }
        }
        
        // Replace original board with next generation
        // This step completes the simultaneous update requirement
        board = next;
    }
};

/*
ALGORITHM WALKTHROUGH:

Example: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]

Visual representation:
Row 0: [0,1,0]  . ● .
Row 1: [0,0,1]  . . ●  
Row 2: [1,1,1]  ● ● ●
Row 3: [0,0,0]  . . .

Let's trace key cells:

Cell (0,1) - Currently ALIVE:
- Neighbors: (0,0)=0, (0,2)=0, (1,0)=0, (1,1)=0, (1,2)=1
- Live neighbors: 1
- Rule 1: <2 neighbors → dies
- Next state: 0

Cell (1,0) - Currently DEAD:
- Neighbors: (0,0)=0, (0,1)=1, (1,1)=0, (2,0)=1, (2,1)=1  
- Live neighbors: 3
- Rule 4: exactly 3 neighbors → becomes alive
- Next state: 1

Cell (2,1) - Currently ALIVE:
- Neighbors: (1,0)=0, (1,1)=0, (1,2)=1, (2,0)=1, (2,2)=1, (3,0)=0, (3,1)=0, (3,2)=0
- Live neighbors: 3  
- Rule 2: 3 neighbors → survives
- Next state: 1

Final result: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

SPACE OPTIMIZATION ALTERNATIVE:

For O(1) space complexity, we could use bit manipulation:
- Use bit 0 for current state
- Use bit 1 for next state  
- Process in-place by encoding both states in each cell
- Finally, right-shift all values to get next generation

Example encoding:
- 00 (0): dead → dead
- 01 (1): alive → dead  
- 10 (2): dead → alive
- 11 (3): alive → alive

This approach is more complex but achieves O(1) space.

REAL-WORLD APPLICATIONS:

1. Biological Simulations: Population dynamics, ecosystem modeling
2. Computer Graphics: Procedural pattern generation, texture synthesis
3. Theoretical Computer Science: Studying emergent behavior, universal computation
4. Game Development: Dynamic world generation, artificial life systems

INTERESTING PATTERNS:

1. Still Life: Patterns that don't change (e.g., 2×2 block)
2. Oscillators: Patterns that repeat with period >1 (e.g., blinker)  
3. Spaceships: Patterns that translate across the grid (e.g., glider)
4. Guns: Patterns that produce other patterns (e.g., glider gun)

ALGORITHM PROPERTIES:

- Deterministic: Same input always produces same output
- Discrete: Time advances in discrete steps  
- Local: Each cell only depends on immediate neighbors
- Uniform: Same rules apply to all cells
- Synchronous: All updates happen simultaneously

This implementation correctly handles the simultaneity requirement by using
a separate array for the next generation, ensuring neighbor counts are based
on the current generation only.
*/
