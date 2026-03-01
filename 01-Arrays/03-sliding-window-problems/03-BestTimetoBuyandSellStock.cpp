/*
 * Problem: Best Time to Buy and Sell Stock.
 * Description: You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
    You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.
    Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit would be 0.
 * Time Complexity: O(n), o(n2)
 * Space Complexity: O(1)
*/

//brute force solution o(n^2) time Complexity.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        for (int i = 0; i < prices.size() - 1; i++){
            for (int j = i + 1; j < prices.size(); j++){
                maxi = max(maxi, prices[j] - prices[i]);
            }
        }
        return maxi;
    }
};

//optimal solution O(n) time Complexity.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int n = prices.size();
        int maxp = 0;
        while (right < n){
            if (prices[left] < prices[right]){
                int cmax = prices[right] - prices[left];
                maxp = max(cmax, maxp);
            }
            else {
                left = right;
            }
            right++;
        }
        return maxp;
    }
};
