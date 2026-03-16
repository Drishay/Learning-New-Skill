#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map <int, int> freq;
        for (int x : nums){
            freq[x]++;
            if (freq[x] > 1){
                return true;
            }
        }
        return false;
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
    vector <int> nums = {1,2,3,1};

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.containsDuplicate(nums));


    return 0;
}




/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (seen.count(x)) { // already exists
                return true;
            }
            seen.insert(x);
        }
        return false;
    }
};

*/