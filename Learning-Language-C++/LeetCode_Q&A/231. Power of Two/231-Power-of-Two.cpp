#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false; // 0 and negative numbers aren't powers of two
        }

        int countSetBit = 0;
        while(n != 0){
            if((n & 1) == 1){  // Proper bitwise AND with correct precedence
                countSetBit++;
            }
            n = n >> 1;
        }

        return countSetBit == 1;
    }
};

class Print{
public:
    void printSingle(bool value){
        cout << "\n" << value;
    }

    void printVector(vector <int> nums){
         for (int num : nums) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
};

int main() {
    // Input
    int n = 5;

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.isPowerOfTwo(n));


    return 0;
}


// leetcode solution
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false; // 0 and negative numbers aren't powers of two
        }

        int countSetBit = 0;
        while(n != 0){
            if((n & 1) == 1){  // Proper bitwise AND with correct precedence
                countSetBit++;
            }
            n = n >> 1;
        }

        return countSetBit == 1;
    }
};

*/

// gpt
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
*/


