/*
 * Problem: Binary Search
 * Description: Searches the given array element in o(logn) time and return index if found and -1 if not found.
 * Time Complexity: O(logn)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int>&arr, int target){
    int n = arr.size();
    if (n < 1) return -1;
  
    int start = 0, end = n - 1;
    while (start <= end){
    int mid = (start+end)/2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main(){
    vector<int>arr = {1,3,4,5,6,7,8,12,14,15,16,19,21}; 
    int target;
    cout << "Enter the target : ";
    cin >> target;
    cout << "Index is : " << BinarySearch(arr, target);
    return 0;
}
