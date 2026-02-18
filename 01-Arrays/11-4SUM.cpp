/*
 * Problem: 4Sum.
 * Description: Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] 
   such that:
      0 <= a, b, c, d < n
      a, b, c, and d are distinct.
      nums[a] + nums[b] + nums[c] + nums[d] == target.
 * Time Complexity: O(n^2), O(nlogn) O(n+m)    -> because of multiple solutions are there.
 * Space Complexity: O(1)  
 */

//brute for solution - O(n^4) time complexity and space completxity O(N)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>s;
        int n = nums.size();
        for (int i = 0; i<n-3; i++ ){
            for (int j = i+1; j < n-2; j++){
                for (int k = j+1; k < n-1; k++){
                    for (int l = k+1; l < n; l++){
                        if ((long long)nums[i] + nums[j] + nums[k] + nums[l] == target)
                        {
                            vector<int>arr = {nums[i], nums[j], nums[k], nums[l]};
                            sort(arr.begin(), arr.end());
                            s.insert(arr);
                        }
                    }
                }
            }
        }
        vector<vector<int>>result_vector(s.begin(), s.end());
        return result_vector;

    }
};

//optimal solution - O(n^3) time complexity and space completxity O(N).
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>s;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i<n-3; i++ ){
            for (int j = i+1; j < n-2; j++){
                int start = j+1, end = n-1;
                while (start < end){
                    long long sum = (long long)nums[i] + nums[j] + nums[start] + nums[end];
                    if ( sum == target){
                        vector<int>arr = {nums[i], nums[j], nums[start], nums[end]};
                        sort(arr.begin(), arr.end());
                        s.insert(arr);
                        start++; end--;
                    }
                    else if (sum < target){
                        start++;
                    } 
                    else {
                        end--;
                    }
                }
            }
        }
        vector<vector<int>>result_vector(s.begin(), s.end());
        return result_vector;
    }
};


