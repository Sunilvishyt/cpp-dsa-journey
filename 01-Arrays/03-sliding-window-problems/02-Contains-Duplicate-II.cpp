/*
 * Problem: Contains Duplicate II.
 * Description: You are given an integer array nums and an integer k, 
     return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k,
     otherwise return false.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int left = 0, right = 0;
        int n = nums.size();
        while (right < n){
            if (right - left > k){
                window.erase(nums[left]);
                left++;
            }

            if (window.count(nums[right])) return true;
            window.insert(nums[right]);
            right++;
        }
        return false;
    }
};
