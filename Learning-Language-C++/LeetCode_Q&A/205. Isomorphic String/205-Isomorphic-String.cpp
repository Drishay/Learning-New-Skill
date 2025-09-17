#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;

        for (int i = 0; i < s.size(); i++) {
            char sc = s[i];
            char tc = t[i];

            // If mapping already exists, check consistency
            if (s2t.count(sc) && s2t[sc] != tc) return false;
            if (t2s.count(tc) && t2s[tc] != sc) return false;

            // Otherwise, establish mapping
            s2t[sc] = tc;
            t2s[tc] = sc;
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
    string s = "egg", t = "add";

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.isIsomorphic(s,t));


    return 0;
}