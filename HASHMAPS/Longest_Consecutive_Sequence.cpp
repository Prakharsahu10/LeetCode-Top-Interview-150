/*
Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

INTUITION:
The key insight is to think about what makes a consecutive sequence:
- A sequence like [1,2,3,4] has consecutive numbers
- To find the longest sequence efficiently, we need to:
  1. Quickly check if a number exists in the array (HashMap/Set)
  2. Only start counting from the "beginning" of a sequence
  3. Avoid recounting the same sequence multiple times

SMART OPTIMIZATION:
Instead of checking every number, we only start counting from numbers that are 
the "start" of a sequence. A number n is the start of a sequence if (n-1) 
doesn't exist in the array.

ALGORITHM:
1. Put all numbers in a HashSet for O(1) lookup
2. For each number n in the set:
   - If (n-1) doesn't exist, n is the start of a sequence
   - Count consecutive numbers starting from n: n, n+1, n+2, ...
   - Track the maximum length found

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

*/

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Handle edge case: empty array
        if (nums.empty()) return 0;
        
        // Step 1: Put all numbers in a HashSet for O(1) lookup
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int maxLength = 0;
        
        // Step 2: Check each unique number
        for (int num : numSet) {
            // Step 3: Only start counting from the beginning of a sequence
            // If (num - 1) exists, then num is not the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                // num is the start of a sequence
                int currentNum = num;
                int currentLength = 1;
                
                // Step 4: Count consecutive numbers
                // Keep checking num+1, num+2, num+3, ... until we can't find the next number
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLength++;
                }
                
                // Step 5: Update maximum length found
                maxLength = max(maxLength, currentLength);
            }
        }
        
        return maxLength;
    }
};

/*
DETAILED WALKTHROUGH:

Example: nums = [100, 4, 200, 1, 3, 2]

Step 1: Create HashSet
numSet = {100, 4, 200, 1, 3, 2}

Step 2: Check each number to see if it's the start of a sequence

Check 100:
- Is (100-1=99) in set? NO → 100 is start of sequence
- Count: 100 → check 101 (not in set) → length = 1

Check 4:
- Is (4-1=3) in set? YES → 4 is NOT start of sequence, skip

Check 200:
- Is (200-1=199) in set? NO → 200 is start of sequence  
- Count: 200 → check 201 (not in set) → length = 1

Check 1:
- Is (1-1=0) in set? NO → 1 is start of sequence
- Count: 1 → 2 (✓) → 3 (✓) → 4 (✓) → 5 (✗) → length = 4

Check 3:
- Is (3-1=2) in set? YES → 3 is NOT start of sequence, skip

Check 2:  
- Is (2-1=1) in set? YES → 2 is NOT start of sequence, skip

Maximum length = 4

WHY THIS IS O(N):
- HashSet creation: O(n)
- Main loop: visits each number once = O(n)
- Inner while loop: each number is visited at most twice (once as start, once as part of sequence)
- Total: O(n) + O(n) + O(n) = O(n)

KEY INSIGHT:
By only starting from sequence beginnings, we ensure each number is processed 
at most twice, maintaining linear time complexity.

ALTERNATIVE APPROACHES:
1. Sorting: O(n log n) time, O(1) space
2. Union-Find: O(n α(n)) time, O(n) space  
3. HashSet (current): O(n) time, O(n) space ← Optimal for time complexity requirement
*/

