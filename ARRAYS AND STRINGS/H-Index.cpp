/*

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

 

Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
Example 2:

Input: citations = [1,3,1]
Output: 1

Constraints:

n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Step 1: Sort the citations in descending order
        sort(citations.rbegin(), citations.rend());
        
        int h = 0;
        // Step 2: Traverse the sorted array
        for (int i = 0; i < citations.size(); i++) {
            // If the current paper has at least (i+1) citations
            if (citations[i] >= i + 1) {
                h = i + 1; // Update h-index
            } else {
                break; // As soon as this is not true, stop
            }
        }
        return h;
    }
};

// Time Complexity: O(n log n), where n is the number of papers. This is due to the sorting step.
// Space Complexity: O(1), as we are using a constant amount of space for the h-index variable and the input array is modified in place.