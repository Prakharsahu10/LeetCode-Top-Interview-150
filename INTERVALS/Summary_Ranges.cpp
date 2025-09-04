/*
Summary Ranges

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

Algorithm Approach:
1. Track the start of each consecutive range
2. Continue until we find a gap (non-consecutive numbers)
3. When gap is found or we reach the end, format and add the range
4. Handle single numbers vs ranges differently in output format

Key Insight:
Since the array is sorted, we can detect consecutive sequences by checking if 
current_number == previous_number + 1. When this breaks, we've found the end of a range.

Time Complexity: O(n) - single pass through array
Space Complexity: O(1) - only using a few variables (excluding output space)

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
 

Constraints:

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.

*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        // Handle edge case: empty array
        if(nums.empty()) return result;

        // Track the start of the current range
        int start = nums[0];
        
        // Loop through array, using i <= nums.size() to handle the last range
        for(int i = 1; i <= nums.size(); ++i) {
            // Check if current range has ended:
            // 1. We've reached the end of array (i == nums.size()), OR
            // 2. Current number is not consecutive to previous (nums[i] != nums[i-1] + 1)
            if (i == nums.size() || nums[i] != nums[i-1] + 1) {
                
                // Format the range based on whether it's a single number or range
                if (start == nums[i-1]) {
                    // Single number: just add the number as string
                    result.push_back(to_string(start));
                } else {
                    // Range: format as "start->end"
                    result.push_back(to_string(start) + "->" + to_string(nums[i-1]));
                }
                
                // Start a new range from current position (if not at end)
                if(i < nums.size()) {
                    start = nums[i];
                }
            }
        }
        
        return result;
    }
};

/*
ALGORITHM WALKTHROUGH:

Example: nums = [0,1,2,4,5,7]

Initial: start = 0, result = []

i=1: nums[1]=1, nums[0]+1=1 → consecutive, continue
i=2: nums[2]=2, nums[1]+1=2 → consecutive, continue  
i=3: nums[3]=4, nums[2]+1=3 → NOT consecutive!
     → End range: start=0, end=nums[2]=2 → add "0->2"
     → New start=4, result = ["0->2"]

i=4: nums[4]=5, nums[3]+1=5 → consecutive, continue
i=5: nums[5]=7, nums[4]+1=6 → NOT consecutive!
     → End range: start=4, end=nums[4]=5 → add "4->5"  
     → New start=7, result = ["0->2", "4->5"]

i=6: i == nums.size() → end of array
     → End range: start=7, end=nums[5]=7 → single number → add "7"
     → result = ["0->2", "4->5", "7"]

KEY DESIGN DECISIONS:

1. Loop condition i <= nums.size():
   - Allows us to handle the last range when we reach the end
   - Avoids separate logic for processing the final range

2. Gap detection: nums[i] != nums[i-1] + 1
   - Works because array is sorted and has unique values
   - Detects when consecutive sequence breaks

3. Range formatting:
   - Single number: just the number as string
   - Multiple numbers: "start->end" format

4. Edge cases handled:
   - Empty array → return empty result
   - Single element → formatted as single number
   - All consecutive → one range covering everything
   - No consecutive pairs → each number as separate range

COMPLEXITY:
- Time: O(n) - single pass through array
- Space: O(1) auxiliary space (output space not counted)
*/