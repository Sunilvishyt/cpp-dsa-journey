/*
 * Problem: remove dublicates from sorted array.
 * Description: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
 * Time Complexity: O(n^2), O(n)    -> because of multiple solutions are there.
 * Time Complexity: O(1)  
 */


//brute force solution. O(n^2) time complexity and O(1) space complexity.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return 1;
        int i = 0;
        while ( i < nums.size()-1)
            if (nums[i] == nums[i+1]){
                for (int j = i+1; j < nums.size() -1 ; j++){
                    nums[j] = nums[j+1];
                }
                nums.pop_back();
            } else {
                i++;
            }

        return nums.size() ;
    }
};


//optimal solution O(n) time complexity and O(1) space complexity
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = i+1; j < nums.size(); j++){
            if (nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};

