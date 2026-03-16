#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //first sol, concatenate the arrays, then use a sorting algo let say quick sort.
public:
    void insertionSort(vector<int>& arr) {
        for(int i = 1; i < arr.size(); i++) {
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for(int i = m; i < m+n; i++){
            nums1[i] = nums2[j];
            j++;
        }
        insertionSort(nums1);

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
    vector<int> num1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> num2 = {2,5,6};
    int n = 3;

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    sol.merge(num1, m, num2, n);

    // printing the value or values
    print.printVector(num1);


    return 0;
}


// leetcode
//by me
/*
class Solution {
public:
    void insertionSort(vector<int>& arr) {
        for(int i = 1; i < arr.size(); i++) {
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for(int i = m; i < m+n; i++){
            nums1[i] = nums2[j];
            j++;
        }
        insertionSort(nums1);

    }
};
*/