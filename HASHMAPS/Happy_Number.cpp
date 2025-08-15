/*
Happy Number Problem

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Key Insight:
This problem can be solved by recognizing patterns in single-digit numbers:
- For single-digit numbers (1-9), only 1 and 7 lead to happiness
- All other single digits eventually cycle and never reach 1
- We can use this mathematical property to optimize the solution

Alternative approaches:
1. HashSet cycle detection (more general)
2. Floyd's cycle detection (space efficient)
3. Mathematical pattern recognition (current approach - most efficient)

Example 1:

Input: n = 19
Output: true
Explanation:
1² + 9² = 82
8² + 2² = 68
6² + 8² = 100
1² + 0² + 0² = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1

*/

class Solution {
public:
    bool isHappy(int n) {
        // Base cases: Mathematical insight about single-digit numbers
        // Only 1 and 7 among single digits lead to happy numbers
        if(n == 1 || n == 7) return true;
        
        // For single digits other than 1 and 7, they eventually cycle
        // and never reach 1, so they are not happy
        else if(n < 10) return false;
        
        // For multi-digit numbers, calculate sum of squares of digits
        else {
            int sum = 0;
            
            // Extract each digit and add its square to sum
            while(n > 0) {
                int temp = n % 10;     // Get last digit
                sum += temp * temp;    // Add square of digit to sum
                n = n / 10;            // Remove last digit
            }
            
            // Recursively check if the sum is a happy number
            return isHappy(sum);
        }
    }
};

/*
ALGORITHM EXPLANATION:

This solution uses a mathematical optimization based on the behavior of single-digit numbers:

Single-digit analysis:
- 1: 1² = 1 → Happy ✓
- 2: 2² = 4 → 4² = 16 → 1² + 6² = 37 → ... → cycles → Not happy ✗
- 3: 3² = 9 → 9² = 81 → ... → cycles → Not happy ✗
- 4: 4² = 16 → ... → cycles → Not happy ✗
- 5: 5² = 25 → ... → cycles → Not happy ✗
- 6: 6² = 36 → ... → cycles → Not happy ✗
- 7: 7² = 49 → 4² + 9² = 97 → ... → 1 → Happy ✓
- 8: 8² = 64 → ... → cycles → Not happy ✗
- 9: 9² = 81 → ... → cycles → Not happy ✗

COMPLEXITY ANALYSIS:
- Time: O(log n) average case, where log n is the number of digits
- Space: O(log n) due to recursion stack

ALTERNATIVE APPROACHES:

1. HashSet Cycle Detection:
   unordered_set<int> seen;
   while(n != 1 && seen.find(n) == seen.end()) {
       seen.insert(n);
       n = getSumOfSquares(n);
   }
   return n == 1;

2. Floyd's Cycle Detection (Two Pointers):
   int slow = n, fast = n;
   do {
       slow = getSumOfSquares(slow);
       fast = getSumOfSquares(getSumOfSquares(fast));
   } while(slow != fast);
   return slow == 1;

The current approach is most efficient as it leverages mathematical properties.

// Time Complexity: O(log n) - number of digits
// Space Complexity: O(log n) - recursion stack