/*
 * Problem: Max Sum Subarray of size K.
 * Description: Given an array of integers arr[]  and a number k. 
    Return the maximum sum of a subarray of size k..
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/


class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        
        int n = arr.size();
        long long currsum = 0;
        
        for (int i = 0; i < k; i++){
            currsum += arr[i];
        }
        
        long long maxsum = currsum;
        
        for (int i = k; i < n; i++){
            currsum += arr[i] - arr[i-k];
            maxsum = max(currsum, maxsum);
        }
        
        return maxsum;
    }
};