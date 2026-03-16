#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to move Left → Right
    void leftToRight(vector<vector<int>>& matrix, int top, int left, int right, vector<int>& result) {
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
    }

    // Function to move Top → Bottom
    void topToBottom(vector<vector<int>>& matrix, int right, int top, int bottom, vector<int>& result) {
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
    }

    // Function to move Right → Left
    void rightToLeft(vector<vector<int>>& matrix, int bottom, int right, int left, vector<int>& result) {
        for (int i = right; i >= left; i--) {
            result.push_back(matrix[bottom][i]);
        }
    }

    // Function to move Bottom → Top
    void bottomToTop(vector<vector<int>>& matrix, int left, int bottom, int top, vector<int>& result) {
        for (int i = bottom; i >= top; i--) {
            result.push_back(matrix[i][left]);
        }
    }

    // Main spiralOrder function
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        if (matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // 1️⃣ Move Left → Right
            leftToRight(matrix, top, left, right, result);
            top++;  // shrink top boundary

            // 2️⃣ Move Top → Bottom
            topToBottom(matrix, right, top, bottom, result);
            right--; // shrink right boundary

            // 3️⃣ Move Right → Left
            if (top <= bottom) {
                rightToLeft(matrix, bottom, right, left, result);
                bottom--; // shrink bottom boundary
            }

            // 4️⃣ Move Bottom → Top
            if (left <= right) {
                bottomToTop(matrix, left, bottom, top, result);
                left++; // shrink left boundary
            }
        }

        return result;
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
    vector<vector<int>> matrix = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printVector(sol.spiralOrder(matrix));


    return 0;
}

/* optimized version without helper functions
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        if (matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // 1️⃣ Move Left → Right
            for (int i = left; i <= right; i++)
                result.push_back(matrix[top][i]);
            top++;

            // 2️⃣ Move Top → Bottom
            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;

            // 3️⃣ Move Right → Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    result.push_back(matrix[bottom][i]);
                bottom--;
            }

            // 4️⃣ Move Bottom → Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }

        return result;
    }
};


*/