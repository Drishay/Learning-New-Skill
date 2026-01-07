#include <bits/stdc++.h>
using namespace std;

/*
// first approach, solved, but few bugs solved by gpt
int* moveZeroes(int* nums){    // void should be there, as we are changing at the memory location
    int size = sizeof(nums)/sizeof(int);
    
    for(int i = 0; i<size; i++){
        if(nums[i] == 0){
            int x = nums[i];
            for(int j = i; j < size; j++){
                nums[j] = nums[j+1];
            }
            nums[size-1] = x;
        }   // we should reduce size by 1, as no need to check the last element
    }

    return nums;
}

int main(){
    int nums[5] = {0,1,0,3,12};
    int size = sizeof(nums)/sizeof(int);
    
    moveZeroes(nums);

    for(int i = 0; i<size; i++){
        cout << nums[i] << " ";
    }
    
}
*/



void moveZeroes(int* nums, int size) {
    for(int i = 0; i < size; i++) {
        if(nums[i] == 0) {
            for(int j = i; j < size - 1; j++) {
                nums[j] = nums[j+1];
            }
            nums[size - 1] = 0;
            size--; // one less element to check (last element is now fixed)
            i--;    // check the current index again
        }
    }
}

// void moveZeroes(int* nums, int size) {
//     int lastNonZeroFoundAt = 0;

//     for (int i = 0; i < size; i++) {
//         if (nums[i] != 0) {
//             swap(nums[lastNonZeroFoundAt++], nums[i]);
//         }
//     }
// }

int main(){
    int nums[5] = {0,1,0,3,12};
    int size = sizeof(nums)/sizeof(int);

    moveZeroes(nums, size);

    for(int i = 0; i<size; i++){
        cout << nums[i] << " ";
    }
}


// leetcode


// first solution but timecomplexity is O(n^2), and worst wase could be all zeroes in front, therefore this is not righ as it could be reduced to O(n)
/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                for (int j = i; j < size - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                nums[size - 1] = 0;
                size--; // reduce size since last element is fixed
                i--;    // recheck this index as new element has moved here
            }
        }
    }
};

*/

// second approach, time complexity O(n), due to use of swap(), two pointer approach
/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZero = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[lastNonZero++], nums[i]);
            }
        }
    }
};

*/