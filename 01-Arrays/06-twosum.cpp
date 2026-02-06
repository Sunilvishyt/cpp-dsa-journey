
/*
 * Problem: two sum.
 * Description: return the indexes of the array elements which becomes target number when added.
 * Time Complexity: O(n), O(logn)    -> because of multiple solutions.
 */
 
#include <iostream>
#include <vector>
using namespace std;

//this function returns the indexes with n^2 time complexity
vector<int> twosum_n_square(vector<int>&nums, int target, int n){
    for (int i = 0; i<n-1; i++){
        for (int j = i+1; j<n; j++){
            if (nums[i] + nums[j] == target) return {i,j};
        }
    }
    return {};
}

//this function returns the indexes with n^2 time complexity
//pass by value here because it will modify the array because of sorting.
vector<int> twosum_nlogn(vector<int>nums, int target, int n){
    sort(nums.begin(), nums.end());
    int start = 0, end = n - 1;
    while (start >= 0 and end < n ){
        if (nums[start] + nums[end] == target){
            return {start,end};
        }
        else if (nums[start] + nums[end] < target){
            start += 1;
        }
        else end -=1;
    }
    return {};
}

int main() {
    vector<int>nums = {2,7,9,14};
    int target = 23;
    int n = nums.size();
    
    cout<<"with n^2 time complexity algo"<<endl;
    vector<int>n_square_nums = twosum_n_square(nums,target,n);
    for (int val : n_square_nums) cout <<val<< " ";
    cout<<endl <<endl;
    
    cout<<"with nlogn time complexity algo"<<endl;
    vector<int>nlogn_nums = twosum_nlogn(nums, target, n);
    for (int val: nlogn_nums) cout<<val << " ";
    return 0;
}
