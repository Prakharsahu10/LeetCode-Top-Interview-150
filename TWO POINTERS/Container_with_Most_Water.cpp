/*
Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Algorithm Intuition:
- Use a two-pointer approach starting from the widest possible container
- The amount of water is limited by the shorter line and the distance between lines
- At each step, we try to maximize the area by moving the pointer at the shorter line
- This is optimal because:
  1. Moving the taller line would only decrease width without increasing height
  2. Moving the shorter line might give us a taller line that compensates for decreased width
- We continue this process until the pointers meet

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1

Constraints:
- n == height.length
- 2 <= n <= 105
- 0 <= height[i] <= 104

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Initialize the maximum area to 0
        int maxArea = 0;
        
        // Use two pointers approach - start with widest container
        int left = 0;                    // Left pointer starts at the leftmost line
        int right = height.size() - 1;   // Right pointer starts at the rightmost line

        // Continue until pointers meet
        while (left < right) {
            // Calculate current area:
            // Width = distance between lines (right - left)
            // Height = minimum height of the two lines (can't hold water higher than shortest side)
            // Area = width * height
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));

            // Move the pointer with smaller height:
            // Intuition: Moving the taller line would only decrease the width without increasing height
            // Moving the shorter line gives us a chance to find a taller line and possibly larger area
            if(height[left] < height[right]) {
                left++;    // Move left pointer if left height is smaller
            } else {
                right--;   // Move right pointer if right height is smaller or equal
            }
        }
        return maxArea;  // Return the maximum area found
    }
};

// Time Complexity: O(n), where n is the number of elements in the height array.
// - We process each element at most once
// - The two pointers converge in a single pass through the array

// Space Complexity: O(1), as we are using only a constant amount of extra space for pointers and variables.
// - We only use a fixed number of variables regardless of input size

// Proof of correctness:
// The two-pointer approach works because we always discard the pointer that cannot contribute to a larger area.
// When we move the pointer at the smaller height:
// - If we find a taller line, we might get a larger area despite the decreased width
// - If we don't find a taller line, we wouldn't have found a larger area by keeping that pointer anyway