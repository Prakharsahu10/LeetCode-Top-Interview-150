/*

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.


Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200

*/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Step 1: Copy elements of nums2 into the empty positions of nums1
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i]; // Overwrite the trailing zeroes in nums1
        }

        // Step 2: Sort the entire nums1 array
        sort(nums1.begin(), nums1.end());
    }
};

// Time Complexity: O((m + n) log(m + n)), where m is the number of elements in nums1 and n is the number of elements in nums2.
// This is because we are sorting the combined array of size m + n.
// Space Complexity: O(1), as we are modifying nums1 in place without using any additional data structures.
// Note: The sort function uses a comparison-based sorting algorithm, which typically has a time complexity of O(n log n).
// However, since we are sorting a small array (maximum size 200), this is efficient and acceptable for this problem.
// The solution is straightforward and leverages the built-in sort function to handle the merging and sorting of the two arrays efficiently.
