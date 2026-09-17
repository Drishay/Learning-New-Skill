class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        vector<bool> kids(candies.size(), false);
        for(int i = 0; i<candies.size(); i++){
            if(candies[i]>=max){
                max = candies[i];
            }
        }
        for(int i = 0; i<candies.size(); i++){
            if(candies[i] + extraCandies >=max){
                kids[i] = true;
            }
        }
        return kids;
    }
};