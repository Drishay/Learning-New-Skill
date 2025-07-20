#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int hammingWeight(int n) {
        if(n <= 0){
            return 0; // 0 and negative numbers have no 1 bit
        }

        int countSetBit = 0;
        while(n != 0){
            if((n & 1) == 1){  // Proper bitwise AND with correct precedence
                countSetBit++;
            }
            n = n >> 1;
        }

        return countSetBit;
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
    int n = 11;

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.hammingWeight(n));


    return 0;
}

// leetcode
// by me
/*
class Solution {
public:
    int hammingWeight(int n) {
        if(n <= 0){
            return 0; // 0 and negative numbers aren't considered for 1 bit
        }

        int countSetBit = 0;
        while(n != 0){
            if((n & 1) == 1){  // Proper bitwise AND with correct precedence
                countSetBit++;
            }
            n = n >> 1;
        }

        return countSetBit;
    }
};
*/

// gpt solution
/*
class Solution {
public:
    int hammingWeight(int n) {
        // Brian Kernighan’s Algorithm
        int count = 0;
        while (n != 0) {
            n = n & (n - 1); // drops the lowest set bit
            count++;
        }
        return count;
    }
};
*/