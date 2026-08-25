class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int check = k;
        for(int i = 1; i<=nums.size()+1; i++){
            check = k * i;

            bool found = false;
            for(int i = 0; i<nums.size(); i++){
                if(nums[i] == check){
                    found = true;
                    break;
                }
            }
            if(found == false) break;
            
        }
        return check;
    }
};


class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> freq(101,0);

        for(int i=0;i<nums.size();i++)
        freq[nums[i]] = 1;

        int i = k;
        while(i <= 100) {
            if(!freq[i])
            return i;
            i += k;
        }
        return ((100 / k) + 1) * k;
    }
};