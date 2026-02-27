/*
 * Problem: Sort Colors
 * Description : You are given an array nums consisting of n elements where each element is an integer representing a color:
      0 represents red
      1 represents white
      2 represents blue
      Your task is to sort the array in-place such that elements of the same color are grouped together and arranged in the order: red (0), white (1), and then blue (2).
      You must not use any built-in sorting functions to solve this problem.
      
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high){
            if (nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low ++;
                mid ++;
            }
            else if (nums[mid] == 1){
                mid ++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
