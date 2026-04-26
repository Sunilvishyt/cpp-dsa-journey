/*
Question : Smallest Stable Index I
  Leetcode question : 3903
Description : 
  You are given an integer array nums of length n and an integer k.
  
  For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).
  
  Return the smallest stable index. If no such index exists, return -1.
Time Complexity : O(n^2)
Space Complexity : O(1)
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int maxi = -1;
            int mini = INT_MAX;

            for (int j = 0; j<=i; j++){
                maxi = max(maxi, nums[j]);
            }

            for (int k = i; k<n; k++){
                mini = min(mini, nums[k]);
            }

            if (maxi - mini <= k){
                return i;
            }
        }
        return -1;
    }
};
