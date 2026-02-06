/*
 * Problem: maximum subarray sum.
 * Description: kedan's algorithm implemention to find out maximum subarray sum
    from given array works for positive and negative arrays.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    vector<int>arr = {4, -6, 2, 8};
    int n = arr.size();
    int maxi = INT_MIN;
    int prefix = 0 ;
    
    for (int j = 0; j < n; j++){
        prefix += arr[j];
        maxi = max(prefix, maxi);
        if (prefix < 0) prefix = 0;
    }

    cout << maxi;
    return 0;
}
