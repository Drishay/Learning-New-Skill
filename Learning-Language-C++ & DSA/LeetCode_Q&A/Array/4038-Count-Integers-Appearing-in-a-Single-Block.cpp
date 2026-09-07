class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> blocks;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                blocks[nums[i]]++;
            }
        }

        int ans = 0;

        for (auto p : blocks) {
            if (p.second == 1) {
                ans++;
            }
        }

        return ans;
    }
};