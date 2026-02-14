/*
 * Problem: merge sorted arrays.
 * Description: given to sorted array nums1 and nums2, we have to merge element of nums2 into nums1 so it should remain sorted.
               also m is given which is number of valid elements in nums1 and n is given which is number of elements in nums2.
 * Time Complexity: O(n^2), O(n)    -> because of multiple solutions are there.
 * Time Complexity: O(1)  
 */


//Brute force solution O(n^2) time complexity
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for (int i = 0; i < n; i++){
            bool changed = false;
            for (int j = m-1; j >=0; j--){
                if (nums1[j] > nums2[i]){
                    nums1[j+1] = nums1[j];
                } else {
                    nums1[j+1] = nums2[i];
                    changed = true;
                    break;
                }
            }
            if (changed == false) nums1[0] = nums2[i];
            m++;
        }
    }
};

//optimized solution O(Nlogn) time complexity-
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++){
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

