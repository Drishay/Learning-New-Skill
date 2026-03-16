#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char, int> freq;

        // Count frequency of chars in magazine
        for (char c : magazine) {
            freq[c]++;
        }

        // Check if ransomNote can be built
        for (char c : ransomNote) {
            if (freq[c] == 0) {
                return false; // not enough characters
            }
            freq[c]--; // use one character
        }

        return true;
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
    string ransomNote = "a", magazine = "b";

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.canConstruct(ransomNote, magazine));


    return 0;
}