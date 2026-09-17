class Solution {
public:
    string reverseVowels(string s) {
        vector<int> index;
        vector<char> vowel;
        for(int i = 0; i<s.size(); i++){
            char ch = tolower(s[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                index.push_back(i);
                vowel.push_back(s[i]);
            }
        }
        reverse(vowel.begin(), vowel.end());
        for(int i = 0; i<index.size(); i++){
            s[index[i]] = vowel[i];
        }
        return s;
    }
};

/*
class Solution {
public:
    string reverseVowels(string s) {

        int left = 0;
        int right = s.length() - 1;

        string vowels = "aeiouAEIOU";

        while (left < right) {

            // Move left until we find a vowel
            while (left < right && vowels.find(s[left]) == string::npos) {
                left++;
            }

            // Move right until we find a vowel
            while (left < right && vowels.find(s[right]) == string::npos) {
                right--;
            }

            // Swap vowels
            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};
*/