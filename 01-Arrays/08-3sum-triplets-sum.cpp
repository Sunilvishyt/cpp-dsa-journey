/*
 * Problem: 3sum (triplet sum)
 * Description: return true if three distinct numbers in the array are there and their sum becomes target otherwise return false.
 * Time Complexity: O(n^2), O(n^3)    -> because of multiple solutions are there.
 * Time Complexity: O(1), O(1)    -> because of multiple solutions are there.
 */

// bruteforce n^3 time complexity
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        for (int i = 0; i<n-2; i++){
            for (int j = i+1; j<n-1; j++){
                for (int k = j+1; k<n; k++){
                    if (arr[i] + arr[j] + arr[k] == target) return true;
                }
            }
        }
        return false;
    }
};


//optimized O(n^2) time complexity.
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        
        //bubble sort algo.
        for (int i = n-1; i >= 0; i--)
            for (int j = 0; j < i; j++)
                if (arr[j]>arr[j+1])
                    swap(arr[j], arr[j+1]);
        
        //now solving
        for (int i = 0; i<n-2; i++){
            int ans = target - arr[i];
            int start = i+1;
            int end = n-1;
            while (start<end){
                if (arr[start] + arr[end] == ans) return true;
                else if (arr[start] + arr[end] > ans) end--;
                else start++;
            }
        }
        return false;
    }
};
