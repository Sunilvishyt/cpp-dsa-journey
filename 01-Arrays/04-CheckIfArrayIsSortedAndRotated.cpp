/*
 * Problem: check if array is sorted and rotated.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>& nums) {
    int dip = 0;
    for (int i = 0; i < nums.size() - 1; i++){
        if (nums[i] > nums[i+1]){
            dip++;
        }
    }
    if (nums.back() > nums.front()){
        dip++;
    }
    if (dip > 1){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    vector<int>v = {1,2,3,4,5};
    bool ans = check(v);
    if (ans == true) cout<<"Array is sorted and rotated.";
    else cout<<"Array is not sorted.";
    return 0;
}
