/*

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,1);

        // Left Product pass
        int leftProduct = 1;
        for (int i = 0; i<n; i++) {
            answer[i] = leftProduct;
            leftProduct *= nums[i];
        }

        //Right Product pass
        int RightProduct = 1;
        for(int i = n - 1; i >= 0; i--){
            answer[i] *= RightProduct;
            RightProduct *= nums[i];
        }
        return answer;
    }
};

// time complexity: O(n), where n is the number of elements in the input array nums.
// Space complexity: O(1) if we consider the output array as not using extra space, otherwise O(n) for the output array.    