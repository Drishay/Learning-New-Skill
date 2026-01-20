class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int size = nums.size();
        unordered_map<int, int> elements;
        for (int i = 0; i < size; i++)
        {
            elements[nums[i]]++;
            if (elements[nums[i]] > size / 2)
            {
                return nums[i];
            }
        }
        return 0;
    }
};

/*
LeetCode Style Explanation:

To solve the "Majority Element" problem optimally, we use the Boyer–Moore Voting Algorithm. Here's the intuition:

We maintain a candidate and a count. As we iterate through the array, we increase the count if the current element is the same as our candidate, 
and decrease the count if it's different. If the count drops to zero, we pick the next element as the new candidate. By the end of the array, the 
candidate will be the majority element because it effectively cancels out all the minority elements.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            if (num == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};

*/