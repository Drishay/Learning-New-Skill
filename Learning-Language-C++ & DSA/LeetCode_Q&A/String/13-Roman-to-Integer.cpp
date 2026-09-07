class Solution {
public:
    int getValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // Check if the current numeral is smaller than the next one
            if (i + 1 < n && getValue(s[i]) < getValue(s[i + 1])) {
                total -= getValue(s[i]); // Subtraction case (e.g., IV)
            } else {
                total += getValue(s[i]); // Addition case (e.g., VI)
            }
        }
        
        return total;
    }
};

/* max running time
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            // If smaller value comes before larger value, subtract it
            if (i + 1 < s.length() && value[s[i]] < value[s[i + 1]])
                ans -= value[s[i]];
            else
                ans += value[s[i]];
        }

        return ans;
    }
};
*/

/* least running time
class Solution {
public:
    int romanToInt(string s) {
       int ans=0;
       for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='M'){
                if(i>0&&s[i-1]=='C') {
                    ans+=900;
                    i--;
                }
                else ans+=1000;
            }
            else if(s[i]=='D'){
                if(i>0&&s[i-1]=='C') {
                    ans+=400;
                    i--;
                }
                else ans+=500;
            }
            else if(s[i]=='C'){
                if(i>0&&s[i-1]=='X') {
                    ans+=90;
                    i--;
                }
                else ans+=100;
            }
            else if(s[i]=='L'){
                if(i>0&&s[i-1]=='X') {
                    ans+=40;
                    i--;
                }
                else ans+=50;
            }
            else if(s[i]=='X'){
                if(i>0&&s[i-1]=='I') {
                    ans+=9;
                    i--;
                }
                else ans+=10;
            }
            else if(s[i]=='V'){
                if(i>0&&s[i-1]=='I') {
                    ans+=4;
                    i--;
                }
                else ans+=5;
            }
            else if(s[i]=='I'){
                ans+=1;
            }
       } 
       return ans;
    }
};
*/