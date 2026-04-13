//prints all the subsets from a given array (contigious and not contigious both).
//leetcode q 78.

class Solution {
public:
    void mrSubset(vector<int>&nums, vector<vector<int>>&ans, vector<int>temp, int index, int n){
        if (index >= n){
            ans.push_back(temp);
            return;
        }   

        mrSubset(nums, ans, temp, index+1, n);
        temp.push_back(nums[index]);
        mrSubset(nums, ans, temp, index+1, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        mrSubset(nums, ans, temp, 0, nums.size());
        return ans;
    }
};
