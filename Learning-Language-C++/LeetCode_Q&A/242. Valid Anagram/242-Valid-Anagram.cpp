#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_freq;
        unordered_map<char, int> t_freq;

        // count frequencies
        for (char c : s) {
            if (c != ' ') { // skip spaces
                s_freq[c]++; // increases count for char c
            }
        }
        for (char c : t) {
            if (c != ' ') { // skip spaces
                t_freq[c]++; // increases count for char c
            }
        }
        return s_freq==t_freq;
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
    string s = "anagram";
    string t = "nagaram";

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.isAnagram(s,t));


    return 0;
}





/*
// optimised version of this by chat gpt using only one map

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false; // lengths must match

        unordered_map<char, int> freq;

        // count characters from s
        for (char c : s) {
            freq[c]++;
        }

        // reduce count for characters from t
        for (char c : t) {
            freq[c]--;
            if (freq[c] < 0) {
                return false; // more occurrences in t than in s
            }
        }

        // if all counts are zero, it's an anagram
        return true;
    }
};

*/

/*
// optimised version of this by chat gpt using array, lookup in array is faster than map.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false; // lengths must match

        int freq[26] = {0}; // fixed-size array for 26 letters

        // increment for s, decrement for t
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        // check if all counts are zero
        for (int count : freq) {
            if (count != 0) return false;
        }

        return true;
    }
};

*/


/*
// optimised version of this by chat gpt using array, covering all the ASCII unique code

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int freq[256] = {0}; // support full ASCII

        for (int i = 0; i < s.size(); i++) {
            unsigned char cs = s[i]; // ensure positive index
            unsigned char ct = t[i];
            freq[cs]++;
            freq[ct]--;
        }

        for (int count : freq) {
            if (count != 0) return false;
        }

        return true;
    }
};
*/



/*
// optimised for ignoring the spaces and punctuations

#include <cctype> // for isalpha, tolower
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0}; // only letters a–z

        for (char c : s) {
            if (isalpha(c)) {                // ignore spaces, digits, symbols
                freq[tolower(c) - 'a']++;    // normalize to lowercase
            }
        }

        for (char c : t) {
            if (isalpha(c)) {
                freq[tolower(c) - 'a']--;    // decrement
            }
        }

        for (int count : freq) {
            if (count != 0) return false;    // mismatch
        }

        return true;
    }
};

*/