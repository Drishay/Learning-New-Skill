#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr1 [10] = {0,0,1,1,1,2,2,3,3,4};
    int arr2 [10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    
    int a2 = 0, count = 0;
    for(int i = 0; i < sizeof(arr1)/4; i++){
        for(int j = 0; j < sizeof(arr1)/4; j++){
            if(arr1[i] == arr2[j]){
                count ++;
            }
            
        }
        if (count == 0 ){
                cout << count << arr1[i] << "\n";
                arr2[a2] = arr1[i];
                a2++;
            }
        count = 0;
    }

    for(int i = 0; i < sizeof(arr1)/4; i++){
        cout<< arr2[i] << " ";
    }
    cout << "\n" << a2;

}

//leetcode
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
