/*
 * Problem: 3Sum.
 * Description: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that 
                i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
                the solution set must not contain duplicate triplets.
 * Time Complexity: O(nlogn) + n^2     -> because of multiple solutions are there.
 * Space Complexity: O(1)  
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //store the ans in the another array
        vector<vector<int>>arr;

        int n = nums.size();
        //sort the array for applying two pointer efficiently.
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++){
            int j = i + 1, k = n - 1;
            
            //dont run the while loop for duplicate nums[i] value
            if (i > 0 and nums[i] == nums[i-1]) continue;

            while ( j < k ){
                if (nums[i] + nums[j] + nums[k] == 0){
                    arr.push_back({nums[i],nums[j],nums[k]});  //store answer
                    j++; k--;

                    //if j and k values are duplicate too ignore them too.
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                }

                else if (nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
                
                else k--;
            }
        }
        return arr;
    }
};
