/*
3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Algorithm Intuition:
1. Sort the array to facilitate the two-pointer approach and handle duplicates
2. Iterate through the array, fixing one element at a time
3. For each fixed element, use two pointers to find pairs that sum to its negative
4. Skip duplicates to ensure unique triplets:
   - Skip duplicates of the first element
   - Skip duplicates of the second element after finding a valid triplet

Time Complexity: O(n²), where n is the length of the array
- Sorting takes O(n log n)
- The nested loop (one pointer + two pointers) takes O(n²)

Space Complexity: O(1) excluding the output array
- Only a constant amount of extra space is used

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Result vector to store all unique triplets that sum to zero
        vector<vector<int>> res;
        
        // Sort the array - crucial for the two-pointer approach and eliminating duplicates
        sort(nums.begin(), nums.end());
        
        // Fix the first element and find pairs that sum to its negative
        for(int i = 0; i < nums.size(); i++) {
            // Skip duplicates for the first element to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;  // Skip this iteration, move to next unique value
            }
            
            // Use two pointers to find pairs that, with nums[i], sum to zero
            int j = i + 1;            // Left pointer (starts after i)
            int k = nums.size() - 1;  // Right pointer (starts from end)

            while(j < k) {
                // Calculate the current sum of the three elements
                int total = nums[i]+nums[j]+nums[k];

                if(total > 0) {
                    // If sum is too large, decrease the right pointer to get a smaller sum
                    k--;
                } else if (total < 0) {
                    // If sum is too small, increase the left pointer to get a larger sum
                    j++;
                } else {
                    // Found a triplet that sums to zero, add to result
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;  // Move left pointer to look for more potential triplets

                    // Skip duplicates for the second element to avoid duplicate triplets
                    // This is necessary because we've already included this value in a triplet
                    while (nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                }
            }
        }
        return res;  // Return all unique triplets
    }
};

// Time Complexity: O(n²), where n is the length of the input array.
// - Sorting takes O(n log n)
// - The nested loop (one pointer + two pointers) takes O(n²)