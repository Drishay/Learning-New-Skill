#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int buyPrice(vector<int> prices){
        int buyPrice = prices[0], buyIndex = 0;
        for(int i =  1; i <prices.size(); i++){ //accessing array index, modified for this problem
            if(prices[i]<buyPrice){
                buyPrice = prices[i];
                buyIndex = i;
            }
        }
        // cout << "buy index " << buyIndex << "\n";
        return buyIndex;
    }

    int sellPrice(vector<int> prices, int buyIndex){
        int sellPrice = prices[buyIndex], sellIndex = buyIndex;
        for(int i =  buyIndex; i <prices.size(); i++){
            if(prices[i]>sellPrice){
                sellPrice = prices[i];
                sellIndex = i;
            }
        }
        // cout << "Sell index " << sellIndex << "\n";
        return sellIndex;
    }
    int maxProfit(vector<int>& prices) {
        int buyIndex = buyPrice(prices);
        int sellIndex = sellPrice(prices, buyIndex);
        // cout << prices[sellIndex] - prices[buyIndex] << "\n";
        return prices[sellIndex] - prices[buyIndex];
    }
};

class Print{
public:
    void printSingle(int value){
        cout << "\n" << value;
    }

    void printVector(vector <int> nums){
         for (int num : nums) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
};

int main() {
    // Input vector
    vector<int> prices = {7,6,4,3,1};

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    // printing the value or values
    print.printSingle(sol.maxProfit(prices));


    return 0;
}





// leetcode
// by me,
/*
This fails because you restricted selling to only after the lowest price, which may not be valid.
To solve this problem, you need to track the minimum price seen so far while iterating through the array, and compute max profit at each step.
*/

/*
class Solution {
public:
    int buyPrice(vector<int> prices){
        int buyPrice = prices[0], buyIndex = 0;
        for(int i =  1; i <prices.size(); i++){
            if(prices[i]<buyPrice){
                buyPrice = prices[i];
                buyIndex = i;
            }
        }
        return buyIndex;
    }

    int sellPrice(vector<int> prices, int buyIndex){
        int sellPrice = prices[buyIndex], sellIndex = buyIndex;
        for(int i =  buyIndex; i <prices.size(); i++){
            if(prices[i]>sellPrice){
                sellPrice = prices[i];
                sellIndex = i;
            }
        }
        return sellIndex;
    }
    int maxProfit(vector<int>& prices) {
        int buyIndex = buyPrice(prices);
        int sellIndex = sellPrice(prices, buyIndex);
        return prices[sellIndex] - prices[buyIndex];
    }
};
*/


// by chat gpt- Yes — it's a form of Dynamic Programming, though it’s often referred to as a "greedy" approach with DP flavor
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i]; // update buying price
            } else {
                maxProfit = max(maxProfit, prices[i] - minPrice); // potential profit
            }
        }
        return maxProfit;
    }
};

*/