#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        vector<int> digits={};
        while(x/10 != 0){
            digits.push_back(x%10);
            x/=10;
        }
        digits.push_back(x%10); //last digit
        long long result = 0;
        for(int i = digits.size()-1; i>=0; i--){
            int x = 1;
            for(int j = 0; j < i; j++){
                x *= 10;
            }
            result += (long long)digits[(digits.size()-1)-i] * x;
        }
        if((result < -2147483648)||(result > 2147483647)){
            return 0;
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
    int n = -123;

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.reverse(n));


    return 0;
}

// leetcode
//by me
/*
class Solution {
public:
    int reverse(int x) {
        vector<int> digits={};
        while(x/10 != 0){
            digits.push_back(x%10);
            x/=10;
        }
        digits.push_back(x%10); //last digit
        long long result = 0;
        for(int i = digits.size()-1; i>=0; i--){
            int x = 1;
            for(int j = 0; j < i; j++){
                x *= 10;
            }
            result += (long long)digits[(digits.size()-1)-i] * x;
        }
        if((result < -2147483648)||(result > 2147483647)){
            return 0;
        }
        return result;
    }
};
*/

// by gpt
/*
class Solution {
public:
    int reverse(int x) {
        long long result = 0;

        while (x != 0) {
            int digit = x % 10;
            result = result * 10 + digit;
            x /= 10;

            // Optional early overflow check (prevents unnecessary work)
            if (result < INT_MIN || result > INT_MAX) {
                return 0;
            }
        }

        return (int)result;
    }
};
*/