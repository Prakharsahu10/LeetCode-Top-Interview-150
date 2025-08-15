/*
Contains Duplicate II (Contains Nearby Duplicate)

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Key Insight:
We need to find duplicate values that are within k distance of each other. 
Use a HashMap to store the most recent index of each value we've seen.
When we encounter a value again, check if the distance from its last occurrence is ≤ k.

Algorithm:
1. Use HashMap to track: value → most recent index
2. For each element:
   - If we've seen this value before AND distance ≤ k, return true
   - Update the HashMap with current index for this value
3. If no nearby duplicates found, return false

Time Complexity: O(n) - single pass through array
Space Complexity: O(min(n, k)) - HashMap stores at most n unique values

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // HashMap to store value → most recent index mapping
        unordered_map<int, int> seen;

        // Iterate through array with index
        for(int i = 0; i < nums.size(); i++) {
            int val = nums[i];  // Current value
            
            // Check if we've seen this value before
            // find() != end() means the value exists in HashMap
            if (seen.find(val) != seen.end() && i - seen[val] <= k) {
                // Found duplicate within distance k
                // i = current index, seen[val] = previous index of same value
                // Distance = i - seen[val] (since i > seen[val])
                return true;
            }
            
            // Update HashMap with current index for this value
            // This overwrites any previous index, keeping only the most recent
            seen[val] = i;
        }
        
        // No nearby duplicates found
        return false;
    }
};

/*
ALGORITHM WALKTHROUGH:

Example 1: nums = [1,2,3,1], k = 3

Step by step execution:
1. i=0, val=1
   - seen.find(1) == seen.end() (not found)
   - seen[1] = 0
   - seen = {1: 0}

2. i=1, val=2  
   - seen.find(2) == seen.end() (not found)
   - seen[2] = 1
   - seen = {1: 0, 2: 1}

3. i=2, val=3
   - seen.find(3) == seen.end() (not found)  
   - seen[3] = 2
   - seen = {1: 0, 2: 1, 3: 2}

4. i=3, val=1
   - seen.find(1) != seen.end() (found at index 0)
   - Distance check: i - seen[1] = 3 - 0 = 3 <= k=3 ✓
   - Return true

Example 3: nums = [1,2,3,1,2,3], k = 2

Key insight: When we see 1 again at index 3, distance = 3-0 = 3 > k=2, so continue.
When we see 2 again at index 4, distance = 4-1 = 3 > k=2, so continue.
No duplicates within distance k=2, so return false.

WHY WE UPDATE THE INDEX:
- We always store the most recent index for each value
- This ensures we check the shortest possible distance for future duplicates
- If current duplicate is too far, a future one might be close enough

OPTIMIZATION NOTE:
- We could use a sliding window approach with a set for better space complexity in some cases
- Current approach is simpler and works well for most inputs
*/

//Time Complexity: O(n) - single pass through array
//Space Complexity: O(min(n, k)) - HashMap stores at most n unique values