/*
 * Problem: Trapping rain water.
 * Description: return the unit of water can be stored between array heights.
 * Time Complexity: O(n^2), O(n)    -> because of multiple solutions are there.
 * Time Complexity: O(n), O(1)    -> because of multiple solutions are there.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//O(n) time complexity and O(n) space complexity
int optimized(vector<int>&nums, int n){
    vector<int>leftmax(n);
    vector<int>rightmax(n);
    int ans = 0;

    //fill leftmax array
    int currrent_lmax = 0;
    for (int i = 0; i < n; i++){
        leftmax[i] = currrent_lmax;
        currrent_lmax = max(currrent_lmax, nums[i]);
    }
    
    //fill right array
    int current_rmax = 0;
    for (int i = n-1; i >= 0; i--){
        rightmax[i] = current_rmax;
        current_rmax = max(nums[i], current_rmax);
    }
    
    for (int i = 0; i<n; i++){
        int mini = min(leftmax[i], rightmax[i]);
        int temp = mini - nums[i];
        if (temp > 0) ans += temp;
    }
    
    return ans;
}


//n^2 time complexity and O(1) space complexity 
int brute_force(vector<int>&nums, int n){
    int temp;
    int ans = 0;
    
    for (int i = 0; i < n; i++){
        int leftmax = 0;  
        int rightmax = 0;  
        for (int j = i-1; j>=0; j--){
            leftmax = max(leftmax, nums[j]);
        }
        
        for (int k = i+1; k<n; k++){
            rightmax = max(rightmax, nums[k]);
        }
        
        int mini = min(leftmax, rightmax);
        temp = mini - nums[i];
        if (temp > 0) ans += temp;
    }
    return ans;
}

//O(n) time complexity and O(1) space complexity
int optimal(vector<int>&nums, int n){
    int right_max = 0;
    int leftmax = 0;
    int ans = 0;
    for (int i = 1; i < n; i++) if (nums[i] > nums[right_max]) right_max = i;
    
    for (int i = 0; i < right_max; i++){
        int temp = leftmax - nums[i];
        if (temp > 0) ans+=temp;
        leftmax = max(leftmax, nums[i]);
    }
    
    leftmax = right_max;
    right_max = 0;
    for (int i = n-1; i>leftmax; i--){
        int temp = right_max - nums[i];
        if (temp > 0) ans+=temp;
        right_max = max(right_max, nums[i]);
    }
    return ans;
}

int main()
{
    vector<int>nums = {4,2,0,5,2,6,2,3};
    int n = nums.size();
    cout<<"by brute force : "<<brute_force(nums, n)<<endl;
    cout<<"by optimized : "<<optimized(nums, n) <<endl;
    cout<<"by optimal : "<<optimal(nums, n);
    return 0;
}

//learning - use idx suffix in the variables which are storing the index, so to differentiate between the variables which are storing the index and number from the array.
