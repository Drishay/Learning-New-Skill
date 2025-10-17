#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Split s into words
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        // If size mismatch, return false
        if (pattern.size() != words.size()) return false;

        // Maps for both directions
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            // If already mapped, check consistency
            if (charToWord.count(c) && charToWord[c] != w) return false;
            if (wordToChar.count(w) && wordToChar[w] != c) return false;

            // Otherwise create mapping
            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
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
    string pattern = "abba", s = "dog cat cat dog";

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.wordPattern(pattern, s));


    return 0;
}