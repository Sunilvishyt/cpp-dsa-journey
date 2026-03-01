
/*
 * Problem: two sum.
 * Description: return the indexes or elements of the array elements which becomes target number when added.
 * Time Complexity: O(n), O(nlogn)    -> because of multiple solutions.
 */
 
#include <iostream>
#include <vector>
using namespace std;

//Brute Force approach with n^2 time complexity. and return indexes
vector<int> twosum_n_square(vector<int>&nums, int target, int n){
    for (int i = 0; i<n-1; i++){
        for (int j = i+1; j<n; j++){
            if (nums[i] + nums[j] == target) return {i,j};
        }
    }
    return {};
}

//optimal approach with Nlogn time complexity
//pass by value here because it will modify the array because of sorting.
//it will return the array elements not indecies.
vector<int> twosum_nlogn(vector<int>nums, int target, int n){
    sort(nums.begin(), nums.end());
    int start = 0, end = n - 1;
    while (start >= 0 and end < n ){
        if (nums[start] + nums[end] == target){
            return {nums[start],nums[end]};
        }
        else if (nums[start] + nums[end] < target){
            start += 1;
        }
        else end -=1;
    }
    return {};
}

//two pointer with binary search approach
//returns array elements not indexes.
vector<int> two_sum_binary_search(vector<int>arr, int target, int n){
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n-1; i++) {
        int ctarget = target - arr[i];
        int start = i+1;
        int end = n-1;
        while(start <= end){
            int mid = (start + end)/2;
            if (arr[mid] == ctarget) return {arr[i], arr[mid]};
            else if (arr[mid] < ctarget) start = mid + 1;
            else end = mid -1;
        }
    }
    return {};
}
using namespace std;
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
    for (int val : nlogn_nums) cout<<val << " ";
    cout<<endl << endl;
    
    cout<<"with binary search " << endl;
    vector<int>binary_search_twosum_nums = two_sum_binary_search(nums, target, n);
    for (int val : binary_search_twosum_nums) cout<<val<< " ";
    
    return 0;
}
