/*
Two Sum Problem

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Key Insight:
Instead of checking every pair (O(n²) brute force), we can use a HashMap to store previously seen numbers
and their indices. For each number, we check if its complement (target - current_number) exists in our map.

Algorithm:
1. Create a HashMap to store number → index mapping
2. For each number in the array:
   - Calculate its complement (target - current_number)
   - If complement exists in HashMap, we found our pair
   - Otherwise, store current number and its index in HashMap
3. Return the indices when pair is found

Time Complexity: O(n) - single pass through array
Space Complexity: O(n) - HashMap can store up to n elements

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // HashMap to store number → index mapping of previously seen elements
        unordered_map<int, int> pairIdx;

        // Iterate through the array with index
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];  // Current number
            
            // Calculate the complement: what number do we need to reach target?
            int complement = target - num;
            
            // Check if we've seen the complement before
            // find() returns an iterator: if found, iterator != end(); if not found, iterator == end()
            // So != end() means "complement WAS found in the map"
            if (pairIdx.find(complement) != pairIdx.end()) {
                // Found the pair! Return current index and complement's index
                // Note: complement's index comes from HashMap (earlier in array)
                return {i, pairIdx[complement]};
            }
            
            // Haven't found pair yet, store current number and its index
            // This number might be the complement for a future element
            pairIdx[num] = i;
        }
        
        // This should never be reached given problem constraints
        // (guaranteed exactly one solution exists)
        return {};
    }
};

/*
ALGORITHM WALKTHROUGH:

Example: nums = [2,7,11,15], target = 9

Step by step execution:
1. i=0, num=2, complement=9-2=7
   - Check if 7 exists in pairIdx: NO
   - Store: pairIdx[2] = 0
   - pairIdx = {2: 0}

2. i=1, num=7, complement=9-7=2  
   - Check if 2 exists in pairIdx: YES (at index 0)
   - Found pair! Return [1, 0]

Result: [1, 0] (indices of 7 and 2)

WHY THIS WORKS:
- We're looking for two numbers that sum to target: a + b = target
- Rearranging: b = target - a
- So for each number 'a', we check if 'b' (complement) was seen before
- HashMap gives us O(1) lookup time to check if complement exists

COMPARISON WITH BRUTE FORCE:
- Brute force: Check every pair → O(n²) time, O(1) space
- HashMap approach: Single pass → O(n) time, O(n) space
- Trade space for time - classic optimization technique

KEY POINTS:
- We store numbers as we see them, not all at once upfront
- This ensures we don't use the same element twice
- HashMap lookup is O(1) average case
- We return indices in order: current index, then stored index
// Time Complexity: O(n) - single pass through array
// Space Complexity: O(n) - HashMap can store up to n elements