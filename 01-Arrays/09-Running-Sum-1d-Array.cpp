/*
Question : 1480. Running Sum of 1d Array
  Leetcode question : 3903
Description : 
  Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
  Return the running sum of nums.
Time Complexity : O(n^2)
Space Complexity : O(1)
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;

        for (int i = 0; i < nums.size(); i++){
            int sum = 0;
            for (int j = 0; j <= i; j++){
                sum += nums[j];
            }
            ans.push_back(sum);
            sum = 0;
        }

        return ans;
    }
};
