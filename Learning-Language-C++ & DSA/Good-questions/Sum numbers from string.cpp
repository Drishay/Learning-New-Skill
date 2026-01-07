/*Problem Statement:

You are given a string that contains both letters and numbers (which may include negative numbers).
Your task is to extract all the numbers — including multi-digit and negative ones — and find their total sum.

Example 1 :
Input:  "1agsgsg23"
Output: 24
Explanation: 1 + 23 = 24

Example 2 :
Input:  "ab-12cd3"
Output: -9
Explanation: -12 + 3 = -9

*/

/* Python 3 Code Implementation
import re

def sum_numbers_from_string(s):
    # Find all positive or negative numbers using regex
    numbers = re.findall(r'-?\d+', s)
    
    # Convert each to integer and sum them
    total = sum(map(int, numbers))
    
    return total

# Example usage
text1 = "1agsgsg23"
text2 = "ab-12cd3"

print("Sum of numbers (Example 1):", sum_numbers_from_string(text1))  # 24
print("Sum of numbers (Example 2):", sum_numbers_from_string(text2))  # -9

*/

// c++ solution
#include <iostream>
#include <string>
using namespace std;

int sumNumbersFromString(string s) {
    int sum = 0, num = 0;
    bool negative = false, inNumber = false;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch == '-') {
            // Check if it's a negative sign before a number
            if (i + 1 < s.size() && isdigit(s[i + 1])) {
                negative = true;
            }
        } 
        else if (isdigit(ch)) {
            inNumber = true;
            num = num * 10 + (ch - '0');
        } 
        else {
            if (inNumber) {
                sum += negative ? -num : num;
                num = 0;
                inNumber = false;
                negative = false;
            }
        }
    }

    // Add last number if string ends with it
    if (inNumber) {
        sum += negative ? -num : num;
    }

    return sum;
}

int main() {
    string text1 = "1agsgsg23";
    string text2 = "ab-12cd3";

    cout << "Sum of numbers (Example 1): " << sumNumbersFromString(text1) << endl;
    cout << "Sum of numbers (Example 2): " << sumNumbersFromString(text2) << endl;

    return 0;
}
