class Solution {
public:
    bool isValid(string s) {
        stack <char> stac;
        for(int i= 0; i < s.length(); i++){
            if((s[i] == '(') || (s[i] == '[') || (s[i] == '{')){
                stac.push(s[i]);
            }
            else{
                if (stac.empty()) return false;
                char ele = stac.top();
                if( (s[i] == ')') && (ele == '(') ){
                    stac.pop();
                }
                else if( (s[i] == ']') && (ele == '[') ){
                    stac.pop();
                }
                else if( (s[i] == '}') && (ele == '{') ){
                    stac.pop();
                }
                else{
                    return false;
                }
            }
        }
        return stac.empty();
    }
};