/*

Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

 

Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII
Example 3:

Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV
 

Constraints:

1 <= num <= 3999

*/

class Solution {
public:
    string intToRoman(int num) {
        // Define a list of all possible Roman numeral values and their corresponding symbols
        // Ordered from largest to smallest to ensure greedy algorithm works correctly
        // Include both regular symbols (M, D, C, L, X, V, I) and special cases (CM, CD, XC, XL, IX, IV)
        const vector<pair<int, string>> valueSymbols{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};

        string res; // Result string to store the Roman numeral representation

        // Iterate through each symbol-value pair in descending order
        for (const auto& [value, symbol] : valueSymbols) {
            // If we've converted the entire number, exit early
            if (num == 0)
                break;

            // While the current value can be subtracted from num,
            // add the corresponding symbol to the result
            while (num >= value) {
                res += symbol;  // Append the symbol to our result
                num -= value;   // Subtract the value from num
            }
        }
        return res; // Return the final Roman numeral representation
    }
};

// Space Complexity: O(1), since we are using a fixed-size vector for the symbols and the result string grows with the input size.
// Time Complexity: O(1), as the number of symbols is constant and does not depend on the input size.
// Note: While the output string length could be up to O(log n) in the worst case, the algorithm itself
// has a constant upper bound since the constraints limit num to 3999, resulting in at most 15 symbols.