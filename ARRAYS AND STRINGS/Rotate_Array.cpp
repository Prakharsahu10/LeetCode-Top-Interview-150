/*

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 10^5

*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle case where k > n
        
        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};

// Time Complexity: O(n), where n is the number of elements in the array. Each reverse operation takes O(n).
// Space Complexity: O(1), as we are reversing the array in place without using any additional data structures.

// Brute Force Approach
class SolutionBruteForce {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle case where k > n
        
        // Perform k rotations one by one
        for (int i = 0; i < k; i++) {
            // Save the last element
            int temp = nums[n - 1];
            
            // Shift all elements one position to the right
            for (int j = n - 1; j > 0; j--) {
                nums[j] = nums[j - 1];
            }
            
            // Put the last element at the beginning
            nums[0] = temp;
        }
    }
};
// Time Complexity: O(n × k), where n is the number of elements and k is the number of rotations
// Space Complexity: O(1), using only a single temporary variable
