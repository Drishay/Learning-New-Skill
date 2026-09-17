class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word3 = "";
        int w1 = 0, w2 = 0;
        bool alt = true;
        while((w1<word1.size()) && (w2<word2.size())){
            if(alt){
                word3 += word1[w1];
                w1++;
                alt = false;
            }
            else{
                word3 += word2[w2];
                w2++;
                alt = true;
            }
        }
        if(w1>=word1.size()){
            for(int i = w2; i<word2.size(); i++){
                word3 += word2[i];
            }
        }
        else{
            for(int i = w1; i<word1.size(); i++){
                word3 += word1[i];
            }
        }
        return word3;
    }
};

/* 0 ms
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int s1 = 0, s2 = 0;

        while(s1 < word1.length() && s2 < word2.length())
        {
            ans += word1[s1++];
            ans += word2[s2++];
        }

        while(s1 < word1.length())
        {
            ans = ans + word1[s1++];
        }

        while(s2 < word2.length())
        {
            ans = ans + word2[s2++];
        }

        return ans;
    }
};
*/