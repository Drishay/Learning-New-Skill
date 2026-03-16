#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr1 [10] = {0,0,1,1,1,2,2,3,3,4};
    int arr2 [10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int value = 3;
    int k = 0;
    for(int i = 0; i < sizeof(arr1)/4; i++){
        if(arr1[i] == value){
            arr1[i] = -1;
        }
    }
    for(int i = 0; i < sizeof(arr1)/4; i++){
        if(arr1[i] == -1){
            continue;
        }
        else{
            arr2[k] = arr1[i];
            k++;
        }
    }


    for(int i = 0; i < sizeof(arr1)/4; i++){
        cout<< arr2[i] << " ";
    }
    cout << "\n" << k;

}

//leetcode

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // Position to overwrite

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
