#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        if(n %2 != 0){
            return 0; // n should be even
        }
        /*
        int result = 0;
        while(n != 0){
            result <<= 1;          // Shift result left to make room
            result |= (n & 1);  // using & gives me the last bit and using | adds it to the result
            n = n >> 1;
        }
        return result;
        */
        int result = 0;
        for(int i = 0; i < 32; ++i) {
            result <<= 1;          // Shift result left to make room
            result |= (n & 1);     // Add the last bit of n to result
            n >>= 1;               // Shift n right to process next bit
        }
        return result;
    }
};

class Print{
public:
    void printSingle(int value){
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
    int n = 43261596;

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.reverseBits(n));


    return 0;
}


// leetcode
// gpt solution
/*
class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        for(int i = 0; i < 32; ++i) {
            result <<= 1;          // Shift result left to make room
            result |= (n & 1);     // Add the last bit of n to result
            n >>= 1;               // Shift n right to process next bit
        }
        return result;
    }
};
*/