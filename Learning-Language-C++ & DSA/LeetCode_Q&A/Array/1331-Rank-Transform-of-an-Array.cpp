//my solutioin, to add the elements in the sorteed map, then giving them ranks and then replacing the elments in the arr with the ranks

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;

        // Insert all elements as keys
        for (int x : arr) {
            mp[x];
        }

        // Assign ranks
        int rank = 1;
        for (auto &it : mp) {
            it.second = rank++;
        }

        for (int &x : arr) {
            x = mp[x];
        }
        return arr;
    }
};


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> temp = arr;

        sort(temp.begin(), temp.end());

        unordered_map<int,int> rank;

        int r = 1;

        for(int x : temp)
        {
            if(rank.find(x) == rank.end())
                rank[x] = r++;
        }

        for(int &x : arr)
            x = rank[x];

        return arr;
    }
};