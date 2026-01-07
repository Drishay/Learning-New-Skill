#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        int n = strs.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            vector<string> group;
            group.push_back(strs[i]);
            visited[i] = true;

            // Create frequency map for the current word
            unordered_map<char, int> freq1;
            for (char c : strs[i])
                freq1[c]++;

            for (int j = i + 1; j < n; j++)
            {
                if (visited[j])
                    continue;

                unordered_map<char, int> freq2;
                for (char c : strs[j])
                    freq2[c]++;

                // Compare the two frequency maps
                if (freq1 == freq2)
                {
                    group.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            result.push_back(group);
        }

        return result;
    }
};

class Print
{
public:
    void printSingle(bool value)
    {
        cout << "\n"
             << value;
    }

    void printVector(vector<int> nums)
    {
        for (int num : nums)
        {
            cout << num << " ";
        }
        cout << "\n";
    }

    void printVectorOfVectors(vector<vector<string>> groups)
    {
        for (auto &group : groups)
        {
            cout << "[";
            for (size_t i = 0; i < group.size(); ++i)
            {
                cout << "\"" << group[i] << "\"";
                if (i < group.size() - 1)
                    cout << ", ";
            }
            cout << "]" << endl;
        }
    }
};

int main()
{
    // Input
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printVectorOfVectors(sol.groupAnagrams(strs));

    return 0;
}

/* what i though while solving this problem
you are a mentor, i am solving leetcode 45 problem, i have a solution, like i will access the array
and i will create the hashmap and the elements with the same number of alphabets are there will be
add to a nested array printing all the arnagrams, for example by accessing the [0] element, we 
create a hashmap and then from[1] to size-1 will try to find the array and when the loop breaks,
clear the old hashmap and then create a new map with next element and if the next element was the 
anagram then shift to the next element.
*/

/* leetcode optimized version
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (auto& word : strs) {
            string key = word;
            sort(key.begin(), key.end());  // Sorting gives unique signature
            groups[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& entry : groups) {
            result.push_back(move(entry.second));
        }

        return result;
    }
};

*/