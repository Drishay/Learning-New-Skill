#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        vector <string> subStrings = {""}; 

        string subString = "";
        for (int i = 0; i <s.length(); i++){
            if(s[i] == ' '){
                if (!subString.empty()){
                    subStrings.push_back(subString);
                    subString = "";
                }
                
            }
            else{
                subString += s[i];
            }
        }
        if (!subString.empty()) {
            subStrings.push_back(subString); // Add the last word
        }

        if (!subStrings.empty()) {
            return subStrings.back().length(); // Return length of the last word
        }

        return 0; // In case the string is empty or contains only spaces
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
    /* // Checking some logic
    // vector <string> S = {"12345", "67890"};
    // cout << S[0][1] << "\n"; // output is 2
    // cout << S[0].length() << "\n"; // output is 5
    */
    
    // Input string
    string s = "Today is a nice day";

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.lengthOfLastWord(s));


    return 0;
}



// leetcode 
// by me
/*
class Solution {
public:
    int lengthOfLastWord(string s) {
        vector <string> subStrings = {""}; 

        string subString = "";
        for (int i = 0; i <s.length(); i++){
            if(s[i] == ' '){
                if (!subString.empty()){
                    subStrings.push_back(subString);
                    subString = "";
                }
                
            }
            else{
                subString += s[i];
            }
        }
        if (!subString.empty()) {
            subStrings.push_back(subString); // Add the last word
        }

        if (!subStrings.empty()) {
            return subStrings.back().length(); // Return length of the last word
        }

        return 0; // In case the string is empty or contains only spaces
    }
};

*/

// chat gpt
/*
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the length of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

*/