#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkSingle(vector<int> &nums, int singlenum, int index){
        for(int j = 0; j < nums.size(); j++){
                if(nums[j] == singlenum && index != j){
                    return false;
                }
        }
        return true;
    }
    int singleNumber(vector<int>& nums) {
        int singlenum = 0;
        for (int i = 0; i < nums.size(); i++){
            singlenum = nums[i];
            if (checkSingle(nums, singlenum, i)){
                return singlenum;
            }
            else{
                continue;
            }
        }
        return -1; //if no single value.
        
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
    // Input vector
    vector<int> nums = {0,0,2,2,3,4,1,4,3}; //every number appears exactly two times, except one

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.singleNumber(nums));


    return 0;
}



// leetcode submission
/* by me, mycurrent solution is O(n²) because for each element, you're scanning the entire array to check if 
it appears elsewhere. For large arrays, this results in poor performance.
*/

/*
class Solution {
public:
    bool checkSingle(vector<int> &nums, int singlenum, int index){
        for(int j = 0; j < nums.size(); j++){
                if(nums[j] == singlenum && index != j){
                    return false;
                }
        }
        return true;
    }
    int singleNumber(vector<int>& nums) {
        int singlenum = 0;
        for (int i = 0; i < nums.size(); i++){
            singlenum = nums[i];
            if (checkSingle(nums, singlenum, i)){
                return singlenum;
            }
            else{
                continue;
            }
        }
        return -1; //if no single value.
        
    }
};
*/

// Chat-gpt, sumitted by chat gpt
// O(n) time complexity and O(1) space complexity using bitwise XOR

/* 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) { //This is a range-based for loop, equivalent to: for (int i = 0; i < nums.size(); i++){result ^= nums[i];}
            result ^= num;  // XOR cancels out duplicates 
            // XOR logic, Only works if every number appears exactly two times, except one, for more frequency use hashmaps(it is slower compare to xor, but works for any frequency)
        }
        return result;
    }
};

*/