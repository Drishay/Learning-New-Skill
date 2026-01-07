#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    string convert(string s){
        string str1;
        for(char c : s){
            if(isalnum(c)){
                str1 += tolower(c);
            }
        }
        return str1;
    }

    bool isPalindrome(string s) {
        s = convert(s);
        int left = 0;
        int right = s.size()-1;
        while (left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
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
    // Input string
    string str1 = "A man, a plan, a canal: Panama";


    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.isPalindrome(str1));


    return 0;
}



//gpt- for memory efficient
/*

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // skip non-alphanumeric from left
            while (left < right && !isalnum(s[left])) left++;
            // skip non-alphanumeric from right
            while (left < right && !isalnum(s[right])) right--;

            // compare in lowercase
            if (tolower(s[left]) != tolower(s[right])) 
                return false;

            left++;
            right--;
        }
        return true;
    }
};

*/